#include <stdio.h>
#include "job.h"
#include "store.h"
#include "dynamic.h"
#include "processor_manager.h"
#include "view.h"
#define one_quit '5'

int main(void) {
	
	system("mode con: cols=170 lines=35");
	system("cls");

	
	
	int mode_memory = -1;	//分配方式
	int size_memory = 128;	//内存分配大小
	//从键盘获取输入
	int c = 'i'; //主菜单选项
	
	char str_name[10] = "default";
	
	int current_job = 1;
	initial_reverse_queue();//初始化后备队列
	int job_init = 0;
	while(c!=one_quit) {
		show_static_store();
		c = getch();
		int c_1 = 'i';//二级菜单
		int c_2 = 'i';//三级菜单
		int c_3 = 'i';//四级菜单
		if( c == '1' ) {  				//1.分区分配方式
			while( c_1 != '4' ) {
				show_partition_menu(0);
				c_1 = getch();
				if( c_1 == '1' ) {				//1.固定分区分配
					mode_memory = 1;
					c_2 = 'i';
					while( c_2 != '3' ) {
						show_final_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.默认大小128k
							initial_store(mode_memory,size_memory);
							c_1 = '4';
							c_2 = '3';
							break;
						} else if( c_2 == '2' ) {	//2.自定义大小
							input_show("请输入分配大小:");
							scanf("%d",&size_memory);
							initial_store(mode_memory,size_memory);
							clear_input_show();
							c_1 = '4';
							c_2 = '3';
							break;
						}
					}
				} else if( c_1 == '2' ) {		//2.固定分区分配(不等)
					mode_memory = 2;
					while( c_2 != '2' ) {
						show_final_not_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.确认
							initial_store(mode_memory,size_memory);
							c_1 = '4';
							c_2 = '2';
							break;
						} else if( c_2 == '2' ) {	//2.取消
							c_2 = '3';
							break;
						}
					}
				} else if( c_1 == '3' ) {		//3.动态分区分配
					mode_memory = 3;
					c_2 = 'i';
					while( c_2 != '5' ) {
						show_dynamic_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.首次适应算法
							c_3 != 'i';
							while( c_3 != '2' ) {
								show_final_not_partition_menu();
								c_3 = getch();
								if( c_3 == '1' ) {			//1.确认
									current_method = 1;//动态
									initial_store(mode_memory,1);
									c_1 = '4';
									c_2 = '5';
									break;
								} else if( c_3 == '2' ) {	//2.取消
									c_1 = '4';
									c_2 = '5';
									break;
								}
							}
						} else if( c_2 == '2' ) {	//2.循环首次适应算法
							c_3 != 'i';
							while( c_3 != '2' ) {
								show_final_not_partition_menu();
								c_3 = getch();
								if( c_3 == '1' ) {			//1.确认
									current_method = 2;
									initial_store(mode_memory,2);
									c_1 = '4';
									c_2 = '5';
									break;
								} else if( c_3 == '2' ) {	//2.取消
									c_1 = '4';
									c_2 = '5';
									break;
								}
							}
						} else if( c_2 == '3' ) { 	//3.最佳适应算法
							c_3 != 'i';
							while( c_3 != '2' ) {
								show_final_not_partition_menu();
								c_3 = getch();
								if( c_3 == '1' ) {			//1.确认
									current_method = 3;
									initial_store(mode_memory,3);
									c_1 = '4';
									c_2 = '5';
									break;
								} else if( c_3 == '2' ) {	//2.取消
									c_1 = '4';
									c_2 = '5';
									break;
								}
							}
						} else if( c_2 == '4' ) {	//4.最坏适应算法
							while( c_3 != '2' ) {
								show_final_not_partition_menu();
								c_3 = getch();
								if( c_3 == '1' ) {			//1.确认
									current_method = 4;
									initial_store(mode_memory,4);
									c_1 = '4';
									c_2 = '5';
									break;
								} else if( c_3 == '2' ) {	//2.取消
									c_1 = '4';
									c_2 = '5';
									break;
								}
							}
						}
					}
				}
			}
		} else if( c == '2' ) {			//2.调入作业
			while( c_1 != '3' ) {
				show_scheduling_job();
				c_1 = getch();
				if( c_1 == '1' ) {				//1.调入预设作业
					c_2 = 'i';
					while( c_2 != '2' ) {
						show_final_not_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.确认
							if( job_init == 0 ) {
								create_job_default();	//创建默认作业
								job_init = 1;
							}
							c_1 = '3';
							c_2 = '2';
							break;
						} else if( c_2 == '2' ) {	//2.取消
							c_2 = '3';
							break;
						}
					}
				} else if( c_1 == '2' ) {		//2.新建作业
					mode_memory = 2;
					while( c_2 != '2' ) {
						show_final_not_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.确认
							printf("输入你的用户名:");
							scanf("%s",str_name);
							push_reserve_jcb(create_space(str_name));
							show_reserve_queue();//刷新显示后备队列
							c_1 = '4';
							c_2 = '2';
							break;
						} else if( c_2 == '2' ) {	//2.取消
							c_2 = '3';
							break;
						}
					}
				}
			}
			if( store_mode == 1 ) {
				show_store();
			}else if( store_mode == 2 ) {
				show_store();
			}else if( store_mode == 3 ) {
				show_dynamic();
			}
			setpos(60,6);
			setpos(0,33);
		} else if( c == '3' ) {			//3.执行菜单
			while( c_1 != '4' ) {
				show_execute_menu();
				c_1 = getch();
				if( c_1 == '1' ) {				//1.自动执行
					c_2 = 'i';
					while( c_2 != '3' ) {
						show_final_not_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.确认
							run();
							c_2 = '3';
							break;
						} else if( c_2 == '2' ) {	//2.取消
							c_2 = '3';
							break;
						}
					}
				} else if( c_1 == '2' ) {		//2.单步执行
					c_2 = 'i';
					run_step();
					show_current_track();
				} else if( c_1 == '3' ) {		//3.暂停
					c_2 = 'i';
					while( c_2 != '3' ) {
						show_final_not_partition_menu();
						c_2 = getch();
						if( c_2 == '1' ) {			//1.确认
							//暂停
							c_2 = '3';
							break;
						} else if( c_2 == '2' ) {	//2.取消
							c_2 = '3';
							break;
						}
					}
				}
			}
		} else if( c == '4' ) {			//4.设置多道
			printf("请输入道数:");
			scanf("%d",&track_number);
			//control_pause = 1;
		}
	}
	system("mode con: cols=80 lines=25");
	system("cls");
	return 0;
}