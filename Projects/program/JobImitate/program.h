#pragma  once
#define PROGRAM_QUEUE_LENGTH 50
#define STATIC_READY_LENGTH 10
#define STATIC_BLOCK_LENGTH 10

#include <time.h>
#include "process.h"
#include "program_0.h"
#include "program_1.h"
#include "program_2.h"
#include "program_3.h"

typedef struct{
	int part_length;
	
	int part_size[10];
	
	int (*part[10])(void);
}Program;

typedef struct Pro_queue{
	Program program;
	struct Pro_queue *next;
}Program_queue;

//外存
Program_queue *program_queue;  //程序集合
Program_queue *program_head;  //队头
Program_queue *program_tail;  //队尾

/*静止就绪队列
 */
Process static_readyQueue[STATIC_READY_LENGTH];

/*静止阻塞队列
 */
Process static_blockQueue[STATIC_BLOCK_LENGTH];

void initial_program() {
	
	program_head = (Program_queue *)malloc(sizeof(Program_queue));
	
	program_tail = program_head;
	
	//初始化程序0
	program_tail->program = *(Program *)malloc(sizeof(Program));
	program_tail->program.part_length = 3;
	program_tail->program.part_size[0] = rand()%10;
	program_tail->program.part[0] = program_0_part_0;
	program_tail->program.part_size[1] = rand()%10;
	program_tail->program.part[1] = program_0_part_1;
	program_tail->program.part_size[2] = rand()%10;
	program_tail->program.part[2] = program_0_part_2;
	
	program_tail->next = (Program_queue *)malloc(sizeof(Program_queue));
	program_tail = program_tail->next;
	
	program_tail->program = *(Program *)malloc(sizeof(Program));
	program_tail->program.part_length = 6;
	program_tail->program.part_size[0] = rand()%10;
	program_tail->program.part[0] = program_1_part_0;
	program_tail->program.part_size[1] = rand()%10;
	program_tail->program.part[1] = program_1_part_1;
	program_tail->program.part_size[2] = rand()%10;
	program_tail->program.part[2] = program_1_part_2;
	program_tail->program.part_size[3] = rand()%10;
	program_tail->program.part[3] = program_1_part_3;
	program_tail->program.part_size[4] = rand()%10;
	program_tail->program.part[4] = program_1_part_4;
	program_tail->program.part_size[5] = rand()%10;
	program_tail->program.part[5] = program_1_part_5;
	
	program_tail->next = (Program_queue *)malloc(sizeof(Program_queue));
	program_tail = program_tail->next;
	program_tail->program = *(Program *)malloc(sizeof(Program));
	program_tail->program.part_length = 1;
	program_tail->program.part_size[0] = rand()%10;
	program_tail->program.part[0] = program_2_part_0;
}

Program_queue * getProcess() {
	Program_queue *tmp = program_head;
	program_head = program_head->next;
	return tmp;
}