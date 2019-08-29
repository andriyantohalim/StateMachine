/*
 * main.c
 *
 *  Created on: Aug 28, 2019
 *      Author: andri
 */


#include "main.h"

extern state_machine_t sm1;


int main(void)
{
	printf("Hello world\n");

	init_sm1();

	sm_start(&sm1);

	while(sm1.control != OFF)
	{
		sm1.current_event = EVENT_2; // force current event to EVENT_2

		sm_run(&sm1);

//		sm1.control = OFF; // enable to force to run once
	}

//	while(1)
//	{
//
//	}

	return 0;
}
