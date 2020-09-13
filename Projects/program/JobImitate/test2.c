#include <time.h>
#include <stdio.h>
#include <time.h>
#include "processor_manager.h"
#include "job.h"
#include "job_part.h"
#include "view.h"
#include "track.h"
int main( void ) {
	initial_reverse_queue();
	push_reserve_jcb(create_space("ximeng"));
	initial_store(3,1);
	int _run_return = 0;
	
	Jcb *_jcb = NULL;
	
	Reserve_queue *_re_tmp = reserve_queue;
	while( _re_tmp != NULL ) {
		if( _re_tmp->jcb!=NULL ) {
			printf("[%d]",_re_tmp->jcb->identify);
		}
		_re_tmp = _re_tmp->next;
	}
	initial_track();
	if( check_reverse_queue() || (check_store_job>0) ) {
		if( check_store_job()<track_number && check_reverse_queue() ) {
			_jcb = push_job(pop_reserve_jcb());	//将后备队列作业压入内存
			_jcb->status = 1;
			push_into_track(_jcb);
		}
		printf("(%d)",_run_return = run_track(store_mode));
	}
	Track *_track;
	printf("%s",get_current_jcb()==NULL?"NULL":"have");
	printf("%d",get_current_num());
	
	return 0;
}