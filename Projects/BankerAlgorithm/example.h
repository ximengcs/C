#pragma once
#include "data.h"
#include "process.h"
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//课本数据
void course(void) {
	Process *_process = process;
	Max *_max = NULL;
	Allocation *_allocation = NULL;
	Available *_available = available;
	
	//available
	_available->num = 3;
	_available->next->num = 3;
	_available->next->next->num = 2;
	
	//P0
	_max = _process->max;
	_allocation = _process->allocation;
	_max->num = 7;  		_max->next->num = 5;  		_max->next->next->num = 3;
	_allocation->num = 0;	_allocation->next->num = 1;	_allocation->next->next->num = 0;
	
	_process = _process->next;
	//P1
	_max = _process->max;
	_allocation = _process->allocation;
	_max->num = 3;  		_max->next->num = 2;  		_max->next->next->num = 2;
	_allocation->num = 2;	_allocation->next->num = 0;	_allocation->next->next->num = 0;
	
	_process = _process->next;
	
	//P2
	_max = _process->max;
	_allocation = _process->allocation;
	_max->num = 9;  		_max->next->num = 0;  		_max->next->next->num = 2;
	_allocation->num = 3;	_allocation->next->num = 0;	_allocation->next->next->num = 2;
	
	_process = _process->next;
	
	//P3
	_max = _process->max;
	_allocation = _process->allocation;
	_max->num = 2;  		_max->next->num = 2;  		_max->next->next->num = 2;
	_allocation->num = 2;	_allocation->next->num = 1;	_allocation->next->next->num = 1;
	
	_process = _process->next;
	
	//P4
	_max = _process->max;
	_allocation = _process->allocation;
	_max->num = 4;  		_max->next->num = 3;  		_max->next->next->num = 3;
	_allocation->num = 0;	_allocation->next->num = 0;	_allocation->next->next->num = 2;
}