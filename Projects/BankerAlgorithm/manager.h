#pragma once
#include "data.h"
#include "process.h"
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//释放一个进程的所有资源
int release_process(Process *_process) {
	
	Work *_work = _process->work;
	Max *_max = _process->max;
	Allocation *_allocation = _process->allocation;
	Need *_need = _process->need;
	
	Work *_old_work = NULL;
	Max *_old_max = NULL;
	Allocation *_old_allocation = NULL;
	Need *_old_need = NULL;
	while(_work!=NULL) {
		_old_work = _work;
		_old_max = _max;
		_old_allocation = _allocation;
		_old_need = _need;
		
		_work = _work->next;
		_max = _max->next;
		_allocation = _allocation->next;
		_need = _need->next;
		
		free(_old_work);
		free(_old_max);
		free(_old_allocation);
		free(_old_need);
	}
	
	free(_process);
}

//将一个资源链表的内容加到另一个资源链表
int add_resource(struct RESOURCE *dest, struct RESOURCE *raw) {
	while(raw!=NULL) {
		dest->num += raw->num;
		raw = raw->next;
		dest = dest->next;
	}
}

//获取一个资源链表
struct RESOURCE * get_object(char _kind) {
	struct RESOURCE *resource = malloc(sizeof(struct RESOURCE));//初始化头指针
	struct RESOURCE *new_resource = resource;
	resource->kind = _kind++;
	resource->num = 0;
	int _i = 1;
	while( _i < KIND_NUM ) {
		resource->next = malloc(sizeof(struct RESOURCE));
		resource->next->kind = _kind++;
		resource->next->num = 0;
		resource = resource->next;
		_i++;
	}
	resource->next = NULL;
	
	return new_resource;
}

//获取一个进程实例
Process* get_process(int _id) {
	Process *_process = malloc(sizeof(Process));
	_process->id = _id;
	_process->work = get_object('A');
	_process->max = get_object('A');
	_process->allocation = get_object('A');
	_process->need = get_object('A');
	_process->finish = false;
	_process->next = NULL;
	_process->pre = NULL;
	
	return _process;
}

//显示列表(测试)
int show_list(struct RESOURCE* list) {
	while(list!=NULL) {
		printf("%c:%d  ",list->kind,list->num);
		list = list->next;
	}
	printf("\n");
}

//显示进程信息(测试)
int show_process(Process *_tmp) {
	while(_tmp!=NULL) {
		printf("进程ID:%d\n",_tmp->id);
		printf("work:");show_list(_tmp->work);
		printf("max:");show_list(_tmp->max);
		printf("need:");show_list(_tmp->need);
		printf("allocation:");show_list(_tmp->allocation);
		_tmp = _tmp->next;
	}
	printf("\n");
}

//显示列表(测试)
int show_safe(void) {
	Safe *_safe = safe;
	while(_safe!=NULL) {
		printf("%d  ",_safe->id);
		_safe = _safe->next;
	}
	printf("\n");
}

//初始化安全序列链表
int initial_safe(void) {
	while(safe!=NULL) {
		Safe *_tmp = safe;
		safe = safe->next;
		free(_tmp);
	}
	safe = malloc(sizeof(Safe));
	Safe *_safe = safe;
	_safe->id = -1;
	int _pro_num = 1;
	
	while(_pro_num++ < PROCESS_NUM) {
		_safe->next = malloc(sizeof(Safe));
		_safe->next->id = -1;
		_safe = _safe->next;
	}
	_safe->next = NULL;
}

int pro_id = 0;
//初始化
int initial(void) {

	//初始化Available
	available = get_object('A');

	//初始化进程
	process = get_process(pro_id++);//初始化头指针
	Process * _process_tmp = process;
	int _pro_num = 1;
	while(_pro_num++ < PROCESS_NUM) {//初始化所设置进程数量的进程
		_process_tmp->next = get_process(pro_id++);
		_process_tmp->next->pre = _process_tmp;
		_process_tmp = _process_tmp->next;
	}
	_process_tmp->next = NULL;
	
	initial_safe();
}

//根据进程最大需求和已经分配的资源初始化其他数据
int calculate(void) {
	//计算Available
	Process *_tmp_process = process;
	Max *_tmp_max = NULL;
	Allocation *_tmp_allocation = NULL;
	Need *_tmp_need = NULL;
	
	while( _tmp_process != NULL ) {
		_tmp_max = _tmp_process->max;
		_tmp_allocation = _tmp_process->allocation;
		_tmp_need = _tmp_process->need;
		while(_tmp_max!=NULL) {//循环遍历每个进程的max的每类资源
			
			_tmp_need->num = _tmp_max->num - _tmp_allocation->num;// 每个进程的每类资源的max-allocation
			
			_tmp_need = _tmp_need->next;
			_tmp_allocation = _tmp_allocation->next;
			_tmp_max = _tmp_max->next;
		}
		_tmp_process = _tmp_process->next;
	}
}

//初始化随机生成系统资源available 每个进程已分配allocation和max
int random_create(void) {
	srand(time(NULL));

	Process *_process = process;
	
	Max *max_value = get_object('A');//所有进程每类资源所需最大值
	Max *i_max_value = NULL;
	while(_process!=NULL) {//循环遍历每个进程
		Max *_max = _process->max;	//保存经过的进程的max  循环遍历每类资源
		Allocation *_allocation = _process->allocation;//allocation
		i_max_value = max_value;
		while(_max!=NULL) {	//循环遍历每个进程的max 和 allocation 的每类资源
			int _tmp_max,_tmp_allocation;
			_tmp_max = rand()%10;//随机生成max的值
			_max->num = _tmp_max;
			
			do {
				if( _tmp_max == 0 ) {
					_tmp_allocation = 0;
					break;
				}
				_tmp_allocation = rand()%10;//随机生成allocation的值,如果大于max最大需要,则一直循环生成allocation直到小于
			}while( _tmp_allocation >= _tmp_max );	
						
			if( _tmp_max > i_max_value->num ) {	
				i_max_value->num = _tmp_max - _tmp_allocation;
			}
			
			_allocation->num = _tmp_allocation;
			
			_max = _max->next;
			_allocation = _allocation->next;
			i_max_value = i_max_value->next;
		}
		_process = _process->next;
	}
	
		
	//随机生成available
	Available *_available = available;
	//循环遍历available每类资源并随机生成
	i_max_value = max_value;
	while(_available!=NULL) {
		
		int _tmp_available;
		do {
			_tmp_available = rand()%10;
		} while( _tmp_available < i_max_value->num );
		_available->num = _tmp_available;
		_available = _available->next;
		i_max_value = i_max_value->next;
	}
}

//检查是否还有可用资源available
int check_available(void) {
	Available *_available = available;
	while(_available!=NULL) {
		if(_available->num > 0)
			return 1;
		_available = _available->next;
	}
	
	return 0;
}

//随机生成一个进程，并随机分配allocation资源和max资源,或通过输入生成,插入process链尾
int random_create_process(Max *input_max, Allocation *input_allocation) {
	if( !check_available() )//如果没有可用资源
		return 0;
	
	Process *_process = process;
	while(process!=NULL && process->next != NULL) {
		process = process->next;
	}
	if( process != NULL ) {
		process->next = get_process(pro_id++);
		process->next->pre = process;
		process = process->next;
	} else
		process = get_process(pro_id++);
	
	Available *_available = available;
	Max *_max = process->max;	//循环遍历每类资源
	Allocation *_allocation = process->allocation;//allocation
	while(_max!=NULL) {	//循环遍历进程的max 和 allocation 的每类资源
		int _tmp_max,_tmp_allocation;
		
		if( input_max != NULL || input_allocation != NULL ) {
			_tmp_max = input_max->num;
			_tmp_allocation = input_allocation->num;
			
			input_max = input_max->next;
			input_allocation = input_allocation->next;
		} else {
			_tmp_max = rand()%10;//随机生成max的值
			do {
				if( _tmp_max == 0 ) {
					_tmp_allocation = 0;
					break;
				}
				_tmp_allocation = rand()%10;//随机生成allocation的值,如果大于max最大需要,则一直循环生成allocation直到小于
			}while( _tmp_allocation >= _tmp_max );	
			if( _tmp_allocation > _available->num )
				_tmp_allocation = _available->num;
		}

		_allocation->num = _tmp_allocation;
		_available->num -= _tmp_allocation;
		_max->num = _tmp_max;
		_available = _available->next;
		_max = _max->next;
		_allocation = _allocation->next;
	}
	if( _process!=NULL )//用process_来遍历链表了，所以当头指针不为NULL(进程链中还有进程)时，将头指针赋值回去
		process = _process;
	PROCESS_NUM++;

	calculate();
	
	return 1;
}

//还原进程的finish
int reset_process_finish(void) {
	
	Process *_process = process;
	Work *_work = NULL;
	while(_process!=NULL) {
		_work = _process->work;
		while( _work!=NULL ) {
			_work->num = 0;
			_work = _work->next;
		}
		_process->finish = false;
		_process = _process->next;
	}
	
}

//计算能否找到下一个安全进程,找到则给work和finish赋值
//接受的参数表示可用资源链表
//返回-1表示没有找到安全序列
//返回其他数字表示当前已经finish的进程
int banker(struct RESOURCE *work) {
	
	struct RESOURCE *_work = work;
	Process *_process = process;
	Need *_need = NULL;
	while( _process!=NULL ){//遍历每个进程查找
		_need = _process->need;
		_work = work;
		while( _work!=NULL ) {//遍历每类资源,如果不能分配给该进程则break
			if( _process->finish == true )
				break;

			if( _work->num < _need->num )//如果work小于need
				break;
			
			_work = _work->next;
			_need = _need->next;
			
			if( _work == NULL ) {//如果到链尾，表示所有的资源都可满足,则返回该进程的id
				Work *_tmp_work = work;
				Allocation *_tmp_allocation = _process->allocation;
				Work *_current_time_process = _process->work;
				while( _tmp_work != NULL ) {//将work工作向量的每类资源加上该进程的allocation
					_current_time_process->num = _tmp_work->num;
					_tmp_work->num = _tmp_work->num + _tmp_allocation->num;
					
					_tmp_work = _tmp_work->next;
					_tmp_allocation = _tmp_allocation->next;
					_current_time_process = _current_time_process->next;
				}
				_process->finish = true;
				
				return _process->id;
			}
		}
		_process = _process->next;
	}
	
	//没有进程可分配
	return -1;
}

//计算安全序列存放至safe
int safe_order(void) {
	int _i = 0;
	initial_safe();
	reset_process_finish();
	Work *work = get_object('A');
	copy_resource(available,work);
	
	Safe *_safe = safe;
	while( _i < PROCESS_NUM ) {
		_safe->id = banker(work);
		_i++;
		_safe = _safe->next;
		
	}
}

//检测系统是否处于安全状态
//返回0处于不安全
int check_safe_sate(void) {
	if( PROCESS_NUM == 0 )
		return 1;
	Safe *_safe = safe;
	while(_safe!=NULL) {
		if( _safe->id == -1 )
			return 0;
		_safe = _safe->next;
	}
	return 1;
}

//源复制到目的
int copy_resource(struct RESOURCE *raw, struct RESOURCE *dest) {
	while( raw != NULL ) {
		dest->num = raw->num;
		raw = raw->next;
		dest = dest->next;
	}
}

//根据进程设置改变系统时间
int system_current_time(Process *_process) {
	if( FLAG_PROCESS_TIME == 0 ) {//如果是随机生成进程运行时间
		
	} else {//固定运行时间
		CURRENT_TIME++;
	}
}

//根据安全序列执行一个进程
int run_step(void) {
	
	if( safe == NULL )//如果队列为空
		return 0;
	Process *_tmp_process = process;
	Process *_will_execute = NULL;
	while(_tmp_process!=NULL) {
		if( _tmp_process->id == safe->id ) {//从安全序列队头通过id找到进程的指针
			_will_execute = _tmp_process;
			break;
		}
		_tmp_process = _tmp_process->next;
	}
	
	if( _will_execute != NULL ) {
		if( _will_execute->pre == NULL ) {	//如果是队头
			if( _will_execute->next == NULL ) { //如果是队尾(既是队头又是队尾)
				process = NULL;
			} else {//是队头
				process = process->next;
				process->pre = NULL;
			}
		} else if( _will_execute->next == NULL ) {//如果是队尾
			_will_execute->pre->next = _will_execute->next;
		} else {//不是队头也不是队尾
			_will_execute->pre->next = _will_execute->next;
			_will_execute->next->pre = _will_execute->pre;
		}
		add_resource(available,_will_execute->allocation);//将进程已经分配的资源返还给系统(available)
		system_current_time(_will_execute);
		release_process(_will_execute);//释放进程
		
		PROCESS_NUM--;//当前进程数-1
		return 1;
	}
	
	return 2;
}

//撤销进程
int cancel_process(void) {
	if( process == NULL )
		return 0;
	
	Process *_process = process;
	while(_process->next!=NULL) {
		_process = _process->next;
	}

	Available *_available = available;
	Allocation *_allocation = _process->allocation;
	while(_available!=NULL) {
		_available->num += _allocation->num;
		
		_allocation = _allocation->next;
		_available = _available->next;
	}
	if( _process->pre != NULL )
		_process->pre->next = _process->next;
	else
		process = NULL;
	release_process(_process);
	PROCESS_NUM--;
}

int last_process_id = -1;
struct RESOURCE *last_require = NULL;

//进程请求
int require_process(int id, struct RESOURCE *new_require) {
	if( process == NULL )
		return 0;
	last_process_id = id;
	last_require = new_require;
	Process *_process = process;
	struct RESOURCE *_new_require = new_require;
	
	while(_process!=NULL) {
		if( _process->id == id ) {
			Need *_need = _process->need;
			Allocation *_allocation = _process->allocation;
			Available *_available = available;
			
			int is_above = 0;//0表示新请求大小小于available
							 //1表示新请求大小大于available
			while(_need!=NULL) {//判断是否出错
				if( _new_require->num > _need->num ) //资源新的请求大小大于need则出错
					return -1;
				if( _new_require->num > _available->num )
					is_above = 1;
				_new_require = _new_require->next;
				_need = _need->next;
				_available = _available->next;
			}
			_new_require = new_require;
			_need = _process->need;
			_available = available;
			while(_need!=NULL) {
				if( is_above == 1 ) {//如果require>available
					//...等待
				} else {
					_allocation->num += _new_require->num;
					_need->num -= _new_require->num;
					_available->num -= _new_require->num;
				}
				_new_require = _new_require->next;
				_available = _available->next;
				_allocation = _allocation->next;
				_need = _need->next;
			}
			
			break;
		}
		_process = _process->next;
	}
}

//撤销请求
int cancel_require(void) {
	if( process == NULL || last_process_id == -1 || last_require == NULL )
		return -1;
	
	Process *_process = process;
	struct RESOURCE *_require = last_require;
	while(_process!=NULL) {
		if( _process->id == last_process_id ) {
			Need *_need = _process->need;
			Allocation *_allocation = _process->allocation;
			Available *_available = available;

			while(_need!=NULL) {
				_allocation->num -= _require->num;
				_need->num += _require->num;
				_available->num += _require->num;
				
				_require = _require->next;
				_available = _available->next;
				_allocation = _allocation->next;
				_need = _need->next;
			}
			break;
		}
		_process = _process->next;
	}
	last_require = NULL;
	last_process_id = -1;
}