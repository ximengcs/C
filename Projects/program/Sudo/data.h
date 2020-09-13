#pragma once

int procedure = 1; //是否演示过程

int NUM = 3;

int content[9][9] = {0};

int state_3[9][9] = {0};

int content_4[16][16] = {0};

int state_4[16][16] = {0};

//初始化数独
int _init(int n) {
	
	int i,j;
	if(n == 1) {
		content[0][0] = 0;content[0][1] = 0;content[0][2] = 0;	content[0][3] = 0;content[0][4] = 0;content[0][5] = 6;	content[0][6] = 0;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 4;content[1][1] = 5;content[1][2] = 0;	content[1][3] = 0;content[1][4] = 0;content[1][5] = 0;	content[1][6] = 1;content[1][7] = 0;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 0;	content[2][3] = 0;content[2][4] = 0;content[2][5] = 2;	content[2][6] = 5;content[2][7] = 0;content[2][8] = 0;
		
		content[3][0] = 0;content[3][1] = 7;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 1;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 0;content[4][2] = 0;	content[4][3] = 0;content[4][4] = 0;content[4][5] = 0;	content[4][6] = 0;content[4][7] = 0;content[4][8] = 6;
		content[5][0] = 8;content[5][1] = 0;content[5][2] = 0;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 0;	content[5][6] = 0;content[5][7] = 7;content[5][8] = 2;
		
		content[6][0] = 0;content[6][1] = 0;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 0;content[6][5] = 0;	content[6][6] = 0;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 0;	content[7][3] = 0;content[7][4] = 4;content[7][5] = 8;	content[7][6] = 9;content[7][7] = 0;content[7][8] = 0;
		content[8][0] = 0;content[8][1] = 1;content[8][2] = 2;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 0;	content[8][6] = 0;content[8][7] = 0;content[8][8] = 0;
	} else if(n == 2) {
		content[0][0] = 0;content[0][1] = 0;content[0][2] = 1;	content[0][3] = 2;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 3;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 2;content[1][1] = 0;content[1][2] = 0;	content[1][3] = 4;content[1][4] = 0;content[1][5] = 0;	content[1][6] = 0;content[1][7] = 0;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 5;	content[2][3] = 6;content[2][4] = 1;content[2][5] = 0;	content[2][6] = 0;content[2][7] = 7;content[2][8] = 0;
		
		content[3][0] = 6;content[3][1] = 8;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 0;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 0;content[4][2] = 2;	content[4][3] = 0;content[4][4] = 4;content[4][5] = 0;	content[4][6] = 9;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 0;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 0;	content[5][6] = 0;content[5][7] = 5;content[5][8] = 3;
		
		content[6][0] = 0;content[6][1] = 3;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 5;content[6][5] = 2;	content[6][6] = 1;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 0;	content[7][3] = 0;content[7][4] = 0;content[7][5] = 4;	content[7][6] = 0;content[7][7] = 0;content[7][8] = 8;
		content[8][0] = 0;content[8][1] = 0;content[8][2] = 9;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 1;	content[8][6] = 5;content[8][7] = 0;content[8][8] = 0;
	} else if(n == 3) {
		content[0][0] = 0;content[0][1] = 0;content[0][2] = 1;	content[0][3] = 2;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 3;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 2;content[1][1] = 0;content[1][2] = 0;	content[1][3] = 4;content[1][4] = 0;content[1][5] = 0;	content[1][6] = 0;content[1][7] = 0;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 5;	content[2][3] = 6;content[2][4] = 1;content[2][5] = 0;	content[2][6] = 0;content[2][7] = 7;content[2][8] = 0;
		
		content[3][0] = 6;content[3][1] = 8;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 0;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 5;content[4][2] = 2;	content[4][3] = 0;content[4][4] = 4;content[4][5] = 0;	content[4][6] = 9;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 0;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 0;	content[5][6] = 0;content[5][7] = 5;content[5][8] = 3;
		
		content[6][0] = 0;content[6][1] = 3;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 5;content[6][5] = 2;	content[6][6] = 1;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 0;	content[7][3] = 0;content[7][4] = 0;content[7][5] = 4;	content[7][6] = 0;content[7][7] = 0;content[7][8] = 8;
		content[8][0] = 0;content[8][1] = 0;content[8][2] = 9;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 1;	content[8][6] = 5;content[8][7] = 0;content[8][8] = 0;
	} else if(n == 4) {
		content[0][0] = 1;content[0][1] = 2;content[0][2] = 0;	content[0][3] = 4;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 3;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 3;content[1][1] = 0;content[1][2] = 0;	content[1][3] = 0;content[1][4] = 1;content[1][5] = 0;	content[1][6] = 0;content[1][7] = 5;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 6;	content[2][3] = 0;content[2][4] = 0;content[2][5] = 0;	content[2][6] = 1;content[2][7] = 0;content[2][8] = 0;
		
		content[3][0] = 7;content[3][1] = 0;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 9;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 4;content[4][2] = 0;	content[4][3] = 6;content[4][4] = 0;content[4][5] = 3;	content[4][6] = 0;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 3;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 2;	content[5][6] = 0;content[5][7] = 0;content[5][8] = 0;
		
		content[6][0] = 5;content[6][1] = 0;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 8;content[6][5] = 0;	content[6][6] = 7;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 7;	content[7][3] = 0;content[7][4] = 0;content[7][5] = 0;	content[7][6] = 0;content[7][7] = 0;content[7][8] = 5;
		content[8][0] = 0;content[8][1] = 0;content[8][2] = 0;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 0;	content[8][6] = 0;content[8][7] = 9;content[8][8] = 8;
	} else if(n == 5) {
		content[0][0] = 1;content[0][1] = 2;content[0][2] = 0;	content[0][3] = 4;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 3;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 3;content[1][1] = 0;content[1][2] = 0;	content[1][3] = 0;content[1][4] = 1;content[1][5] = 0;	content[1][6] = 0;content[1][7] = 5;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 6;	content[2][3] = 0;content[2][4] = 0;content[2][5] = 0;	content[2][6] = 1;content[2][7] = 0;content[2][8] = 0;
		
		content[3][0] = 7;content[3][1] = 0;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 9;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 4;content[4][2] = 0;	content[4][3] = 6;content[4][4] = 0;content[4][5] = 3;	content[4][6] = 0;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 3;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 2;	content[5][6] = 0;content[5][7] = 0;content[5][8] = 0;
		
		content[6][0] = 5;content[6][1] = 0;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 8;content[6][5] = 0;	content[6][6] = 7;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 7;	content[7][3] = 0;content[7][4] = 0;content[7][5] = 0;	content[7][6] = 0;content[7][7] = 0;content[7][8] = 5;
		content[8][0] = 0;content[8][1] = 0;content[8][2] = 0;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 0;	content[8][6] = 0;content[8][7] = 9;content[8][8] = 8;
	} else if(n == 6) {
		content[0][0] = 1;content[0][1] = 2;content[0][2] = 0;	content[0][3] = 3;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 0;content[0][7] = 0;content[0][8] = 0;
		content[1][0] = 3;content[1][1] = 4;content[1][2] = 0;	content[1][3] = 0;content[1][4] = 0;content[1][5] = 0;	content[1][6] = 1;content[1][7] = 0;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 5;	content[2][3] = 0;content[2][4] = 0;content[2][5] = 0;	content[2][6] = 0;content[2][7] = 0;content[2][8] = 0;
		
		content[3][0] = 6;content[3][1] = 0;content[3][2] = 2;	content[3][3] = 4;content[3][4] = 0;content[3][5] = 0;	content[3][6] = 5;content[3][7] = 0;content[3][8] = 0;
		content[4][0] = 0;content[4][1] = 0;content[4][2] = 0;	content[4][3] = 0;content[4][4] = 6;content[4][5] = 0;	content[4][6] = 0;content[4][7] = 7;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 0;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 8;	content[5][6] = 0;content[5][7] = 0;content[5][8] = 6;
		
		content[6][0] = 0;content[6][1] = 0;content[6][2] = 4;	content[6][3] = 2;content[6][4] = 0;content[6][5] = 0;	content[6][6] = 3;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 0;	content[7][3] = 0;content[7][4] = 7;content[7][5] = 0;	content[7][6] = 0;content[7][7] = 0;content[7][8] = 9;
		content[8][0] = 0;content[8][1] = 0;content[8][2] = 0;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 9;	content[8][6] = 0;content[8][7] = 8;content[8][8] = 0;
	} else if(n == 7) {
		content[0][0] = 0;content[0][1] = 0;content[0][2] = 0;	content[0][3] = 0;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 0;content[0][7] = 1;content[0][8] = 2;
		content[1][0] = 0;content[1][1] = 0;content[1][2] = 0;	content[1][3] = 0;content[1][4] = 0;content[1][5] = 0;	content[1][6] = 0;content[1][7] = 0;content[1][8] = 3;
		content[2][0] = 0;content[2][1] = 0;content[2][2] = 2;	content[2][3] = 3;content[2][4] = 0;content[2][5] = 0;	content[2][6] = 4;content[2][7] = 0;content[2][8] = 0;
		
		content[3][0] = 0;content[3][1] = 0;content[3][2] = 1;	content[3][3] = 8;content[3][4] = 0;content[3][5] = 0;	content[3][6] = 0;content[3][7] = 0;content[3][8] = 5;
		content[4][0] = 0;content[4][1] = 6;content[4][2] = 0;	content[4][3] = 0;content[4][4] = 7;content[4][5] = 0;	content[4][6] = 8;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 0;content[5][2] = 0;	content[5][3] = 0;content[5][4] = 0;content[5][5] = 9;	content[5][6] = 0;content[5][7] = 0;content[5][8] = 0;
		
		content[6][0] = 0;content[6][1] = 0;content[6][2] = 8;	content[6][3] = 5;content[6][4] = 0;content[6][5] = 0;	content[6][6] = 0;content[6][7] = 0;content[6][8] = 0;
		content[7][0] = 9;content[7][1] = 0;content[7][2] = 0;	content[7][3] = 0;content[7][4] = 4;content[7][5] = 0;	content[7][6] = 5;content[7][7] = 0;content[7][8] = 0;
		content[8][0] = 4;content[8][1] = 7;content[8][2] = 0;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 6;	content[8][6] = 0;content[8][7] = 0;content[8][8] = 0;
	} else if(n == 8) {
		content[0][0] = 0;content[0][1] = 0;content[0][2] = 0;	content[0][3] = 0;content[0][4] = 0;content[0][5] = 0;	content[0][6] = 0;content[0][7] = 0;content[0][8] = 3;
		content[1][0] = 0;content[1][1] = 0;content[1][2] = 1;	content[1][3] = 0;content[1][4] = 0;content[1][5] = 5;	content[1][6] = 6;content[1][7] = 0;content[1][8] = 0;
		content[2][0] = 0;content[2][1] = 9;content[2][2] = 0;	content[2][3] = 0;content[2][4] = 4;content[2][5] = 0;	content[2][6] = 0;content[2][7] = 7;content[2][8] = 0;
		
		content[3][0] = 0;content[3][1] = 0;content[3][2] = 0;	content[3][3] = 0;content[3][4] = 0;content[3][5] = 9;	content[3][6] = 0;content[3][7] = 5;content[3][8] = 0;
		content[4][0] = 7;content[4][1] = 0;content[4][2] = 0;	content[4][3] = 0;content[4][4] = 0;content[4][5] = 0;	content[4][6] = 0;content[4][7] = 0;content[4][8] = 0;
		content[5][0] = 0;content[5][1] = 5;content[5][2] = 0;	content[5][3] = 4;content[5][4] = 0;content[5][5] = 2;	content[5][6] = 0;content[5][7] = 0;content[5][8] = 0;
		
		content[6][0] = 0;content[6][1] = 8;content[6][2] = 0;	content[6][3] = 0;content[6][4] = 2;content[6][5] = 0;	content[6][6] = 0;content[6][7] = 9;content[6][8] = 0;
		content[7][0] = 0;content[7][1] = 0;content[7][2] = 3;	content[7][3] = 5;content[7][4] = 0;content[7][5] = 0;	content[7][6] = 1;content[7][7] = 0;content[7][8] = 0;
		content[8][0] = 6;content[8][1] = 0;content[8][2] = 0;	content[8][3] = 0;content[8][4] = 0;content[8][5] = 0;	content[8][6] = 0;content[8][7] = 0;content[8][8] = 0;
	}
	for( i = 0; i < 9; i++ ) {
		for( j = 0; j < 9; j++ ) {
			if(content[i][j] !=  0)
				state_3[i][j] = 1;
			else
				state_3[i][j] = 0;
		}
	}
}

//检查数独是否完成
int check_content(void) {
	
}
