#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* get_next(char* b, int size) {
	int* next = (int*)malloc(sizeof(int) * (size + 1));
	next[0] = 0;
	int i;
	for (i = 1; i < size; i++) {
		int j = i - 1;
		while (b[i] != b[next[j]] && j > 0)
			j = next[j]-1; //找到可以相等的位置
		if (b[i] == b[next[j]])
			next[i] = next[j] + 1;
		else
			next[i] = 0;
	}
	next[size] = '\0';
	return next;
}

int kmp(char* a, char* b) {
	int i = 0, j = 0;
	int* next = get_next(b, strlen(b));
	while (a[i] != '\0') {
		if (a[i] != b[j]) { //如果不相等
			if (j > 0)
				j = next[j - 1];//j返回到最大前缀
			else
				i++;
		}
		else {	//如果相等
			i++;
			j++;
			if (b[j] == '\0')
				break;
		}
	}
	//free(next);
	if (b[j] != '\0') //如果j没有匹配完就已经结束
		return -1;
	else
		return i - j;
}

int main() {
	char a[] = "hellodsf";
	char b[] = "ello";
	printf("%d", kmp(a, b));
	return 0;
}