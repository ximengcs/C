#pragma once
#include "job.h"
typedef struct JOB_PART{
	int (*code)(void);	//代码块
	int job_size;		//单部分大小
	
	struct JOB_PART *next; //作业下一代码块
}Job_part;
