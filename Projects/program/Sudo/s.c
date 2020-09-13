#include <stdio.h>
#include "view.h"
#include <stdlib.h>
#include "calculator.h"
#include <windows.h>

int main(void) {
	system("mode con: cols=80 lines=24");
	system("cls");
	
	show_menu();
	int _count = 1;
	int _tmp_count = 1;

	int _count_2 = 1;//二级菜单
	int _tmp_count_2 = 1;
	
	int _count_3 = 1;//三级菜单
	int _tmp_count_3 = 1;

	int _have = 0;
	long _time = 0;

	int flag = 0;//棋盘初始化
	do {//-------------------------------------------------------------------------------一级菜单
		//判断按键
		_tmp_count = getch();
		if( _tmp_count == 's' ) {//如果按键是上
			if( _count < 2 )
				_count++;
		} else if( _tmp_count == 'w' ) {//下
			if( _count > 1 )
				_count--;
		} else if( _tmp_count == 13 ) {//回车
			show_2_menu(1);
			do {//---------------------------------------------------------------二级菜单
				
				if( flag == 0 ) {
					if( _count == 1 ) {
						NUM = 3;
						//show_3_2();
					} else if( _count == 2 ) {
						system("cls");
						return 0;
					} else if( _count == 3 ) {
						system("cls");
						return 0;
					}
					flag = 1;
				}
				//判断按键
				
				_tmp_count_2 = getch();
				if( _tmp_count_2 == 's' ) {//上
					if( _count_2 < 6 )
						_count_2++;
				} else if( _tmp_count_2 == 'w' ) {//下
					if( _count_2 > 1 )
						_count_2--;
				} else if( _tmp_count_2 == 13 ) {//回车
					if( _count_2 == 1 ) {//生成数独
						show_create_hole_menu(1);
						
						do {//-------------------------------------------------------三级菜单
							_tmp_count_3 = getch();
							
							if( _tmp_count_3 == 's' ) {//上
								if( _count_3 < 13 )
									_count_3++;
							} else if( _tmp_count_3 == 'w' ) {//下
								if( _count_3 > 1 )
									_count_3--;
							} else if( _tmp_count_3 == 13 ) {//回车
								if( _count_3 == 6 ) {
									_init(1);
								} else if( _count_3 == 7 ) {
									_init(2);
								} else if( _count_3 == 8 ) {
									_init(3);
								} else if( _count_3 == 9 ) {
									_init(4);
								} else if( _count_3 == 10 ) {
									_init(5);
								} else if( _count_3 == 11 ) {
									_init(6);
								} else if( _count_3 == 12 ) {
									_init(7);
								} else if( _count_3 == 13 ) {
									_init(8);
								} else if( NUM == 3 )
									create_num(((_count_3)*10) + 20);
								_count_3 = 1;
								break;
							}
							
							show_create_hole_menu(_count_3);
						}while(1);//-----------------------------------------三级菜单end
						if( NUM == 3 )
							reflesh_num();
						else 
							reflesh_num_4();
					} else if( _count_2 == 2 ) {//回溯法计算数独
						_time = clock();
						_have = recall(NUM);
						setpos(0,21);
						if( _time!=0 )
							printf("所用时间:%d毫秒　　　　　　　　",clock()-_time);
						else
							printf("无解　　　　　 　　　　　　　　");
					} else if( _count_2 == 3 ) {//优化
						_time = clock();
						_have = accurate_3(NUM);
						setpos(0,21);
						if( _time!=0 )
							printf("所用时间:%d毫秒　　　　　　　　",clock()-_time);
						else
							printf("无解　　　　　 　　　　　　　　");
					} else if( _count_2 == 4 ) {//重填
						reset();
						if( NUM == 3 )
							reflesh_num();
						else 
							reflesh_num_4();
					} else if( _count_2 == 5 ) {//过程显示开关
						if(procedure)
							procedure = 0;
						else
							procedure = 1;
						show_2_menu(_count_2);
					} else if( _count_2 == 6 ) {//返回
						_count_2=1;
						flag = 0;
						break;
					}
				}
				
				show_2_menu(_count_2);
				
			} while( 1 );//-------------------------------------------二级菜单end
		}
		
		if( _count == 1 ) {
			show_choice_menu(_count);
		} else if( _count == 2 ) {
			show_choice_menu(_count);
		} else if( _count == 3 ) {
			show_choice_menu(_count);
		}
	} while( 1 );//---------------------------------------------------------------一级菜单end
	return 0;
}