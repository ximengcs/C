#pragma once
#include <stdio.h>
#include "simon.h"
#include "data.h"
#include "process.h"
#include "manager.h"
#include "simon.h"
//测试
int pos(void) {
	setpos(0,24);
}

//输入input
int show_input_require(void) {
	setcolor(14,8);
	setpos(0,23);printf("输入进程id、新请求的各资源数量:");
	set_default_color();
}

//输入available
int input_available(void) {
	setcolor(14,8);
	setpos(0,23);printf("输入available:");
	set_default_color();
}

//输入资源种类
int input_kind(void) {
	setcolor(14,8);
	setpos(0,23);printf("输入资源种类个数:");
	set_default_color();
}

//输入进程
int input_process_info(void) {
	setcolor(14,8);
	setpos(0,23);printf("输入进程的Max、Allocation(用空格隔开):");
	set_default_color();
}

//清除输入行
int reflesh_input(void) {
	setpos(0,23);printf("%98s","");
}

//设置为默认颜色
int set_default_color(void) {
	setcolor(7,0);
}

//设置选中颜色
int set_choice_color(void) {
	setcolor(0,11);
}

//刷新显示空白
int reflesh_space(int last_num) {
	int i;
	for( i = last_num; i < 18; i++ ) {
		setpos(2,i);
		printf("%-20s"," ");
	}
}

//显示1-6菜单
int show_menu_6(int count) {
	if( count == 1 )
		set_choice_color();
	setpos(2,1);printf("%s","更改资源种类:");printf("%-7d",KIND_NUM);
	set_default_color();
	if( count == 2 )
		set_choice_color();
	setpos(2,2);printf("%-20s","更改available");
	set_default_color();
	if( count == 3 )
		set_choice_color();
	setpos(2,3);printf("%-20s","返回    ");
	set_default_color();
	reflesh_space(4);
}

//显示1-2菜单
int show_menu_1_2(int count) {
	if( count == 1 )
		set_choice_color();
	setpos(2,1);printf("%-20s","手动输入");
	set_default_color();
	if( count == 2 )
		set_choice_color();
	setpos(2,2);printf("%-20s","随机生成一个");
	set_default_color();
	if( count == 3 )
		set_choice_color();
	setpos(2,3);printf("%-20s","随机生成十个");
	set_default_color();
	if( count == 4 )
		set_choice_color();
	setpos(2,4);printf("%-20s","返回    ");
	set_default_color();
	reflesh_space(5);
}

//显示菜单
int show_menu_1(int count) {
	if( count == 1 )
		set_choice_color();
	setpos(2,1);printf("%-20s","创建进程");
	set_default_color();
	if( count == 2 )
		set_choice_color();
	setpos(2,2);printf("%-20s","撤销进程");
	set_default_color();
	if( count == 3 )
		set_choice_color();
	setpos(2,3);printf("%-20s","执行进程");
	set_default_color();
	if( count == 4 )
		set_choice_color();
	setpos(2,4);printf("%-20s","进程请求");
	set_default_color();
	if( count == 5 )
		set_choice_color();
	setpos(2,5);printf("%-20s","撤销请求");
	set_default_color();
	if( count == 6 )
		set_choice_color();
	setpos(2,6);printf("%-20s","课本例题");
	set_default_color();
	if( count == 7 )
		set_choice_color();
	setpos(2,7);printf("%-20s","设置");
	set_default_color();
	if( count == 8 )
		set_choice_color();
	setpos(2,8);printf("%-20s","退出");
	set_default_color();
	reflesh_space(9);
}

int resource_gage = 1;//资源显示页码
int work_page = 1;//进程显示页码
int process_page = 1;//进程显示页码
int safe_order_page = 1;//安全序列显示页码

//刷新页码:刷新以上四个页码
int reflesh_page(void) {
	if( ((resource_gage-1)*3) >= KIND_NUM ) {
		if( KIND_NUM > 3 )
			resource_gage--;
		else
			resource_gage = 1;
	}
	if( ((work_page-1)*5) >= PROCESS_NUM ) {
		if( PROCESS_NUM > 5 )
			work_page--;
		else
			work_page = 1;
	}
	if( ((process_page-1)*5) >= PROCESS_NUM ) {
		if( PROCESS_NUM > 5 )
			process_page--;
		else
			process_page = 1;
	}
	if( ((safe_order_page-1)*10) >= PROCESS_NUM ) {
		if( PROCESS_NUM > 10 )
			safe_order_page--;
		else
			safe_order_page = 1;
	}
}

//显示安全序列
int show_safe_order(void) {
	if( !check_safe_sate() ) {
		setpos(24,11);printf("%-76s","");
		setpos(24,11);setcolor(13,0);printf(" 系统处于不安全状态!");set_default_color();
		return 0;
	}
	
	Safe *_safe = safe;
	setpos(24,11);printf("%-76s","");
	if(_safe->id==-1)
		return 0;
	setpos(24,11);setcolor(14,0);printf(" T%d时刻",CURRENT_TIME);set_default_color();printf("安全序列:");
	
	int count = 0;
	int start_show = 0;
	while(_safe!=NULL) {
		if( (start_show >= ((safe_order_page-1)*10)) && count < 10 ) {
			printf("P%d",_safe->id);
			_safe = _safe->next;
			if( _safe!=NULL && count < 9 )
				printf("、");
			count++;
		}else
			_safe = _safe->next;
		start_show++;
	}
}

//显示安全序列时各个进程的信息 work allcation need allcation+work
int show_safe_process_info_test(void) {
	int i = 17,j = 36; //i:行坐标 j:列
	
	Process *_process = process;
	Max *_max = NULL;
	Allocation *_allocation = NULL;
	Need *_need = NULL;
	Work *_work = NULL;
	int _start_show_process = (work_page-1)*5;
	int _start_show_resource = (resource_gage-1)*3;
	int count_process_page = 0;
	int count_resource_page = 0;
	int _process_i = 0;
			
	while(_process!=NULL) {
		
		if( (_process_i >= _start_show_process) && (count_process_page<5) ) {//起始显示ID
			
			count_resource_page = 0;
			j = 37;
			_need = _process->need;//临时变量need
			_work = _process->work;//临时变量work
			_allocation = _process->allocation;//临时变量allocation
			while(_need!=NULL && count_resource_page<3) {
				setpos(28,i);printf("P%-3d",_process->id);
				setpos(j,15);printf("%-3c",_need->kind);
				setpos(j+14,15);printf("%-3c",_need->kind);
				setpos(j+28,15);printf("%-3c",_need->kind);
				setpos(j+42,15);printf("%-3c",_need->kind);
				if((_need->kind-65) >= _start_show_resource) {//如果到达当前资源显示页码
	
					setpos(j,i);printf("%-3d",_work->num);//work
					
					setpos(j+14,i);printf("%-3d",_need->num);//need
					
					setpos(j+28,i);printf("%-3d",_allocation->num);//allocation
					
					if( _process->finish == true ) {
						setpos(j+42,i);printf("%-3d",_allocation->num + _work->num);//allocation+work
					} else {
						setpos(j+42,i);printf("%-3d",0);
					}
	
					count_resource_page++;
					j += 4;
				}
				
				_work = _work->next;
				_allocation = _allocation->next;
				_need = _need->next;
			}
			
			setpos(93,i);printf("%-5s",_process->finish?"true":"false");//finish
			
			while(count_resource_page<3) {
				setpos(j,15);printf("%-3s","");
				setpos(j+14,15);printf("%-3s","");
				setpos(j+28,15);printf("%-3s","");
				setpos(j+42,15);printf("%-3s","");
				setpos(j,i);printf("%-3s","");//work
					
				setpos(j+14,i);printf("%-3s","");//need
					
				setpos(j+28,i);printf("%-3s","");//allocation
					
				setpos(j+42,i);printf("%-3s","");//allocation+work
				count_resource_page++;
				j += 4;
			}
			
			count_process_page++;
			i++;
		}
		_process_i++;
		_process = _process->next;
	}
	
			
	while( count_process_page<5 ) {
		count_resource_page = 0;
		j = 36;
		while( count_resource_page < 3 ) {
			setpos(28,i);printf("%-3s","");
			
			setpos(j,i);printf("%-4s","");//work
					
			setpos(j+14,i);printf("%-3s","");//need
			
			setpos(j+28,i);printf("%-3s","");//allocation
			
			setpos(j+42,i);printf("%-4s","");//allocation+work
			
			setpos(93,i);printf("%-5s","");//finish
			
			count_resource_page++;
			
			j += 4;
		}
		count_process_page++;
		i++;	
	}
}

//显示安全序列时各个进程的信息 work allcation need allcation+work
int show_safe_process_info(void) {
	int i = 17,j = 36; //i:行坐标 j:列
	
	Process *_process = process;
	Max *_max = NULL;
	Allocation *_allocation = NULL;
	Need *_need = NULL;
	Work *_work = NULL;
	int _start_show_process = (work_page-1)*5;
	int _start_show_resource = (resource_gage-1)*3;
	int count_process_page = 0;
	int count_resource_page = 0;
	int _process_i = 0;
	
	
	Safe *_safe = safe;
	while( count_process_page < 5 ) {
		_process = process;
		if( _process_i >= _start_show_process ) {
			while(_process!=NULL) {
				if( _safe->id == _process->id ) {
					count_resource_page = 0;
					j = 37;
					_need = _process->need;//临时变量need
					_work = _process->work;//临时变量work
					_allocation = _process->allocation;//临时变量allocation
					while(_need!=NULL && count_resource_page<3) {
						setpos(28,i);printf("P%-3d",_process->id);
						setpos(j,15);printf("%-3c",_need->kind);
						setpos(j+14,15);printf("%-3c",_need->kind);
						setpos(j+28,15);printf("%-3c",_need->kind);
						setpos(j+42,15);printf("%-3c",_need->kind);
						if((_need->kind-65) >= _start_show_resource) {//如果到达当前资源显示页码
			
							setpos(j,i);printf("%-3d",_work->num);//work
							
							setpos(j+14,i);printf("%-3d",_need->num);//need
							
							setpos(j+28,i);printf("%-3d",_allocation->num);//allocation
							
							if( _process->finish == true ) {
								setpos(j+42,i);printf("%-3d",_allocation->num + _work->num);//allocation+work
							} else {
								setpos(j+42,i);printf("%-3d",0);
							}
			
							count_resource_page++;
							j += 4;
						}
						
						_work = _work->next;
						_allocation = _allocation->next;
						_need = _need->next;
					}
					
					setpos(93,i);printf("%-5s",_process->finish?"true":"false");//finish
					
					while(count_resource_page<3) {
						setpos(j,15);printf("%-3s","");
						setpos(j+14,15);printf("%-3s","");
						setpos(j+28,15);printf("%-3s","");
						setpos(j+42,15);printf("%-3s","");
						setpos(j,i);printf("%-3s","");//work
							
						setpos(j+14,i);printf("%-3s","");//need
							
						setpos(j+28,i);printf("%-3s","");//allocation
							
						setpos(j+42,i);printf("%-3s","");//allocation+work
						count_resource_page++;
						j += 4;
					}
					
					count_process_page++;
					i++;
					break;
				}
				_process = _process->next;
			}
		}
		_process_i++;
		if( _safe->next == NULL )
			break;
		_safe = _safe->next;
		if( _safe->id == -1 )
			break;
	}
			
	while( count_process_page<5 ) {
		count_resource_page = 0;
		j = 36;
		while( count_resource_page < 3 ) {
			setpos(28,i);printf("%-3s","");
			
			setpos(j,i);printf("%-4s","");//work
					
			setpos(j+14,i);printf("%-3s","");//need
			
			setpos(j+28,i);printf("%-3s","");//allocation
			
			setpos(j+42,i);printf("%-4s","");//allocation+work
			
			setpos(93,i);printf("%-5s","");//finish
			
			count_resource_page++;
			
			j += 4;
		}
		count_process_page++;
		i++;	
	}
}

//显示T时刻各进程的max allocation need
int show_time(void) {
	int i = 5,j = 36; //i:行坐标 j:列
	
	Process *_process = process;
	Max *_max = NULL;
	Allocation *_allocation = NULL;
	Need *_need = NULL;
	Available *_available = NULL;
	int _start_show_process = (process_page-1)*5;
	int _start_show_resource = (resource_gage-1)*3;
	
	int count_process_page = 0;
	int count_resource_page = 0;
	
	int _prcess_i = 0;

	while(_process!=NULL) {
		if( (_prcess_i >= _start_show_process) && (count_process_page<5) ) {//起始显示ID
			
			count_resource_page = 0;
			j = 37;
			_need = _process->need;//临时变量need
			_max = _process->max;//临时变量max
			_allocation = _process->allocation;//临时变量allocation
			_available = available;
			while(_max!=NULL && count_resource_page<3) {
				setpos(28,i);printf("P%-3d",_process->id);
				setpos(j,3);printf("%-3c",_max->kind);
				setpos(j+14,3);printf("%-3c",_max->kind);
				setpos(j+28,3);printf("%-3c",_max->kind);
				setpos(j+42,3);printf("%-3c",_max->kind);
				if((_max->kind-65) >= _start_show_resource) {//如果到达当前资源显示页码

					setpos(j,i);printf("%-3d",_max->num);//max
					
					setpos(j+14,i);printf("%-3d",_allocation->num);//allocation
					
					setpos(j+28,i);printf("%-3d",_need->num);//need
					
					setpos(j+42,5);printf("%-3d",_available->num);//available
					
					count_resource_page++;
					j += 4;
				}
				
				_available = _available->next;
				_allocation = _allocation->next;
				_need = _need->next;
				_max = _max->next;
			}
			while(count_resource_page<3) {
				setpos(j,3);printf("%-3s","");
				setpos(j+14,3);printf("%-3s","");
				setpos(j+28,3);printf("%-3s","");
				setpos(j+42,3);printf("%-3s","");
				setpos(j,i);printf("%-3s","");//work ABC
					
				setpos(j+14,i);printf("%-3s","");//need ABC
					
				setpos(j+28,i);printf("%-3s","");//allocation ABC
					
				setpos(j+42,i);printf("%-3s","");//available ABC
				count_resource_page++;
				j += 4;
			}
			
			count_process_page++;
			i++;
		}
		_prcess_i++;
		_process = _process->next;
	}
	
	while( count_process_page<5 ) {
		count_resource_page = 0;
		j = 36;
		while( count_resource_page < 3 ) {
			setpos(28,i);printf("%-3s","");
			
			setpos(j,i);printf("%-4s","");//work
					
			setpos(j+14,i);printf("%-3s","");//allocation
			
			setpos(j+28,i);printf("%-3s","");//need
			
			setpos(j+42,i);printf("%-4s","");//available
			
			count_resource_page++;
			
			j += 4;
		}
		count_process_page++;
		i++;	
	}
}

//显示主框架
int show_frame(void) {
	int i,j;
	for( i = 0; i < 23; i++ ) {
		for( j = 0; j < 50; j++ ) {
			if( j == 0 || (i == 0&&j<11) || (i == 22&&j<11) || j == 11)
				printf("■");
			else if( (i == 0 || i== 2 || i == 4 || i == 10 || i == 12 || i == 14 || i == 16 || i == 22) && j > 11) {
				printf("━");
			} else if( (j == 45 || j == 38 || j == 31 || j == 24 || j == 17 || j == 12 || j == 49) && i != 11 ) {
				printf("┃");
			} else
				printf("  ");
		}
	}

	setpos(24,0);printf("┏");
	setpos(24,12);printf("┏");
	setpos(24,10);printf("┗");
	setpos(24,22);printf("┗");
	setpos(98,0);printf("┓");
	setpos(98,12);printf("┓");
	setpos(98,10);printf("┛");
	setpos(98,22);printf("┛");
	
	setpos(24,2);printf("┣");
	setpos(24,4);printf("┣");
	
	setpos(24,14);printf("┣");
	setpos(24,16);printf("┣");
	
	setpos(98,2);printf("┫");
	setpos(98,4);printf("┫");
	
	setpos(98,14);printf("┫");
	setpos(98,16);printf("┫");
	
	setpos(34,0);printf("┳");
	setpos(48,0);printf("┳");
	setpos(62,0);printf("┳");
	setpos(76,0);printf("┳");
	setpos(90,0);printf("┳");
	
	setpos(34,2);printf("╋");
	setpos(48,2);printf("╋");
	setpos(62,2);printf("╋");
	setpos(76,2);printf("╋");
	setpos(90,2);printf("╋");
	
	setpos(34,4);printf("╋");
	setpos(48,4);printf("╋");
	setpos(62,4);printf("╋");
	setpos(76,4);printf("╋");
	setpos(90,4);printf("╋");
	
	setpos(34,12);printf("┳");
	setpos(48,12);printf("┳");
	setpos(62,12);printf("┳");
	setpos(76,12);printf("┳");
	setpos(90,12);printf("┳");
	
	setpos(34,14);printf("╋");
	setpos(48,14);printf("╋");
	setpos(62,14);printf("╋");
	setpos(76,14);printf("╋");
	setpos(90,14);printf("╋");
	
	setpos(34,16);printf("╋");
	setpos(48,16);printf("╋");
	setpos(62,16);printf("╋");
	setpos(76,16);printf("╋");
	setpos(90,16);printf("╋");
	
	setpos(34,0);printf("┳");
	setpos(48,0);printf("┳");
	setpos(62,0);printf("┳");
	setpos(76,0);printf("┳");
	setpos(90,0);printf("┳");
	
	setpos(34,2);printf("╋");
	setpos(48,2);printf("╋");
	setpos(62,2);printf("╋");
	setpos(76,2);printf("╋");
	setpos(90,2);printf("╋");

	setpos(34,10);printf("┻");
	setpos(48,10);printf("┻");
	setpos(62,10);printf("┻");
	setpos(76,10);printf("┻");
	setpos(90,10);printf("┻");
	
	setpos(34,22);printf("┻");
	setpos(48,22);printf("┻");
	setpos(62,22);printf("┻");
	setpos(76,22);printf("┻");
	setpos(90,22);printf("┻");
	
	setcolor(10,0);
	setpos(40,1);printf("Max");
	setpos(51,1);printf("Allocation");
	setpos(68,1);printf("Need");
	setpos(79,1);printf("Available");
	setpos(28,3);printf("进程");
	setpos(40,13);printf("Work");
	setpos(53,13);printf("Need");
	setpos(65,13);printf("Allocation");
	setpos(80,13);printf("AL+Work");
	setpos(90,14);set_default_color();printf("┫");setcolor(10,0);printf("Finish");set_default_color();printf("┃");setcolor(10,0);
	setpos(28,15);printf("进程");
	set_default_color();
	setpos(90,0);printf("┓　　　　");
	setpos(90,1);printf("┃　　　　");
	setpos(90,2);printf("┫　　　　");
	setpos(90,3);printf("┃　　　　");
	setpos(90,4);printf("┫　　　　");
	setpos(90,5);printf("┃　　　　");
	setpos(90,6);printf("┃　　　　");
	setpos(90,7);printf("┃　　　　");
	setpos(90,8);printf("┃　　　　");
	setpos(90,9);printf("┃　　　　");
	setpos(90,10);printf("┛　　　　");
}