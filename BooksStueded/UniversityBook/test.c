#include <stdio.h>
#include <pthread.h>

int flag = 0;

void thread() {
	printf("this is son");
}
int main(void) {
	pthread_t son;
	int succee;
	succee = pthread_create(&son,NULL,(void *)thread,NULL);
	if(succee!=0) {
		printf("faild");
		return 1;
	}
	printf("this is parent;");
	pthread_join(son,NULL);
	return 0;
}