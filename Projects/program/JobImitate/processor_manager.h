#pragma once
#include "store.h"
#include "job.h"
#include "job_0.h"
#include "job_1.h"
#include "job_2.h"
#include "job_3.h"
#include "job_4.h"
#include "job_5.h"
#include "job_6.h"
#include "job_7.h"
#include "job_8.h"
#include "job_9.h"
#include <stdlib.h>
#include "track.h"
#include "data.h"
#include <windows.h>
#include <time.h>

/*后备队列
 */
typedef struct RESERVE_QUEUE {
	Jcb *jcb;
	
	struct RESERVE_QUEUE *next;
}Reserve_queue;

Reserve_queue *reserve_queue = NULL;

/*创建默认系统作业
 */
void create_job_default() {
	Reserve_queue *_tmp = reserve_queue;
	srand(time(NULL));
	//作业0
	Jcb *_jcb_0 = malloc(sizeof(Jcb));			//第1个作业
	_jcb_0->identify = _JCB_ID;
	_jcb_0->username = "Mr.shi";
	_jcb_0->user_account = _JCB_ID++;
	_jcb_0->kind = 0; //普通
	_jcb_0->status = 0;//后备状态
	_jcb_0->prior = 0;//默认优先级
	_jcb_0->runtime = 0;//已经运行时间
	_jcb_0->request_time = 1500;//预计运行时间1500毫秒
	_jcb_0->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_0_part = malloc(sizeof(Job_part));
	_jcb_0->part = _job_0_part;//实际运行的代码部分
	_job_0_part->code = job_0_part_0;
	_job_0_part->job_size = 4;
	_job_0_part->next = malloc(sizeof(Job_part));
	_job_0_part = _job_0_part->next;
	_job_0_part->code = job_0_part_1;
	_job_0_part->job_size = 4;
	_job_0_part->next = malloc(sizeof(Job_part));
	_job_0_part = _job_0_part->next;
	_job_0_part->code = job_0_part_2;
	_job_0_part->job_size = 4;
	_job_0_part->next = NULL;
	_tmp->jcb = _jcb_0;
	
	//作业1
	_tmp = _tmp->next;
	Jcb *_jcb_1 = malloc(sizeof(Jcb));	
	_jcb_1->identify = _JCB_ID;
	_jcb_1->username = "Mr.xi";
	_jcb_1->user_account = _JCB_ID++;
	_jcb_1->kind = 0; //普通
	_jcb_1->status = 0;//后备状态
	_jcb_1->prior = 0;//默认优先级
	_jcb_1->runtime = 0;//已经运行时间
	_jcb_1->request_time = 1500;//预计运行时间1500毫秒
	_jcb_1->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_1_part = malloc(sizeof(Job_part));
	_jcb_1->part = _job_1_part;//实际运行的代码部分
	_job_1_part->code = job_1_part_0;
	_job_1_part->job_size = 4;
	_job_1_part->next = malloc(sizeof(Job_part));
	_job_1_part = _job_1_part->next;
	_job_1_part->code = job_1_part_1;
	_job_1_part->job_size = 4;
	_job_1_part->next = malloc(sizeof(Job_part));
	_job_1_part = _job_1_part->next;
	_job_1_part->code = job_1_part_2;
	_job_1_part->job_size = 4;
	_job_1_part->next = malloc(sizeof(Job_part));
	_job_1_part = _job_1_part->next;
	_job_1_part->code = job_1_part_3;
	_job_1_part->job_size = 4;
	_job_1_part->next = malloc(sizeof(Job_part));
	_job_1_part = _job_1_part->next;
	_job_1_part->code = job_1_part_4;
	_job_1_part->job_size = 4;
	_job_1_part->next = NULL;
	_tmp->jcb = _jcb_1;
	
	//作业2
	_tmp = _tmp->next;
	Jcb *_jcb_2 = malloc(sizeof(Jcb));	
	_jcb_2->identify = _JCB_ID;
	_jcb_2->username = "Mr.wang";
	_jcb_2->user_account = _JCB_ID++;
	_jcb_2->kind = 0; //普通
	_jcb_2->status = 0;//后备状态
	_jcb_2->prior = 0;//默认优先级
	_jcb_2->runtime = 0;//已经运行时间
	_jcb_2->request_time = 1500;//预计运行时间1500毫秒
	_jcb_2->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_2_part = malloc(sizeof(Job_part));
	_jcb_2->part = _job_2_part;//实际运行的代码部分
	_job_2_part->code = job_2_part_0;
	_job_2_part->job_size = 4;
	_job_2_part->next = NULL;
	_tmp->jcb = _jcb_2;
	
	//作业3
	_tmp = _tmp->next;
	Jcb *_jcb_3 = malloc(sizeof(Jcb));	
	_jcb_3->identify = _JCB_ID;
	_jcb_3->username = "Mr.a";
	_jcb_3->user_account = _JCB_ID++;
	_jcb_3->kind = 0; //普通
	_jcb_3->status = 0;//后备状态
	_jcb_3->prior = 0;//默认优先级
	_jcb_3->runtime = 0;//已经运行时间
	_jcb_3->request_time = 1500;//预计运行时间1500毫秒
	_jcb_3->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_3_part = malloc(sizeof(Job_part));
	_jcb_3->part = _job_3_part;//实际运行的代码部分
	_job_3_part->code = job_3_part_0;
	_job_3_part->job_size = 4;
	_job_3_part->next = malloc(sizeof(Job_part));
	_job_3_part = _job_3_part->next;
	_job_3_part->code = job_3_part_1;
	_job_3_part->job_size = 4;
	_job_3_part->next = malloc(sizeof(Job_part));
	_job_3_part = _job_3_part->next;
	_job_3_part->code = job_3_part_2;
	_job_3_part->job_size = 4;
	_job_3_part->next = malloc(sizeof(Job_part));
	_job_3_part = _job_3_part->next;
	_job_3_part->code = job_3_part_3;
	_job_3_part->job_size = 4;
	_job_3_part->next = malloc(sizeof(Job_part));
	_job_3_part = _job_3_part->next;
	_job_3_part->code = job_3_part_4;
	_job_3_part->job_size = 4;
	_job_3_part->next = NULL;
	_tmp->jcb = _jcb_3;
	
	//作业4
	_tmp = _tmp->next;
	Jcb *_jcb_4 = malloc(sizeof(Jcb));	
	_jcb_4->identify = _JCB_ID;
	_jcb_4->username = "Mr.b";
	_jcb_4->user_account = _JCB_ID++;
	_jcb_4->kind = 0; //普通
	_jcb_4->status = 0;//后备状态
	_jcb_4->prior = 0;//默认优先级
	_jcb_4->runtime = 0;//已经运行时间
	_jcb_4->request_time = 1500;//预计运行时间1500毫秒
	_jcb_4->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_4_part = malloc(sizeof(Job_part));
	_jcb_4->part = _job_4_part;//实际运行的代码部分
	_job_4_part->code = job_4_part_0;
	_job_4_part->job_size = 4;
	_job_4_part->next = malloc(sizeof(Job_part));
	_job_4_part = _job_4_part->next;
	_job_4_part->code = job_4_part_1;
	_job_4_part->job_size = 4;
	_job_4_part->next = malloc(sizeof(Job_part));
	_job_4_part = _job_4_part->next;
	_job_4_part->code = job_4_part_2;
	_job_4_part->job_size = 4;
	_job_4_part->next = malloc(sizeof(Job_part));
	_job_4_part = _job_4_part->next;
	_job_4_part->code = job_4_part_3;
	_job_4_part->job_size = 4;
	_job_4_part->next = malloc(sizeof(Job_part));
	_job_4_part = _job_4_part->next;
	_job_4_part->code = job_4_part_4;
	_job_4_part->job_size = 4;
	_job_4_part->next = NULL;
	_tmp->jcb = _jcb_4;
	
	//作业5
	_tmp = _tmp->next;
	Jcb *_jcb_5 = malloc(sizeof(Jcb));	
	_jcb_5->identify = _JCB_ID;
	_jcb_5->username = "Mr.c";
	_jcb_5->user_account = _JCB_ID++;
	_jcb_5->kind = 0; //普通
	_jcb_5->status = 0;//后备状态
	_jcb_5->prior = 0;//默认优先级
	_jcb_5->runtime = 0;//已经运行时间
	_jcb_5->request_time = 1500;//预计运行时间1500毫秒
	_jcb_5->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_5_part = malloc(sizeof(Job_part));
	_jcb_5->part = _job_5_part;//实际运行的代码部分
	_job_5_part->code = job_5_part_0;
	_job_5_part->job_size = 4;
	_job_5_part->next = malloc(sizeof(Job_part));
	_job_5_part = _job_5_part->next;
	_job_5_part->code = job_5_part_1;
	_job_5_part->job_size = 4;
	_job_5_part->next = malloc(sizeof(Job_part));
	_job_5_part = _job_5_part->next;
	_job_5_part->code = job_5_part_2;
	_job_5_part->job_size = 4;
	_job_5_part->next = malloc(sizeof(Job_part));
	_job_5_part = _job_5_part->next;
	_job_5_part->code = job_5_part_3;
	_job_5_part->job_size = 4;
	_job_5_part->next = malloc(sizeof(Job_part));
	_job_5_part = _job_5_part->next;
	_job_5_part->code = job_5_part_4;
	_job_5_part->job_size = 4;
	_job_5_part->next = NULL;
	_tmp->jcb = _jcb_5;
	
	//作业6
	_tmp = _tmp->next;
	Jcb *_jcb_6 = malloc(sizeof(Jcb));	
	_jcb_6->identify = _JCB_ID;
	_jcb_6->username = "Mr.d";
	_jcb_6->user_account = _JCB_ID++;
	_jcb_6->kind = 0; //普通
	_jcb_6->status = 0;//后备状态
	_jcb_6->prior = 0;//默认优先级
	_jcb_6->runtime = 0;//已经运行时间
	_jcb_6->request_time = 1500;//预计运行时间1500毫秒
	_jcb_6->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_6_part = malloc(sizeof(Job_part));
	_jcb_6->part = _job_6_part;//实际运行的代码部分
	_job_6_part->code = job_6_part_0;
	_job_6_part->job_size = 4;
	_job_6_part->next = malloc(sizeof(Job_part));
	_job_6_part = _job_6_part->next;
	_job_6_part->code = job_6_part_1;
	_job_6_part->job_size = 4;
	_job_6_part->next = malloc(sizeof(Job_part));
	_job_6_part = _job_6_part->next;
	_job_6_part->code = job_6_part_2;
	_job_6_part->job_size = 4;
	_job_6_part->next = malloc(sizeof(Job_part));
	_job_6_part = _job_6_part->next;
	_job_6_part->code = job_6_part_3;
	_job_6_part->job_size = 4;
	_job_6_part->next = malloc(sizeof(Job_part));
	_job_6_part = _job_6_part->next;
	_job_6_part->code = job_6_part_4;
	_job_6_part->job_size = 4;
	_job_6_part->next = NULL;
	_tmp->jcb = _jcb_6;
	
	//作业7
	_tmp = _tmp->next;
	Jcb *_jcb_7 = malloc(sizeof(Jcb));	
	_jcb_7->identify = _JCB_ID;
	_jcb_7->username = "Mr.xi";
	_jcb_7->user_account = _JCB_ID++;
	_jcb_7->kind = 0; //普通
	_jcb_7->status = 0;//后备状态
	_jcb_7->prior = 0;//默认优先级
	_jcb_7->runtime = 0;//已经运行时间
	_jcb_7->request_time = 1500;//预计运行时间1500毫秒
	_jcb_7->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_7_part = malloc(sizeof(Job_part));
	_jcb_7->part = _job_7_part;//实际运行的代码部分
	_job_7_part->code = job_7_part_0;
	_job_7_part->job_size = 4;
	_job_7_part->next = malloc(sizeof(Job_part));
	_job_7_part = _job_7_part->next;
	_job_7_part->code = job_7_part_1;
	_job_7_part->job_size = 4;
	_job_7_part->next = malloc(sizeof(Job_part));
	_job_7_part = _job_7_part->next;
	_job_7_part->code = job_7_part_2;
	_job_7_part->job_size = 4;
	_job_7_part->next = malloc(sizeof(Job_part));
	_job_7_part = _job_7_part->next;
	_job_7_part->code = job_7_part_3;
	_job_7_part->job_size = 4;
	_job_7_part->next = malloc(sizeof(Job_part));
	_job_7_part = _job_7_part->next;
	_job_7_part->code = job_7_part_4;
	_job_7_part->job_size = 4;
	_job_7_part->next = NULL;
	_tmp->jcb = _jcb_7;
	
	//作业8
	_tmp = _tmp->next;
	Jcb *_jcb_8 = malloc(sizeof(Jcb));	
	_jcb_8->identify = _JCB_ID;
	_jcb_8->username = "Mr.xi";
	_jcb_8->user_account = _JCB_ID++;
	_jcb_8->kind = 0; //普通
	_jcb_8->status = 0;//后备状态
	_jcb_8->prior = 0;//默认优先级
	_jcb_8->runtime = 0;//已经运行时间
	_jcb_8->request_time = 1500;//预计运行时间1500毫秒
	_jcb_8->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_8_part = malloc(sizeof(Job_part));
	_jcb_8->part = _job_8_part;//实际运行的代码部分
	_job_8_part->code = job_8_part_0;
	_job_8_part->job_size = 4;
	_job_8_part->next = malloc(sizeof(Job_part));
	_job_8_part = _job_8_part->next;
	_job_8_part->code = job_8_part_1;
	_job_8_part->job_size = 4;
	_job_8_part->next = malloc(sizeof(Job_part));
	_job_8_part = _job_8_part->next;
	_job_8_part->code = job_8_part_2;
	_job_8_part->job_size = 4;
	_job_8_part->next = malloc(sizeof(Job_part));
	_job_8_part = _job_8_part->next;
	_job_8_part->code = job_8_part_3;
	_job_8_part->job_size = 4;
	_job_8_part->next = malloc(sizeof(Job_part));
	_job_8_part = _job_8_part->next;
	_job_8_part->code = job_8_part_4;
	_job_8_part->job_size = 4;
	_job_8_part->next = NULL;
	_tmp->jcb = _jcb_8;
	
	//作业9
	_tmp = _tmp->next;
	Jcb *_jcb_9 = malloc(sizeof(Jcb));	
	_jcb_9->identify = _JCB_ID;
	_jcb_9->username = "Mr.e";
	_jcb_9->user_account = _JCB_ID++;
	_jcb_9->kind = 0; //普通
	_jcb_9->status = 0;//后备状态
	_jcb_9->prior = 0;//默认优先级
	_jcb_9->runtime = 0;//已经运行时间
	_jcb_9->request_time = 1500;//预计运行时间1500毫秒
	_jcb_9->request_memory = rand()%100+1;//要求内存大小
	
	Job_part *_job_9_part = malloc(sizeof(Job_part));
	_jcb_9->part = _job_9_part;//实际运行的代码部分
	_job_9_part->code = job_9_part_0;
	_job_9_part->job_size = 4;
	_job_9_part->next = malloc(sizeof(Job_part));
	_job_9_part = _job_9_part->next;
	_job_9_part->code = job_9_part_1;
	_job_9_part->job_size = 4;
	_job_9_part->next = malloc(sizeof(Job_part));
	_job_9_part = _job_9_part->next;
	_job_9_part->code = job_9_part_2;
	_job_9_part->job_size = 4;
	_job_9_part->next = malloc(sizeof(Job_part));
	_job_9_part = _job_9_part->next;
	_job_9_part->code = job_9_part_3;
	_job_9_part->job_size = 4;
	_job_9_part->next = malloc(sizeof(Job_part));
	_job_9_part = _job_9_part->next;
	_job_9_part->code = job_9_part_4;
	_job_9_part->job_size = 4;
	_job_9_part->next = NULL;
	_tmp->jcb = _jcb_9;
}

/*初始化后备队列(10个)
 */
void initial_reverse_queue() {
	int i = 0;
	//在后备队列初始化10个队列空间
	reserve_queue = malloc(sizeof(Reserve_queue));
	Reserve_queue *tmp = reserve_queue;
	tmp->jcb = NULL;
	for( i = 0; i < 9; i++ ) {
		tmp->next = malloc(sizeof(Reserve_queue));
		tmp->next->jcb = NULL;
		tmp = tmp->next;
	}
	tmp->next = NULL;
}

/*显示后背队列当前是否有作业
 */
int show_reserve_jcb_info() {
	Reserve_queue *_tmp = reserve_queue;
	int i = 1;
	printf("\n");
	while(_tmp != NULL ) {
		//如果在内存中找到作业
		if( _tmp->jcb != NULL  ) {
			printf("%d:有作业 ",i++);
		} else {
			printf("%d:无作业 ",i++);
		}
		_tmp=_tmp->next;
	}
	printf("\n");
}
 
/*检查后背队列是否还有作业
 */
int check_reverse_queue() {
	Reserve_queue *_tmp = reserve_queue;
	while( _tmp != NULL ) {
		if( _tmp->jcb != NULL )
			return 1;
		_tmp = _tmp->next;
	}
	return 0;
}
 
/*从后备队列弹出一个作业
 */
Jcb *pop_reserve_jcb( void ){
	//保存jcb用于返回
	Jcb *_tmp = NULL;
	
	Reserve_queue *_find = reserve_queue;
	//找到第一个jcb不为空的节点
	while( _find != NULL ) {
		
		if( _find->jcb != NULL ) {
			_tmp = _find->jcb;
			_find->jcb = NULL;
			break;
		}
		_find = _find->next;
	}

	return _tmp;			//返回NULL表示后备队列已没有作业
}

/*将一个作业推进后备队列
 */
int push_reserve_jcb( Jcb *_jcb ) {	//没有涉及算法(先来先服务...)
	
	Reserve_queue *_find = reserve_queue;
	//找到第一个jcb不为空的节点
	while( _find != NULL ) {
		
		if( _find->jcb == NULL ) {
			//将jcb放入节点
			_find->jcb = _jcb;
			return 0;
		}
		_find = _find->next;
	}
}

/*高级调度
 */
int high_level_scheduling() {
	//push_job(reserve_queue->jcb);
}

/*作业调度测试
 */
int test(void) {
	initial_reverse_queue();		//初始化
	create_job_default();
	//high_level_scheduling();
}

/*执行后背队列
 */
int test_run_reserve(void) {
	Reserve_queue *_tmp = reserve_queue;
	Job_part *_tmp_part;
	while(_tmp != NULL ) {
		//如果在内存中找到作业  执行
		if( _tmp->jcb != NULL  ) {
			_tmp_part = _tmp->jcb->part;
			while( _tmp_part != NULL ) {
				_tmp_part->code();
				_tmp_part = _tmp_part->next;
			}
		}
		_tmp=_tmp->next;
	}
}

int control_pause = 0; //控制运行0,暂停1,退出2

/*作业执行测试
 */
int test_run(void) {
	int n = 0;
	Store_job *_tmp = store_job;
	Job_part *_tmp_part;
	while(_tmp != NULL ) {
		//如果在内存中找到作业  执行
		if( _tmp->jcb != NULL  ) {
			_tmp_part = _tmp->jcb->part;
			while( _tmp_part != NULL ) {
				if( kbhit() != 0 ) {
					if( (control_pause = getch()) == '4' )
						control_pause = 1;
				}
				if( control_pause == 1 ) {
					control_pause = 0;
					return 0;
				}
				_tmp_part->code();
				_tmp_part = _tmp_part->next;
			}
		}
		_tmp=_tmp->next;
	}
}


/*更新jcb信息(等待时间...)
 */
int update() {
	current_time++;
	
	Store_job *_tmp = store_job;
	
	while( _tmp != NULL ) {
		if( _tmp->jcb != NULL ) {
			_tmp->jcb->runtime += current_time;
		}
		_tmp = _tmp->next;
	}
}

/*执行作业
 */
int run(void) {
	int _run_return = 0;
	
	Jcb *_jcb = NULL;
	
	initial_track();
	//showall();
	while( check_reverse_queue() || (check_store_job()>0) ) {
		if( check_store_job()<track_number && check_reverse_queue() ) {
			_jcb = push_job(pop_reserve_jcb());	//将后备队列作业压入内存
			_jcb->status = 1;
			push_into_track(_jcb);
		}
		show_track();
		show_current_jcb_info();
		show_current_track();
		_run_return = run_track(store_mode);
		update();
		reflesh_info();
		
		if( _run_return == 0 ) {		//执行完成
			
		} else if( _run_return == 1 ) {	//未执未完成
			//继续执行
		} else if( _run_return == 2 ) {	//道中已没有作业
			return 0;//所有作业执行完毕  返回
		}
		if( control_pause == 1 )
			return 0;
	}
}

int step_use_state = 0;
int empty = 0;
/*单步执行作业
 */
int run_step(void) {
	int _run_return = 0;
	
	Jcb *_jcb = NULL;
	
	if( step_use_state == 0 ) {
		initial_track();
		step_use_state = 1;
	}
	
	if( empty == 1 )
		return 0;
	//showall();
	if( check_reverse_queue() || (check_store_job()>0) ) {
		if( check_store_job()<track_number && check_reverse_queue() ) {
			_jcb = push_job(pop_reserve_jcb());	//将后备队列作业压入内存
			_jcb->status = 1;
			push_into_track(_jcb);
		}
		show_track();
		show_current_jcb_info();
		show_current_track();
		_run_return = run_track(store_mode);
		update();
		reflesh_info();

		if( _run_return == 0 ) {		//执行完成

		} else if( _run_return == 1 ) {	//未执未完成
			//继续执行
		} else if( _run_return == 2 ) {	//道中已没有作业
			show_track();
			empty = 1;//所有作业执行完毕  返回
		}
	}
}