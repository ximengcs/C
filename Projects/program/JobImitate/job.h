#pragma once
#include "job_part.h"
#include <stdlib.h>
#include "data.h"
#include "job_custom.h"

int _JCB_ID = 0;

/*作业控制块
 */
typedef struct JCB {
	int identify;   //作业标识
	char *username; //用户名称(作业所属)
	int user_account;//用户账号
	int kind;		//作业类型
	int status;		//作业状态
	
	//调度信息
	int prior;		//优先级
	int runtime;	//已经运行时间
	
	//资源需求
	int request_time;//预计运行时间
	int request_memory;//要求内存大小
	
	Job_part *part;//作业实际代码部分
}Jcb;

/*创建一个没有执行代码的作业
 */
Jcb *create_space(char *username) {
	Jcb *_jcb = malloc(sizeof(Jcb));
	_jcb->identify = _JCB_ID;
	_jcb->username = username;
	_jcb->user_account = _JCB_ID++;
	_jcb->kind = 0;
	_jcb->status = 0;
	_jcb->prior = 0;
	_jcb->runtime = 0;
	_jcb->request_time = 4;
	_jcb->request_memory = 16;
	_jcb->part = malloc(sizeof(Job_part));
	_jcb->part->code = job_part_0;
	_jcb->part->next = NULL;
	return _jcb;
}
