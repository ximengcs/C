#pragma once
#include <stdio.h>
#include "simon.h"
#include <stdlib.h>
#include "data.h"
#include "store.h"
#include "track.h"
#define HEIGHT 33
#define WIDTH  85

/*体现当前道数(完成态)
 */
int show_current_track_finish(void) {
	Jcb *_tmp = get_current_jcb();
	int num = get_current_num();
	setpos(76,11+(num-1)*2);
	setcolor(7,4);	
	printf("作业%d执行完毕..",_tmp!=NULL?_tmp->identify:0);
	setcolor(7,0);
	setpos(0,33);
}

/*体现当前道数(执行态)
 */
int show_current_track(void) {
	Jcb *_tmp = get_current_jcb();
	int num = get_current_num();
	setpos(76,11+(num-1)*2);
	setcolor(0,10);	
	if( current->jcb != NULL )
		printf("作业%d正在执行中",_tmp!=NULL?_tmp->identify:0);
	setcolor(7,0);
	setpos(0,33);
}

/*显示道中信息
 */
int show_track(void) {

	Track *_track = track;
	int i = 0;
	while( i < track_number ) {
		setpos(75,11+i*2);
		if( _track->jcb != NULL )
			printf("   ---作业%d---   ",_track->jcb->identify);
		else
			printf("   ----NULL---   ");
		i++;
		_track = _track->next;
	}
	setpos(0,33);
}
 
/*显示当前执行的作业信息
 */
int show_current_jcb_info(void) {
	Jcb *_jcb;
	if( (_jcb=get_current_jcb()) != NULL ) {
		setpos(46,11);
		printf("作业内部ID:%-d",_jcb->identify);                     setpos(46,12);
		printf("所属用户:%-9s",_jcb->username);                       setpos(46,13);
		printf("作业类型:%-9s",_jcb->kind==0?"普通":"系统");          setpos(46,14);
		printf("作业状态:%-9s",_jcb->status==0?"创建态":"运行态");    setpos(46,15);
		printf("作业优先级:%-d",_jcb->prior);                        setpos(46,16);
		printf("已经运行时间:%-d",_jcb->runtime);                    setpos(46,17);
		printf("预计运行时间:%-d",_jcb->request_time);               setpos(46,18);
		printf("要求内存大小:%-d",_jcb->request_memory);             setpos(46,19);
	}
	setpos(0,33);
}
 
/*当前系统信息
 */
int os_info(void) {
	setpos(24,1);
	printf("内存大小:%dM",memory_size);
	setpos(24,2);
	printf("道数:%d",track_number);
	setpos(24,3);
	
	printf("当前分配算法:");
	char *str_method;
	if( store_mode == 1 )
		str_method = "固定分配(大小相等)";
	else if( store_mode == 2 )
		str_method = "固定分配(大小不等)";
	else if( store_mode == 3 )
		if( current_method == 1 )
			str_method = "动态(首次适应)";
		else if( current_method == 2 ) {
			str_method = "动态(循环首次)";
			if( _previous != NULL ) {
				setpos(24,6);
				printf("上次指针分区号:%d",_previous->partition_number);
			}
		}
		else if( current_method == 3 )
			str_method = "动态(最佳适应)";
		else if( current_method == 4 )
			str_method = "动态(最坏适应)";
	setpos(24,4);
	printf("%s",str_method);
	
	setpos(24,5);
	printf("%-12s","当前内存占用:");
	Store_job *_tmp = store_job;
	int _memory_size = 0;
	while( _tmp != NULL ) {
		if( _tmp->jcb != NULL ) {
			_memory_size += _tmp->jcb->request_memory;
		}
		_tmp = _tmp->next;
	}
	
	printf("%2d%%",(int)(((float)_memory_size)/((float)memory_size) * 100) );
	
	setpos(0,33);
}

int clear_menu_show(void) {
	
	int i;
	for( i = 0; i < 10; i++ ) {
		setpos(2,i+1);
		setcolor(7,0);
		printf("　　　　　　　　　");
	}
	setpos(0,33);
	
}

/*清空输入区
 */
int clear_input_show(void) {
	setpos(0,33);
	printf("　　　　　　　　　　　　　　");
	setpos(0,33);
}

/*输入提示
 */
int input_show(char *str) {
	clear_input_show();
	setpos(0,33);
	printf(str);
}

/*显示主菜单
 */
int show_menu( void ) {
	clear_menu_show();
	
	int length = 5;
	char *menu_string[5] = {
		"分配方式",
		"调入作业",
		"开始执行",
		"设置多道",
		"退出"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示分配方式菜单
 */
int show_partition_menu(int mode) {
	clear_menu_show();
	int length = 4;
	char *menu_string[4] = {
		"固定(大小相等)",
		"固定(大小不等)",
		"动态分配",
		"返回"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示执行菜单
 */
int show_execute_menu(void) {
	clear_menu_show();
	int length = 4;
	char *menu_string[4] = {
		"自动执行",
		"单步执行",
		"暂停执行",
		"返回"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示动态分配方式菜单
 */
int show_dynamic_menu(void) {
	clear_menu_show();
	int length = 5;
	char *menu_string[5] = {
		"首次适应算法",
		"循环首次适应",
		"最佳适应算法",
		"最坏适应算法",
		"返回"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示固定分配大小相等菜单
 */
int show_final_partition_menu() {
	clear_menu_show();
	int length = 3;
	char *menu_string[3] = {
		"默认大小(128k)",
		"自定义大小",
		"返回"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示固定分配大小不等菜单
 */
int show_final_not_partition_menu() {
	clear_menu_show();
	int length = 2;
	char *menu_string[2] = {
		"确认",
		"取消"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*显示分区表信息(固定分区大小)
 */
void show_store() {
	Final_partition_description *tmp = final_partition_description;
	int last_show_store = 1;
	int _n = 2;
	while( tmp!=NULL && last_show_store <= 30 ) {
		setpos(114,_n);
		printf(" %-7d%-6d%-4d%6s\n",
		tmp->partition_number,tmp->partition_size,tmp->partition_start_address,tmp->partition_state==0?"未分配":"已分配");
		tmp = tmp->next;
		_n++;
		last_show_store++;
	}
	
	while( _n < 32 ) {
		setpos(140,_n);
		printf("%23s"," ");
		_n++;
	}
	
	setpos(0,33);
}

/*显示调入作业菜单
 */
void show_scheduling_job() {
	clear_menu_show();
	int length = 3;
	char *menu_string[3] = {
		"调入预设作业",
		"新建作业",
		"返回"
	};
	
	int i;
	char *str;
	for( i = 0; i < length; i++ ) {
		str = menu_string[i];
		setpos(2,i+1);
		setcolor(14,9);
		printf(" %d",i+1);
		setcolor(7,0);
		printf("%s",str);
	}
	setpos(0,33);
}

/*动态分区信息
 */
void show_dynamic() {
	
	Final_partition_description *tmp = final_partition_description;
	int last_show_store = 1;
	int _n = 2;
	while( tmp!=NULL && last_show_store <= 30 ) {
		setpos(114,_n);
		//如果空闲则显示
		if( tmp->partition_state == 0 ) {
			printf(" %-7d%-6d%-6d%4s\n",
			tmp->partition_number,tmp->partition_size,tmp->partition_start_address,"空闲");
			_n++;
		}
		tmp = tmp->next;
		last_show_store++;
	}

	while( _n < 32 ) {
		setpos(114,_n);
		printf("%24s"," ");
		_n++;
	}
	
	setpos(0,33);
}

/*主框架显示
 */
int show_static_store( void ) {
	clear_menu_show();
	
	setpos(0,0);
	int i = 0;
	int j = 0;
	int k = 1;
	int _k = 1;
	for( j = 0; j < HEIGHT; j++ ) {
		if( j == 0 || j == HEIGHT-1 ) {
			for( i = 0; i < WIDTH; i++ ) {
				if( j == 0 && i == 60 ) {
					
					setcolor(14,4);
					//如果是动态分配方式,显示空闲分区表
					if( store_mode == 3 )
						printf("空闲分区表");
					else
						printf("分区说明表");
					setcolor(7,0);
					i+=4;
				}else if( j == 0 && i == 73 ) {
					setcolor(14,4);
					printf("存储空间分配情况");
					setcolor(7,0);
					i+=7;
				}else if( j == 0 && i == 3 ) {
					setcolor(14,4);
					printf("选项菜单");
					setcolor(7,0);
					i+=3;
				}else if( j == 0 && i == 13 ) {
					setcolor(14,4);
					printf("当前系统设置");
					setcolor(7,0);
					i+=5;
				}else if( j == 0 && i == 34 ) {
					setcolor(14,4);
					printf("当前程序输出");
					setcolor(7,0);
					i+=5;
				}else 
					printf("■");
			}
		} else {
			for( i = 0; i < WIDTH; i++ ){
				if( j == _k*2+10  && i == 33 && _k <= track_number ) {
					printf("■■■■■■■■■■■■■■■■■");
					i+=16;
					_k++;
				}else if( j == 10 && i == 50 ) {
					setcolor(14,4);
					printf("后备队列");
					setcolor(14,9);
					printf("大小");
					setcolor(7,0);
					i+=5;
				}else if( j == 10 && i == 23 ) {
					setcolor(14,4);
					printf("当前执行作业信息");
					setcolor(7,0);
					i+=7;
				}else if( j == 10 && i == 41 ) {
					setcolor(14,4);
					printf("多道");
					setcolor(7,0);
					i+=1;
				}else if( i == 0 || i == WIDTH-1 || i == 69 || i == 56 || i == 10 || i == 21 
					|| (j == 10 && (i > 21 && i < 57)) 
					|| (j > 10 && i == 32)
					|| (j > 10 && i == 49))
					printf("■");
				else if( j == 1 && i == 57 ) {
					setcolor(14,9);
					printf("分区号　大小　起址　状态");
					setcolor(7,0);
					i+=11;
				}else
					printf("　");
			}
		}
	}
	show_reserve_queue();
	show_menu();
	os_info();
	//如果是动态分配方式,显示空闲分区表
	if( store_mode == 3 )
		show_dynamic();
	else
		show_store(); 
	
	show_store_info();
	clear_input_show();
	return 0;
}

/*显示后备队列信息
 */
int show_reserve_queue( void ) {
	int _n = 11;
	int count = 0;
	Reserve_queue *_tmp = reserve_queue;
	while( _tmp != NULL  ) {
		if( _tmp->jcb != NULL ) {
			setpos(100,_n++);
			printf("作业%-4d%4d",_tmp->jcb->identify,_tmp->jcb->request_memory);
		}
		_tmp = _tmp->next;
		count++;
	}
	
	while( count < 21 ) {
		setpos(100,_n++);
		printf("            ");
		count++;
	}
	setpos(0,33);
}

/*显示内存
 */
int show_store_info() {
	Store_job *tmp = store_job;
	int last_show_store = 1;
	int _n = 2;
	
	setpos(140,1);
	setcolor(14,9);
	printf("起始地址　　　　内容　　　　");
	setcolor(7,0);
	
	while( tmp!=NULL && last_show_store <= 30 ) {
		setpos(140,_n);
		if( tmp->jcb != NULL ) {
			printf(" %-16d作业%-6d\n",tmp->start_address,tmp->jcb->identify);
		} else {
			printf(" %-16d%-6s\n",tmp->start_address,"NULL");
		}
		tmp = tmp->next;
		_n++;
		last_show_store++;
	}
	
	while( _n < 32 ) {
		setpos(140,_n);
		printf("%23s"," ");
		_n++;
	}
	
	setpos(0,33);
}


/*刷新数据
 */
int reflesh_info(void) {
	show_track();
	show_current_jcb_info();
	clear_input_show();
	
	if( store_mode == 3 )
		show_dynamic();
	else
		show_store();
	
	show_reserve_queue();
	os_info();
	show_store_info();
}