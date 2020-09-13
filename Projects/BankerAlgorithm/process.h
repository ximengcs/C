#pragma once
#include "data.h"
#include <stdbool.h>

typedef struct PROCESS {
	int id;//进程id
	int request_time;//需要运行时间
	Work *work;
	Max *max;
	Allocation *allocation;
	Need *need;
	bool finish;
	struct PROCESS *next;//后向指针
	struct PROCESS *pre; //前向指针
}Process;

Process *process;	//进程队列