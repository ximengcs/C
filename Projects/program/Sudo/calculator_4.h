#pragma once
#include "data.h"
#include "view.h"
#include "time.h"
#include <stdlib.h>

//回溯法计算数独
//返回0无解
int recall_4(int col) {
	
	int start_value = 0;
	int i,j,k,l;
	
	int pos = 10;
	int count = 1;
	//行 
	for( i = 0; i < col*col; i++ ) {
		//列
		for( j = 0; j < col*col; j++ ) {
			if( state_4[i][j] == 1 ) {
				continue;
			}
			content_4[i][j] += 1;
			if( content_4[i][j] == 17 ) {
				content_4[i][j] = 0;
				//找到前面第一个不是固定值的
				if( j == 0 ) {
					k = i-1;//行
					l = col*col-1;//列
				} else {
					k = i;
					l = j-1;
				}
				
				int find_flag = 0;
				while( k >= 0 ) {
					while( l >= 0 && l <= col*col ) {
						if( state_4[k][l] != 1 && find_flag == 0 ) {
							
							
							find_flag = 1;
							break;
						}
						l--;
					}
					if( find_flag == 1 )
						break;
					k--;
					l = col*col-1;
				}
				if( find_flag == 1 ) {
					i = k;
					j = l-1;
				} else {
					
					return 0;
				}
			} else if( check_point_4(i,j,4) == 0 ) {//如果不合法
				j--;
			} else {
			}
			if( procedure )
				reflesh_num_4();
		}
	}
	
}

//检查当前格的合法性
//合法返回1
//不合法返回0
int check_point_4(int i, int j, int col) {
	
	//检查当前行是否合法
	int k;
	for( k = 0; k < col*col; k++ ) {
		if( k == j )
			k++;
		if( content_4[i][k] == content_4[i][j] )  //如果存在两个数相等
			return 0;
	}
	
	//检查当前列是否合法
	for( k = 0; k < col*col; k++ ) {
		if( k == i )
			k++;
		if( content_4[k][j] == content_4[i][j] )	//如果存在两个数相等
			return 0;
	}
	
	//检查当前九宫格是否合法
	int _i,_j,_i_limit,_j_limit;
	_i = (i/col)*col;//行
	_j = (j/col)*col;//列
	_i_limit = _i + col;
	_j_limit = _j + col;
	while( _i < _i_limit ) {//当前九宫格的行
		_j = (j/col)*col;//列
		while( _j < _j_limit ) {//遍历当前九宫格的列
			if( _i == i && _j == j )
				_j++;
			if( content_4[_i][_j] == content_4[i][j] )
				return 0;
			_j++;
		}
		_i++;
	}
	
	return 1;//如果没有找到相等的数，合法
}

//生成数独
int create_num_4(int hole_num) {
	
	int i,j;
	for( i = 0; i < 16; i++ ) {
		for( j = 0; j < 16; j++ ) {
			content_4[i][j] = 0;
			if( i == 0 )
				state_4[i][j] = 1;
			else
				state_4[i][j] = 0;
		}
	}
	
	srand(time(NULL));
	
	for( i = 0; i < 16; i++ ) {
		content_4[0][i] = rand()%16+1;
		if( check_point_4(0,i,4) == 0 )
			i--;
	}
	
	accurate_4(4);
	
	for( i = 0; i < 16; i++ ) {
		for( j = 0; j < 16; j++ ) {
			state_4[i][j] = 1;
		}
	}
	
	hole_4(hole_num);
	reflesh_num_4();
}

//挖洞
int hole_4(int n) {
	srand(time(NULL));
	int i,_i,_j;
	for( i = 0; i < n; i++ ) {
		_i = rand()%16;
		_j = rand()%16;
		if( state_4[_i][_j] == 1 ) {
			content_4[_i][_j] = 0;
			state_4[_i][_j] = 0;
		} else
			i--;
	}
}

//计算并放入可用数组
int put_available_4( int available[16][16][16], int i, int j ) {
	
	int k;
	int col = 4;
	//放入当前九宫格可用数组
		//检查当前九宫格是否合法
	int _i,_j,_i_limit,_j_limit;
	_i = (i/col)*col;//行
	_j = (j/col)*col;//列
	_i_limit = _i + col;
	_j_limit = _j + col;
	while( _i < _i_limit ) {//遍历当前九宫格的行
		_j = (j/col)*col;//列
		while( _j < _j_limit ) {//遍历当前九宫格的列
			//如果当前九宫格内当前数字可用
			available[_i][_j][ content_4[i][j]-1 ] = 1;
			_j++;
		}
		_i++;
	}
	
	//放入当前行 当前列 可用数组
	for( _i = 0; _i < 16; _i++ ) {
		available[_i][j][ content_4[i][j]-1 ] = 1;
		available[i][_i][ content_4[i][j]-1 ] = 1;
	}
}

//
int show_available_4( int available[16][16][16] ) {
	int i,j,k;
	printf("\n");
	for( i = 0; i < 9; i++ ) {
		for( j = 0; j < 9; j++ ) {
			for( k = 0; k < 9; k++ ) {
				printf("%2d",available[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
}

//优化算法
int accurate_4(int col) {
	int available[16][16][16] = {0};
	int i,j;
	
	//初始化可用数字数组
	for( i = 0; i < 9; i++ ) {
		for( j = 0; j < 9; j++ ) {
			if(state_4[i][j] == 1) {
				put_available_4( available, i, j );
			}
		}
	}
	
	
	int start_value = 0;
	int k,l;
	
	int pos = 10;
	//行 
	for( i = 0; i < col*col; i++ ) {
		//列
		for( j = 0; j < col*col; j++ ) {
			if( state_4[i][j] == 1 ) {
				continue;
			}
			content_4[i][j] += 1;
			
			while( available[i][j][ content_4[i][j]-1 ] == 1 && content_4[i][j] != 17 )
				content_4[i][j]++;
			
			if( content_4[i][j] == 17 ) {
				content_4[i][j] = 0;
				//找到前面第一个不是固定值的
				if( j == 0 ) {
					k = i-1;//行
					l = col*col-1;//列
				} else {
					k = i;
					l = j-1;
				}
				
				int find_flag = 0;
				while( k >= 0 ) {
					while( l >= 0 && l <= col*col ) {
						if( state_4[k][l] != 1 && find_flag == 0 ) {
							
							
							find_flag = 1;
							break;
						}
						l--;
					}
					if( find_flag == 1 )
						break;
					k--;
					l = col*col-1;
				}
				if( find_flag == 1 ) {
					i = k;
					j = l-1;
				} else {
					
					return 0;
				}
			} else if( check_point_4(i,j,4) == 0 ) {//如果不合法
				j--;
			} else {
			}
			if( procedure )
				reflesh_num_4();
		}
	}
}

//重填
int reset_4(void) {
	int i,j;
	
	for( i = 0; i < 9; i++ ) {
		for( j = 0; j < 9; j++ ) {
			if( state_3[i][j] == 0 )
				content[i][j] = 0;
		}
	}
}