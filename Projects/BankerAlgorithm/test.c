#include <stdio.h>
#include "manager.h"
#include "data.h"
#include "process.h"
#include <stdlib.h>
#include "view.h"
#include <time.h>

int run(void) {
	if( PROCESS_NUM > 0 ) {
		safe_order();
		run_step();
	}
}

int cancel_pro(void) {
	if( PROCESS_NUM > 0 ) {
		cancel_process();
	}
}

int create(void) {
	if( PROCESS_NUM > 0 ) {
		random_create_process(NULL,NULL);
	}
}

int main(void) {
	srand(time(NULL));
	initial();
	random_create();
	calculate();
	while(1) {
		int i = rand()%3;
		if( i == 0 )
			run();
		else if( i == 1 )
			cancel_pro();
		else
			create();
		printf("(%d)",i);
	}
	return 0;
}