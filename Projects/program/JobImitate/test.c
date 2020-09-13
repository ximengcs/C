#include <stdio.h>
#include "job.h"
#include "store.h"
#include "dynamic.h"
#include "processor_manager.h"
#include "view.h"
#include "track.h"
void test_free_description();
int test_store_info();
void test_all_description();
void show_reverse_store();
void showall();
void show_track_info_();
int main(void) {
	//test();	//初始化后背队列
	
	initial_store(3,16); //初始化动态分配
	
	initial_track();
	Jcb *_jcb;
	int _run_return;
	initial_reverse_queue();//初始化后备队列
	create_job_default();	//创建默认作业
	run();
	while( check_reverse_queue() || (check_store_job>0) ) {
		
		if( check_store_job()<4 && check_reverse_queue() ) {
			_jcb = push_job(pop_reserve_jcb());	//将后备队列作业压入内存
			push_into_track(_jcb);
		}
		printf("reach");
		_run_return = run_track(3);
		printf("%d",_run_return);
		if( _run_return == 0 ) {		//执行完成
			
		} else if( _run_return == 1 ) {	//未执未完成
			//继续执行
		} else if( _run_return == 2 ) {	//道中已没有作业
			return 0;//所有作业执行完毕  返回
		}
		show_track_info_();
	}
	
	
	
	return 0;
}

void show_track_info_() {
	Track *_track = track;
	
	int i = 0;
	printf("\ncurrent:%d",_track->jcb!=NULL?_track->jcb->identify:99);
	while( i < 4 ) {
		printf(" %d ",_track->jcb!=NULL?_track->jcb->identify:99);
		_track = _track->next;
		i++;
	}
	printf("\n");
}

void show_reverse_store() {
	printf("reverse\n");
	Store_job *_tmp = store_job;
	while(_tmp->next!=NULL) {
		_tmp = _tmp->next;
	}
	//找到尾指针
	while(_tmp!=NULL) {
		if( _tmp->jcb != NULL ) {
			printf(" %-14d作业%-d\n",_tmp->start_address,_tmp->jcb->identify);
		} else {
			printf("%-8d%　　　　NULL\n",_tmp->start_address);
		}
		_tmp = _tmp->pre;
	}
}

void showall() {
	show_reserve_jcb_info();	//显示后备队列作业情况
	
	printf("\n");
	test_all_description();		//显示所有描述信息
	printf("\n");
	test_free_description();	//显示空闲表
	
	printf("\n");
	
	test_store_info();			//显示内存情况
	printf("\n");
}

/*显示分区描述表所有信息
 */
void test_all_description() {
	printf("\n分区号　大小　起址　状态\n");
	Final_partition_description *tmp = final_partition_description;
	while( tmp!=NULL ) {
		//显示
		printf(" %-7d%-5d%-4d%s\n",
		tmp->partition_number,tmp->partition_size,tmp->partition_start_address,tmp->partition_state==0?"空闲":"分配");
		tmp = tmp->next;
	}
}


/*显示空闲表信息
 */
void test_free_description() {
	
	Final_partition_description *tmp = final_partition_description;
	printf("\n分区号　大小　起址　状态\n");
	while( tmp!=NULL ) {
		//如果空闲则显示
		if( tmp->partition_state == 0 ) {
			printf(" %-7d%-5d%-4d%s\n",
			tmp->partition_number,tmp->partition_size,tmp->partition_start_address,"空闲");
		}
		tmp = tmp->next;
	}
}

/*显示内存
 */
int test_store_info() {
	Store_job *tmp = store_job;
	int last_show_store = 1;
	printf("起始地址　　　　内容　　　　\n");
	
	while( tmp!=NULL && last_show_store <= 30 ) {
		if( tmp->jcb != NULL ) {
			printf(" %-14d作业%-d\n",tmp->start_address,tmp->jcb->identify);
		} else {
			printf("%-8d%　　　　NULL\n",tmp->start_address);
		}
		tmp = tmp->next;
		last_show_store++;
	}
}