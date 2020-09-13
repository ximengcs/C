#pragma once

int KIND_NUM = 3;	//资源种类数

int PROCESS_NUM = 1;	//当前进程数目

int CURRENT_TIME = 0;	//当前时刻

int FLAG_PROCESS_TIME = 1; //为0表示随机生成运行时间[最大值:PROCESS_TIME]
						   //为1表示进程运行时间固定值[值:PROCESS_TIME]
int PROCESS_TIME = 1;

//资源结构体
typedef struct RESOURCE {
	char kind;	//资源类型
	int num;	//资源数目
	struct RESOURCE* next;	//下一资源指针
}Available,Work,Max,Allocation,Need;

Available *available;	//系统资源总数

typedef struct SAFE {
	int id;//进程id
}Safe;
	struct SAFE *next;

Safe *safe;	//安全序列