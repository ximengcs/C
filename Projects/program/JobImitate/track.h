#pragma  once
#include "job.h"
#include "simon.h"
//道
typedef struct TRACK {
	Jcb *jcb;
	Job_part *current_part;
	int number;
	struct TRACK *next;
}Track;

Track *track;

Track *current;	//当前执行处

//获取当前执行的作业指针
Jcb *get_current_jcb() {
	return current->jcb;
}

//获取当前执行的道数
int get_current_num() {
	return current->number;
}

//检查道中有无空闲
int check_track() {
	int i = 0;
	Track *_tmp = track;
	for( i = 0; i < track_number; i++ ){
		if( _tmp->jcb == NULL )
			return 1;
		_tmp = _tmp->next;
	}
	return 0;
}

//初始化
int initial_track( void ) {
	int _num = 1;
	
	track = malloc(sizeof(Track));
	track->jcb = NULL;
	track->current_part = NULL;
	track->number = _num++;
	track->next = NULL;

	int i;
	Track *_current = track;
	for( i = 1; i < track_number; i++ ) {
		_current->next = malloc(sizeof(Track));
		_current->next->jcb = NULL;
		_current->next->current_part = NULL;
		_current->next->next = NULL;
		_current->next->number = _num++;
		_current = _current->next;
	}
	
	_current->next = track;
	current = track;
}

//加入作业
//0:道中作业已满
//1:加入成功
int push_into_track(Jcb *_jcb) {
	int sucess = 1;
	Track *_track = track;
	int i = 0;
	for( i = 0; i < track_number; i++ ) {
		if( _track->jcb == NULL ) {
			_track->jcb = _jcb;
			_track->current_part = _jcb->part;
			return 0;
		}
		_track = _track->next;
	}
	return sucess;
}

//执行当前作业的一部分
//返回0表示执行完成  可以销毁作业
//返回1表示未执行完成
//返回2表示没有作业可执行
int run_track(int mode) {
	int count = 0;
	
	setpos(65,5);
	current->current_part->code(); //执行当前代码
	setpos(0,33);
	
	current->current_part = current->current_part->next;//指向下一代码
	if( current->current_part == NULL ) {	//如果当前作业代码执行完毕
		show_current_track_finish();
		Sleep(500);
		if( mode == 3 )
			free_finished_job_dynamic(current->jcb);	//释放jcb空间
		else
			free_finished_job_static(current->jcb);
		
		current->jcb = NULL;	//将当前指针改为NULL
		while( current->jcb == NULL ) {

			current = current->next;	//指向下一道
			if( current->jcb != NULL ) {
				current->current_part = current->jcb->part;
				return 0;
			}
			count++;
			if( count > track_number )
				return 2;
		}
	} else {	//如果当前代码没有执行完  将指针指向下一道
		do {
			current = current->next;
		} while( current->jcb == NULL );
	}
	return 1;
}