#include <stdio.h>
#include <stdlib.h>

void BubbleSort( int *nArray, int n );
void SelectSort( int nArray[], int n );

int main( void )
{
	int array[] = { 5, 2, -1, 0, 4, 8, 3 };
	int size;
	int i;
	
	size = sizeof array / sizeof array[0];
	
	BubbleSort( array, size );
	for( i = 0; i < size; i++ )
		printf( "%d ", array[i] );
	
	return EXIT_SUCCESS;
}

//冒泡排序
void BubbleSort( int *nArray, int n )
{
	int i, j;
	
	for( i = 0; i < size; i++ )
		for( j = 1; j < n-i; j++ ) // n-i ：最大元素减去已经排序的元素（排到最后的元素）个数
			if( nArray[j] < nArray[j-1] ){
				//交换值                 !!!!!!!!!!!!!!!!!!!!!!!交换的值是j和j-1，而不是j和i
				nArray[j-1] = nArray[j-1] + nArray[j];
				nArray[j] = nArray[j-1] - nArray[j];
				nArray[j-1] = nArray[j-1] - nArray[j];
			}
}

//选择排序
void SelectSort( int nArray[], int n )
{
	int i, j, min, tmp;
	//min：轮流查找数组中最小值的下标直到最后一个元素
	
	for( i = 0; i < n -1; i++ ){
		min = i;
		for( j = i+1; j < n; j++ ){
			if( nArray[j] < nArray[min] )
				min = j;
		}
		if( min != i )
		{
			//交换元素的值
			nArray[i] = nArray[i] + nArray[min];
			nArray[min] = nArray[i] - nArray[min];
			nArray[i] = nArray[i] - nArray[min];	
		}
	}
}

