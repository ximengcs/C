#pragma  once
#define JOB_0_SIZE 3
#include <windows.h>

//分成多个进程
int job_0_part_0() {
	Sleep(500);
	printf("作业0运行33%%...");
}

int job_0_part_1() {
	Sleep(500);
	printf("作业0运行66%%...");
}

int job_0_part_2() {
	Sleep(500);
	printf("作业0运行100%%...");
}