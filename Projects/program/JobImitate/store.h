#pragma once
#include "job.h"
#include "data.h"
#include "job_part.h"
#include <stdlib.h>
/*内存
 */
typedef struct STORE_JOB {
	Jcb *jcb;				//实际内容(作业)
	int job_all_size;		//作业所占总内存(多个进程)   (动态:当前内存区大小)
	int start_address;	//作业在内存中起始地址
	struct STORE_JOB *next;		//指向下一分区
	struct STORE_JOB *pre;		//指向上一分区
}Store_job,Store_job_free;

/*分区说明表(固定分配)
 *空闲分区表(动态分配)
 */
typedef struct FINAL_PARTITION_DESCRIPTION {
	int partition_number;			//分区号
	int partition_size;				//分区大小
	int partition_start_address;	//分区始址
	int partition_state;			//分区状态
	
	struct FINAL_PARTITION_DESCRIPTION *next;  //下一分区表项
	struct FINAL_PARTITION_DESCRIPTION *pre;   //上一分区表项
}Final_partition_description,Final_partition_description_free;

int store_mode;//分配方式1:固定分配大小(相等)2.固定分配大小(不等)3.动态分区分配
Store_job *store_job = NULL; //内存中作业存放处
Final_partition_description *final_partition_description = NULL;//分区说明表

Store_job_free *store_job_free = NULL; //空闲链
Final_partition_description_free *final_partition_description_free = NULL; //空闲分区表

int N = 1;//分区号

/*检查内存中有几个作业
 */
int check_store_job(){
	Store_job *_tmp = store_job;
	int n = 0;
	while( _tmp != NULL ) {
		if( _tmp->jcb != NULL )
			n++;
		_tmp = _tmp->next;
	}
	return n;
}

/*释放已经完成作业的内存空间(动态)
 */
int free_finished_job_dynamic(Jcb *_jcb) {
	
	//在内存中通过jcb ID找到作业，记录起始地址
	int _will_free_jcb_start_address;
	Store_job *_tmp = store_job;
	Store_job *will_free_store = NULL;
	//遍历内存
	
	while( _tmp != NULL ) {
		//如果jcb标识相等,找到
		
		if( _tmp->jcb!=NULL && (_tmp->jcb->identify == _jcb->identify) ) {
			
			_will_free_jcb_start_address = _tmp->start_address;
			
			if( _tmp->pre == NULL ) { //如果是头节点
			
				_tmp->jcb = NULL;//设置空闲
				
				if( _tmp->next == NULL ) {
					
					free(_jcb);//释放jcb
				} else {
					//如果下一个节点空闲
					if( _tmp->next->jcb == NULL ) {
						will_free_store = _tmp->next;
						if( _tmp->next->next != NULL ) {
							_tmp->next->next->pre = _tmp;
						}
						_tmp->job_all_size += _tmp->next->job_all_size;
						_tmp->next = _tmp->next->next;
						free(_jcb);
						free(will_free_store);
						break;
					}
				}
			} else if( _tmp->next == NULL ) {//如果是尾节点
				if( _tmp->pre->jcb == NULL ) {//如果前一节点空闲
					_tmp->pre->job_all_size += _tmp->job_all_size;
					_tmp->pre->next = NULL;
					free(_jcb);//释放jcb
					free(_tmp);//释放节点空间

					
				} else {	//如果尾节点前一节点分配
					_tmp->jcb = NULL;//设置空闲
					free(_jcb);//释放jcb
					free(_tmp);//释放节点空间
				}

			} else if( _tmp->pre != NULL && _tmp->pre->jcb != NULL ) {// 如果此节点不是头节点 且上一节点已分配
				//如果下一节点已分配
				
				if( _tmp->next->jcb != NULL ){
					//将该节点标示为未分配
					_tmp->jcb = NULL;
					free(_jcb);//释放jcb内存
					break;
				} else {//如果下一节点未分配
					_tmp->job_all_size += _tmp->next->job_all_size;
					_tmp->jcb = NULL;
					
					//保存下一节点
					will_free_store = _tmp->next;
					_tmp->next = _tmp->next->next;
					if( _tmp->next != NULL )
						_tmp->next->pre = _tmp;

					free(_jcb);//释放jcb内存
					free(will_free_store);//释放节点空间

					break;
				}
			} else { //上一节点未分配
				//如果下一节点已分配
				if( _tmp->next->jcb != NULL ) {
					_tmp->pre->job_all_size += _tmp->job_all_size;
					_tmp->next->pre = _tmp->pre;
					_tmp->pre->next = _tmp->next;
					free(_jcb);//释放jcb
					free(_tmp);//释放节点
					break;
				} else {//如果下一节点未分配
					_tmp->pre->job_all_size += _tmp->job_all_size + _tmp->next->job_all_size;
					_tmp->pre->next = _tmp->next->next;
					if( _tmp->next->next != NULL )
						_tmp->next->next->pre = _tmp->pre;
					free(_jcb);//释放jcb
					free(_tmp->next);//释放下一节点 
					free(_tmp);//释放当前节点
					_tmp = NULL;
					break;
				}
			}
		}
		if( _tmp != NULL )
			_tmp = _tmp->next;
	}

	Final_partition_description *_tmp_free = final_partition_description;
	Final_partition_description *_tmp_will_free = NULL;
	while( _tmp_free != NULL ) {
		//通过起始地址找到需要修改的表项
		if( _tmp_free->partition_start_address == _will_free_jcb_start_address ) {
			// 如果此节点不是头节点 且上一节点已分配
			if( _tmp_free->pre == NULL ) {
				if( _tmp_free->next == NULL ) {
					_tmp_free->partition_state = 0;//设置空闲
					free(_jcb);//释放jcb
				} else {
					_tmp_free->partition_state = 0;//设置空闲
					//如果下一个节点空闲
					if( _tmp_free->next->partition_state == 0 ) {
						_tmp_will_free = _tmp_free->next;
						if( _tmp_free->next->next != NULL ) {
							_tmp_free->next->next->pre = _tmp_free;
						}
						_tmp_free->partition_size += _tmp_free->next->partition_size;
						_tmp_free->next = _tmp_free->next->next;
						free(_jcb);
						free(_tmp_will_free);
						break;
					}
				}
			} else if( _tmp_free->next == NULL ) {// 如果是尾节点
				if( _tmp_free->pre->partition_state == 0 ) {//如果前一节点空闲
					_tmp_free->pre->partition_size += _tmp_free->partition_size;
					_tmp_free->pre->next = NULL;
				}
				_tmp->jcb = NULL;//设置空闲
				free(_jcb);//释放jcb
				free(_tmp);//释放节点空间
			} else if( _tmp_free->pre->partition_state == 1 ) {
				//如果下一节点已分配
				if( _tmp_free->next->partition_state == 1 ){
					//将该节点标示为未分配
					_tmp_free->partition_state = 0;
					break;
				} else {//如果下一节点未分配
					_tmp_free->partition_size += _tmp_free->next->partition_size;
					_tmp_free->partition_state = 0;
					
					//保存下一节点
					_tmp_will_free = _tmp_free->next;
					_tmp_free->next = _tmp_free->next->next;

					if( _tmp_free->next != NULL )
						_tmp_free->next->pre = _tmp_free;

					free(_tmp_will_free);//释放节点空间
					break;
				}
			} else { //上一节点未分配,不是尾节点
				//如果下一节点已分配
				if( _tmp_free->next->partition_state == 1 ) {
					_tmp_free->pre->partition_size += _tmp_free->partition_size;
					_tmp_free->next->pre = _tmp_free->pre;
					_tmp_free->pre->next = _tmp_free->next;

					free(_tmp_free);//释放节点
					break;
				} else {//如果下一节点未分配
					_tmp_free->pre->partition_size += _tmp_free->partition_size + _tmp_free->next->partition_size;
					_tmp_free->pre->next = _tmp_free->next->next;
					if( _tmp_free->next->next != NULL )
						_tmp_free->next->next->pre = _tmp_free->pre;
					free(_tmp_free->next);//释放下一节点 
					free(_tmp_free);//释放当前节点
					_tmp_free = NULL;
					break;
				}
			}
		}
		if( _tmp_free != NULL )
			_tmp_free = _tmp_free->next;
	}
}

/*释放已经完成作业的内存空间(静态)
 */
int free_finished_job_static(Jcb *_jcb) {
	Store_job *_store = store_job;
	Final_partition_description *_description = final_partition_description;
	
	int _start_address;
	while( _store->jcb != NULL ) {
		//如果找到将要释放的jcb
		if( _store->jcb->identify == _jcb->identify ) {
			_start_address = _store->start_address;//保存起始地址用来修改分区描述表
			_store->jcb = NULL;
			free(_jcb);//释放空间
			break;
		}
		_store = _store->next;
	}

	while(_description!=NULL) {
		if( _description->partition_start_address == _start_address ) {
			_description->partition_state = 0;
			break;
		}
		_description = _description->next;
	}
}

/*动态分区初始化
 */
void dynamic_store_init() {
	//初始化分区表
	final_partition_description = NULL;
	final_partition_description_free = malloc(sizeof(Final_partition_description_free));
	final_partition_description_free->partition_number = N++;
	final_partition_description_free->partition_size = memory_size;
	final_partition_description_free->partition_start_address = 0;
	final_partition_description_free->partition_state = 0;
	final_partition_description_free->next = NULL;
	final_partition_description_free->pre = NULL;
	final_partition_description = final_partition_description_free;
	//已使用分区链和空闲分区链为空
	store_job_free = malloc(sizeof(Store_job_free));
	store_job_free->next=NULL;
	store_job_free->pre=NULL;
	store_job_free->start_address=0;
	store_job_free->jcb=NULL;
	store_job_free->job_all_size = memory_size;
	store_job = store_job_free;
}

/*初始化内存分配方式
 */
void initial_store(int mode,int size) {
	store_mode = mode;
	// 根据多道 道数初始化
	int _memory_size;
	
	Store_job *next;
	Final_partition_description *next_descrip;
	int _start_address = 0;
	switch(mode) {
		case 1://固定分配(分区大小相等)
	
			_start_address = 0;

			store_job = malloc(sizeof(Store_job));
			store_job->next=NULL;
			store_job->jcb=NULL;
			store_job->start_address = 0;
			final_partition_description = (Final_partition_description *)malloc(sizeof(Final_partition_description));
			final_partition_description->next=NULL;
			final_partition_description->partition_number = N++;
			final_partition_description->partition_size = size;
			final_partition_description->partition_start_address = _start_address;
			final_partition_description->partition_state = 0;  //未分配
			_start_address += size;
			
			_memory_size = memory_size - size;
			
			next = store_job;
			next_descrip = final_partition_description;
			while( _memory_size > 0 ) {

				next->next = malloc(sizeof(Store_job));
				next = next->next;
				next->jcb = NULL;
				next_descrip->next = (Final_partition_description *)malloc(sizeof(Final_partition_description));
				next_descrip = next_descrip->next;
				next_descrip->next = NULL;
				next_descrip->partition_number = N++;
				next_descrip->partition_size = size;
				next_descrip->partition_start_address = _start_address;
				next->start_address = next_descrip->partition_start_address;
				next_descrip->partition_state = 0;
				_start_address += size;
				_memory_size -= size;
			}
			next->next = NULL;
			break;
		case 2://固定分配(分区大小不等)

			_memory_size = memory_size;
			_start_address = 0;

			size = 32;
			
			store_job = malloc(sizeof(Store_job));
			store_job->next=NULL;
			store_job->jcb=NULL;
			store_job->start_address = 0;
			final_partition_description = (Final_partition_description *)malloc(sizeof(Final_partition_description));
			final_partition_description->next=NULL;
			final_partition_description->partition_number = N++;
			final_partition_description->partition_size = size;
			final_partition_description->partition_start_address = _start_address;
			final_partition_description->partition_state = 0;  //未分配
			_start_address += size;
			
			next = store_job;
			next_descrip = final_partition_description;
			while( _memory_size > 0 ) {
				next->next = malloc(sizeof(Store_job));
				next = next->next;
				next->jcb = NULL;
				next_descrip->next = (Final_partition_description *)malloc(sizeof(Final_partition_description));
				next_descrip = next_descrip->next;
				next_descrip->next = NULL;
				next_descrip->partition_number = N++;
				next_descrip->partition_size = size;
				next_descrip->partition_start_address = _start_address;
				next->start_address = next_descrip->partition_start_address;
				next_descrip->partition_state = 0;
				_start_address += size;
				size *= 2;
				_memory_size -= size;
			}
			next->next = NULL;
			break;
		case 3://动态分配
			dynamic_store_init();
			break;
	}
}

/********************************动态分区分配*******************************************/

int current_method = 1;	//当前分区分配算法

//首次适应算法
int FF(Jcb *_jcb) {
	
	Final_partition_description *tmp_final_partition_description = final_partition_description;
	Store_job *_tmp_store_job = store_job;
	int free_address = 0;
	//顺序查找第一个空闲分区表

	while( tmp_final_partition_description!=NULL ) {
		//如果找到空闲区
		if( tmp_final_partition_description->partition_state == 0 ) {
			//如果该空闲区大于作业内存需求
			if( tmp_final_partition_description->partition_size > _jcb->request_memory ) {
				
				//新建一个空闲分区
				Final_partition_description *_tmp = malloc(sizeof(Final_partition_description));
				_tmp->partition_state=0;
				_tmp->partition_start_address = tmp_final_partition_description->partition_start_address+_jcb->request_memory;
				_tmp->partition_size = tmp_final_partition_description->partition_size-_jcb->request_memory;
				_tmp->partition_number = N++;
				_tmp->next = tmp_final_partition_description->next;
				if( _tmp->next != NULL )
					_tmp->next->pre = _tmp;
				
				_tmp->pre = tmp_final_partition_description;
				
				tmp_final_partition_description->next = _tmp;
				
				tmp_final_partition_description->partition_state = 1;
				free_address = tmp_final_partition_description->partition_start_address;	//保存分配前的始址
				tmp_final_partition_description->partition_size = _jcb->request_memory;
				break;
			} else if( tmp_final_partition_description->partition_size == _jcb->request_memory ) {
				tmp_final_partition_description->partition_state = 1;
				break;
			}
		}
		tmp_final_partition_description = tmp_final_partition_description->next;
	}

	Store_job *_new_tmp = malloc(sizeof(Store_job));	//创建新节点插入到旧节点之后 
	while( _tmp_store_job != NULL ) {
		if( _tmp_store_job->start_address == free_address ) {
			
			if( _tmp_store_job->job_all_size > _jcb->request_memory ) { //如果空闲区大小大于请求大小

				_new_tmp->jcb = NULL;		//新节点空闲
				_new_tmp->job_all_size = _tmp_store_job->job_all_size - _jcb->request_memory;
				_new_tmp->start_address = _tmp_store_job->start_address + _jcb->request_memory;
				_new_tmp->pre = _tmp_store_job;
				_new_tmp->next = _tmp_store_job->next;
				if( _new_tmp->next != NULL )
					_new_tmp->next->pre = _new_tmp;
				
				_tmp_store_job->jcb = _jcb;	//将jcb放入
				_tmp_store_job->next = _new_tmp;
				_tmp_store_job->job_all_size = _jcb->request_memory;
				
				break;
			} else if( _tmp_store_job->job_all_size == _jcb->request_memory ) {
				_tmp_store_job->jcb = _jcb;
				break;
			}
		}
		_tmp_store_job = _tmp_store_job->next;
	}
}

//上次指针
Final_partition_description *_previous = NULL;

//循环首次适应算法
int NF(Jcb *_jcb) {
	Final_partition_description *_tmp_last = _previous;
	Store_job *_tmp_store_job = store_job;
	int free_address = 0;
	//顺序查找第一个空闲分区表

	int _i = 0; //如果从上次节点起没有，找到，从头循环一次
	while( _previous!=NULL ) {
		//如果找到空闲区
		if( _previous->partition_state == 0 ) {
			//如果该空闲区大于作业内存需求
			if( _previous->partition_size > _jcb->request_memory ) {
				//新建一个空闲分区
				Final_partition_description *_tmp = malloc(sizeof(Final_partition_description));
				_tmp->partition_state=0;
				_tmp->partition_start_address = _previous->partition_start_address+_jcb->request_memory;
				_tmp->partition_size = _previous->partition_size-_jcb->request_memory;
				_tmp->partition_number = N++;
				_tmp->next = _previous->next;
				if( _tmp->next != NULL )
					_tmp->next->pre = _tmp;
				
				_tmp->pre = _previous;
				
				_previous->next = _tmp;
				
				_previous->partition_state = 1;
				free_address = _previous->partition_start_address;	//保存分配前的始址
				_previous->partition_size = _jcb->request_memory;
				break;
			} else if( _previous->partition_size == _jcb->request_memory ) {
				_previous->partition_state = 1;
				break;
			}
		}
		_previous = _previous->next;
		if( _i == 0 && _previous == NULL ) {
			_previous = final_partition_description;
			_i = 1;
		}
		if( _i == 1 && _previous == _tmp_last )
			break;
	}
	
	Store_job *_new_tmp = malloc(sizeof(Store_job));	//创建新节点插入到旧节点之后 
	while( _tmp_store_job != NULL ) {
		if( _tmp_store_job->start_address == free_address ) {
			
			if( _tmp_store_job->job_all_size > _jcb->request_memory ) { //如果空闲区大小大于请求大小

				_new_tmp->jcb = NULL;		//新节点空闲
				_new_tmp->job_all_size = _tmp_store_job->job_all_size - _jcb->request_memory;
				_new_tmp->start_address = _tmp_store_job->start_address + _jcb->request_memory;
				_new_tmp->pre = _tmp_store_job;
				_new_tmp->next = _tmp_store_job->next;
				if( _new_tmp->next != NULL )
					_new_tmp->next->pre = _new_tmp;
				
				_tmp_store_job->jcb = _jcb;	//将jcb放入
				_tmp_store_job->next = _new_tmp;
				_tmp_store_job->job_all_size = _jcb->request_memory;
				
				break;
			} else if( _tmp_store_job->job_all_size == _jcb->request_memory ) {
				_tmp_store_job->jcb = _jcb;
				break;
			}
		}
		_tmp_store_job = _tmp_store_job->next;
	}
}

//最佳适应算法
int BF(Jcb *_jcb) {
	Final_partition_description *_tmp_description = final_partition_description;
	Store_job *_tmp_store = store_job;
	int will_size = memory_size;
	int will_start_address = 0;
	int will_partition_number = 0;
	//寻找最佳适应的空闲区
	while( _tmp_description != NULL ) {
		if( _tmp_description->partition_state == 0 ) {//如果是空闲区
			//如果该空闲区大于所需大小且小于上次搜索到的空闲大小
			if( (_tmp_description->partition_size >= _jcb->request_memory) && (_tmp_description->partition_size <= will_size) ) {
				will_size = _tmp_description->partition_size;
				will_start_address = _tmp_description->partition_start_address;
				will_partition_number = _tmp_description->partition_number;
			}
		}
		_tmp_description = _tmp_description->next;
	}
	Final_partition_description *tmp_final_partition_description = final_partition_description;
	Store_job *_tmp_store_job = store_job;
	int free_address = 0;
	
	
	
	while( tmp_final_partition_description!=NULL ) {//如果找到空闲区
		if( tmp_final_partition_description->partition_number == will_partition_number ) {
			//如果该空闲区大于作业内存需求
			if( tmp_final_partition_description->partition_size > _jcb->request_memory ) {
				
				//新建一个空闲分区
				Final_partition_description *_tmp = malloc(sizeof(Final_partition_description));
				_tmp->partition_state=0;
				_tmp->partition_start_address = tmp_final_partition_description->partition_start_address+_jcb->request_memory;
				_tmp->partition_size = tmp_final_partition_description->partition_size-_jcb->request_memory;
				_tmp->partition_number = N++;
				_tmp->next = tmp_final_partition_description->next;
				if( _tmp->next != NULL )
					_tmp->next->pre = _tmp;
				
				_tmp->pre = tmp_final_partition_description;
				
				tmp_final_partition_description->next = _tmp;
				
				tmp_final_partition_description->partition_state = 1;
				free_address = tmp_final_partition_description->partition_start_address;	//保存分配前的始址
				tmp_final_partition_description->partition_size = _jcb->request_memory;
				break;
			} else if( tmp_final_partition_description->partition_size == _jcb->request_memory ) {
				tmp_final_partition_description->partition_state = 1;
				break;
			}
		}
		tmp_final_partition_description = tmp_final_partition_description->next;
	}

	Store_job *_new_tmp = malloc(sizeof(Store_job));	//创建新节点插入到旧节点之后 
	while( _tmp_store_job != NULL ) {
		if( _tmp_store_job->start_address == free_address ) {
			
			if( _tmp_store_job->job_all_size > _jcb->request_memory ) { //如果空闲区大小大于请求大小

				_new_tmp->jcb = NULL;		//新节点空闲
				_new_tmp->job_all_size = _tmp_store_job->job_all_size - _jcb->request_memory;
				_new_tmp->start_address = _tmp_store_job->start_address + _jcb->request_memory;
				_new_tmp->pre = _tmp_store_job;
				_new_tmp->next = _tmp_store_job->next;
				if( _new_tmp->next != NULL )
					_new_tmp->next->pre = _new_tmp;
				
				_tmp_store_job->jcb = _jcb;	//将jcb放入
				_tmp_store_job->next = _new_tmp;
				_tmp_store_job->job_all_size = _jcb->request_memory;
				
				break;
			} else if( _tmp_store_job->job_all_size == _jcb->request_memory ) {
				_tmp_store_job->jcb = _jcb;
				break;
			}
		}
		_tmp_store_job = _tmp_store_job->next;
	}
}

//最坏适应算法
int WF(Jcb *_jcb) {
	Final_partition_description *_tmp_description = final_partition_description;
	Store_job *_tmp_store = store_job;
	int will_size = 0;
	int will_start_address = 0;
	int will_partition_number = 0;
	//寻找最佳适应的空闲区
	while( _tmp_description != NULL ) {
		if( _tmp_description->partition_state == 0 ) {//如果是空闲区
			//如果该空闲区大于所需大小且小于上次搜索到的空闲大小
			if( (_tmp_description->partition_size >= _jcb->request_memory) && (_tmp_description->partition_size >= will_size) ) {
				will_size = _tmp_description->partition_size;
				will_start_address = _tmp_description->partition_start_address;
				will_partition_number = _tmp_description->partition_number;
			}
		}
		_tmp_description = _tmp_description->next;
	}
	Final_partition_description *tmp_final_partition_description = final_partition_description;
	Store_job *_tmp_store_job = store_job;
	int free_address = 0;
	
	
	
	while( tmp_final_partition_description!=NULL ) {//如果找到空闲区
		if( tmp_final_partition_description->partition_number == will_partition_number ) {
			//如果该空闲区大于作业内存需求
			if( tmp_final_partition_description->partition_size > _jcb->request_memory ) {
				
				//新建一个空闲分区
				Final_partition_description *_tmp = malloc(sizeof(Final_partition_description));
				_tmp->partition_state=0;
				_tmp->partition_start_address = tmp_final_partition_description->partition_start_address+_jcb->request_memory;
				_tmp->partition_size = tmp_final_partition_description->partition_size-_jcb->request_memory;
				_tmp->partition_number = N++;
				_tmp->next = tmp_final_partition_description->next;
				if( _tmp->next != NULL )
					_tmp->next->pre = _tmp;
				
				_tmp->pre = tmp_final_partition_description;
				
				tmp_final_partition_description->next = _tmp;
				
				tmp_final_partition_description->partition_state = 1;
				free_address = tmp_final_partition_description->partition_start_address;	//保存分配前的始址
				tmp_final_partition_description->partition_size = _jcb->request_memory;
				break;
			} else if( tmp_final_partition_description->partition_size == _jcb->request_memory ) {
				tmp_final_partition_description->partition_state = 1;
				break;
			}
		}
		tmp_final_partition_description = tmp_final_partition_description->next;
	}

	Store_job *_new_tmp = malloc(sizeof(Store_job));	//创建新节点插入到旧节点之后 
	while( _tmp_store_job != NULL ) {
		if( _tmp_store_job->start_address == free_address ) {
			
			if( _tmp_store_job->job_all_size > _jcb->request_memory ) { //如果空闲区大小大于请求大小

				_new_tmp->jcb = NULL;		//新节点空闲
				_new_tmp->job_all_size = _tmp_store_job->job_all_size - _jcb->request_memory;
				_new_tmp->start_address = _tmp_store_job->start_address + _jcb->request_memory;
				_new_tmp->pre = _tmp_store_job;
				_new_tmp->next = _tmp_store_job->next;
				if( _new_tmp->next != NULL )
					_new_tmp->next->pre = _new_tmp;
				
				_tmp_store_job->jcb = _jcb;	//将jcb放入
				_tmp_store_job->next = _new_tmp;
				_tmp_store_job->job_all_size = _jcb->request_memory;
				
				break;
			} else if( _tmp_store_job->job_all_size == _jcb->request_memory ) {
				_tmp_store_job->jcb = _jcb;
				break;
			}
		}
		_tmp_store_job = _tmp_store_job->next;
	}
}

/*作业放入内存
 */
int _state_3 = 0;
Jcb *push_job(Jcb *_jcb){
	
	
	//根据内存分配方式和调度算法放入作业
	Final_partition_description *free = final_partition_description;
	int free_address;//分区号对应地址
	Store_job *_store_job = store_job;
	Store_job_free *tmp_free = store_job_free;
	Final_partition_description_free *tmp_description_free = final_partition_description_free;
	switch(store_mode) {
		case 1://固定分配(固定大小)
			//如果作业大小大于分配大小  返回-1
			if( _jcb->request_memory > final_partition_description->partition_size )
				return NULL;
			//找到第一个空闲区
			while( free != NULL ) {
				//如果找到空闲区
				if( free->partition_state == 0 ) {
					free->partition_state = 1;//表示分配
					free_address = free->partition_start_address;
					break;
				}
				free = free->next;
			}
			
			//在分区链中找到对应地址
			while(_store_job!=NULL) {
				//找到对应地址
				if( _store_job->start_address == free_address ) {
					_store_job->jcb = _jcb;
					_store_job->job_all_size = _jcb->request_memory;
					break;
				}
				_store_job = _store_job->next;
			}
			break;
		case 2://固定分配(大小不等)
			//找到第一个空闲区
			while( free != NULL ) {
				//如果找到空闲区
				if( free->partition_state == 0 ) {
					//如果空闲区的大小>作业大小，则分配
					if( free->partition_size >= _jcb->request_memory ) {
						free->partition_state = 1;//表示分配
						free_address = free->partition_start_address;
						break;
					}
				}
				free = free->next;
			}
			
			//在分区链中找到对应地址
			while(_store_job!=NULL) {
				//找到对应地址
				if( _store_job->start_address == free_address ) {
					_store_job->jcb = _jcb;
					_store_job->job_all_size = _jcb->request_memory;
					break;
				}
				_store_job = _store_job->next;
			}
			break;
		case 3://动态分配
			//将jcb放入空闲链中
			if( current_method == 1 ) { //首次适应算法
				FF(_jcb);
			} else if( current_method == 2 ) {//循环首次适应算法
				if( _state_3 == 0 ) {
					_previous = final_partition_description;
					_state_3 = 1;
				}
				NF(_jcb);
			} else if( current_method == 3 ) //最佳适应算法
				BF(_jcb);
			else if(current_method == 4 ) //最坏适应算法
				WF(_jcb);
			break;
	}
	
	return _jcb;
}

