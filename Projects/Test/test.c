#include <stdio.h>
#include "simon.h"

int main(void) {
	
	char chars[100][20];
	ziku(chars);
	
	char *tmp = &chars;
	int i = 0;
	while(i<100) {
		printf("%s\n",tmp);
		tmp++;
		i++;
	}
	
	return 0;
}