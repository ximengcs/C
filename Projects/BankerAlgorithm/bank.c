#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Windows.h>
#include "view.h"
#include "example.h"

//课本数据
int initial_course_example(void);

//重置"系统"
int reset(void);

int get_input(Max *_max, Allocation *_allocation);

int main(void) {
	system("cls");
	set_console_size(100,25);
	show_frame();
	hide_console();
	
	initial();
	random_create();
	calculate();
	safe_order();
	show_safe_order();
	show_time();
	show_safe_process_info();
	
	int COUNT_1_MAX = 8;	//一级菜单选项个数
	int COUNT_2_MAX = 4;	//二级菜单选项个数
	
	int count_1 = 1,//一级菜单
		count_2 = 1,//二级菜单
		count_3 = 1;//三级菜单
	int input_1 = '0',
		input_2 = '0',
		input_3 = '0';

	while(1) {//---------------------------------------一级菜单
		show_menu_1(count_1);
		input_1 = getch();
		if( input_1 == 's' ) {	//下
			if( count_1 < COUNT_1_MAX )
				count_1++;
		} else if( input_1 == 'w' ) {//上
			if( count_1 > 1 )
				count_1--;
		} else if( input_1 == 13 ) {//回车
			if( count_1 == 1 ) {//创建进程
				while(1) {//----------------------------二级菜单
					show_menu_1_2(count_2);
					input_2 = getch();
					if( input_2 == 's' ) {//下
						if( count_2 < COUNT_2_MAX )
							count_2++;
					} else if( input_2 == 'w' ) {//上
						if( count_2 > 1 )
							count_2--;
					} else if( input_2 == 13 ) {//回车
						if( count_2 == 1 ) {//手动输入
							input_process_info();
							Max *max = get_object('A');
							Allocation *all = get_object('A');
							show_console();
							get_input(max,all);
							hide_console();
							random_create_process(max,all);
							reflesh_input();
							safe_order();
							show_time();
							show_safe_process_info();
							show_safe_order();
						} else if( count_2 == 2 ) {//随机生成一个
							random_create_process(NULL,NULL);
							safe_order();
							show_time();
							show_safe_process_info();
							show_safe_order();
						} else if( count_2 == 3 ) {//随机生成十个
							int i = 0;
							for( i = 0; i < 10; i++ )
								random_create_process(NULL,NULL);
							safe_order();
							show_safe_process_info();
							show_time();
							show_safe_order();
						} else if( count_2 == 4 ) {
							count_2 = 1;
							break;
						}
					} else
						change_page(input_2);
				}
			} else if( count_1 == 2 ) {//撤销进程
				if( PROCESS_NUM > 0 ) {
					cancel_process();
					safe_order();
					reflesh_page();
					show_time();
					show_safe_process_info();
					show_safe_order();
				}
			} else if( count_1 == 3 ) {//执行进程
				if( PROCESS_NUM > 0 ) {
					run_step();
					safe_order();
					reflesh_page();
					show_safe_process_info();
					show_time();
					show_safe_order();
				}
			} else if( count_1 == 4 ) {//进程请求
				if( PROCESS_NUM > 0 ) {
					show_input_require();
					int id = -1;
					struct RESOURCE *new_require = get_object('A');
					struct RESOURCE *tmp = new_require;
					show_console();
					scanf("%d",&id);
					while( tmp != NULL ) {
						int num = 0;
						scanf("%d",&num);
						tmp->num = num;
						tmp = tmp->next;
					}
					hide_console();
					require_process(id,new_require);
					reflesh_input();
					safe_order();
					show_time();
					show_safe_process_info();
					show_safe_order();
				}
			} else if( count_1 == 5 ) {//撤销请求
				if( PROCESS_NUM > 0 ) {
					cancel_require();
					safe_order();
					show_time();
					show_safe_process_info();
					show_safe_order();
				}
			} else if( count_1 == 6 ) {//课本例题
				initial_course_example();
				safe_order();
				show_time();
				show_safe_process_info();
				show_safe_order();
			} else if( count_1 == 7 ) {//设置
				while(1) {
					show_menu_6(count_2);
					input_2 = getch();
					if( input_2 == 's' ) {//下
						if( count_2 < 3 )
							count_2++;
					} else if( input_2 == 'w' ) {//上
						if( count_2 > 1 )
							count_2--;
					} else if( input_2 == 13 ) {//回车
						if( count_2 == 1 ) {//资源种类
							input_kind();
							show_console();
							scanf("%d",&KIND_NUM);
							hide_console();
							reflesh_input();
							reflesh_page();
							reset();//重置系统
						} else if( count_2 == 2 ) {//available
							Available *tmp = available;
							input_available();
							show_console();
							while( tmp != NULL ) {
								int num = 0;
								scanf("%d",&num);
								tmp->num = num;
								tmp = tmp->next;
							}
							hide_console();
							reflesh_input();
							safe_order();
							show_safe_process_info();
							show_time();
							show_safe_order();
						} else if( count_2 == 3 ) {//退出
							count_2 = 1;
							break;
						}
					} else
						change_page(input_2);
				}
			} else if( count_1 == 8 ) {//退出
				release_all();
				show_console();
				return 0;
			}
		} else
			change_page(input_1);
	}
}

int change_page(int input) {
	if( input == 'u' ) {//资源上翻页
		if( resource_gage > 1 ) {
			resource_gage--;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'j' ) {//资源下翻页
		if( resource_gage < ((KIND_NUM-1)/3+1) ) {
			resource_gage++;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'o' ) {//work上翻页
		if( work_page > 1 ) {
			work_page--;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'l' ) {//work下翻页
		if( work_page < ((PROCESS_NUM-1)/5+1) ) {
			work_page++;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'i' ) {//进程上翻页
		if( process_page > 1 ) {
			process_page--;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'k' ) {//进程下翻页
		if( process_page < ((PROCESS_NUM-1)/5+1) ) {
			process_page++;
			show_safe_process_info();
			show_time();
		}
	} else if( input == 'y' ) {//安全序列上翻页
		if( safe_order_page > 1 ) {
			safe_order_page--;
			show_safe_order();
		}
	} else if( input == 'h' ) {//安全序列下翻页
		if( safe_order_page < ((PROCESS_NUM-1)/10+1) ) {
			safe_order_page++;
			show_safe_order();
		}
	}
}

int release_all(void) {
	//释放safe
	while(safe!=NULL) {
		Safe *old = safe;
		safe = safe->next;
		free(old);
	}
	
	//释放available
	while(available!=NULL) {
		Available *old = available;
		available = available->next;
		free(old);
	}

	//释放进程
	while(process!=NULL) {
		Process *old = process;
		process = process->next;
		
		Work *_work = old->work;
		Max *_max = old->max;
		Allocation *_allocation = old->allocation;
		Need *_need = old->need;
		while(_work!=NULL) {
			Work *old_work = _work;
			Max *old_max = _max;
			Allocation *old_allocation = _allocation;
			Need *old_need = _need;
			_work = _work->next;
			_max = _max->next;
			_allocation = _allocation->next;
			_need = _need->next;
			free(old_work);
			free(old_max);
			free(old_allocation);
			free(old_need);
		}
		
		free(old);
	}
	
	pro_id = 0;
}

int get_input(Max *_max, Allocation *_allocation) {
	while( _max != NULL ) {
		int tmp = 0;
		scanf("%d",&tmp);
		_max->num = tmp;
		_max = _max->next;
	}
	while( _allocation != NULL ) {
		int tmp = 0;
		scanf("%d",&tmp);
		_allocation->num = tmp;
		_allocation = _allocation->next;
	}
}

int reset(void) {
	release_all();
	PROCESS_NUM = 1;
	CURRENT_TIME = 0;
	initial();
	random_create();
	calculate();
	safe_order();
	show_safe_order();
	show_time();
	show_safe_process_info();
}

int initial_course_example(void) {
	release_all();
	CURRENT_TIME = 0;
	PROCESS_NUM = 5;
	KIND_NUM = 3;
	initial();
	course();
	reflesh_page();
	calculate();
	safe_order();
	show_safe_order();
	show_time();
	show_safe_process_info();
}