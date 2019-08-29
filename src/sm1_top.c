/*
 * sm1.c
 *
 *  Created on: Aug 30, 2019
 *      Author: andri
 */

#include "sm1_top.h"


void action_s1_e1(void)
{
	// Do something here
	printf("Hello from S1E1\n");
	// Do something here
}

void action_s1_e6(void)
{
	// Do something here
	printf("Hello from S1E6\n");
	// Do something here
}

void action_s2_e4(void)
{
	// Do something here
	printf("Hello from S2E4\n");
	// Do something here
}

void action_s2_e2(void)
{
	// Do something here
	printf("Hello from S2E2\n");
	// Do something here
}

void action_s3_e3(void)
{
	// Do something here
	printf("Hello from S3E3\n");
	// Do something here
}

void action_s3_e5(void)
{
	// Do something here
	printf("Hello from S3E5\n");
	// Do something here
}

// The following void init_sm1(void) practically the same as making the following table:

// 2D DATA array for NEXT STATE
//STATE_e next_state[MAX_STATE][MAX_EVENT])(void) = {
//	{STATE_2, 		MAX_STATE, 		MAX_STATE, 		MAX_STATE, 			MAX_STATE, 			STATE_3},		// Next state for STATE_1 events
//	{MAX_STATE, 	STATE_3, 		MAX_STATE, 		STATE_2, 			MAX_STATE, 			MAX_STATE}, 			// Next state for STATE_2 events
//	{MAX_STATE,		MAX_STATE,		STATE_1, 		MAX_STATE,			STATE_2,			MAX_STATE} 			// Next state for STATE_3 events
//};

// 2D FUNCTION POINTER array for ACTION FUNCTIONS
//void (*state_transition[MAX_STATE][MAX_EVENT])(void) = {
//	{action_s1_e1, 		NULL, 			NULL, 			NULL, 			NULL, 			action_s1_e6},	// Procedures for STATE_1
//	{NULL, 				action_s2_e4, 	NULL, 			action_s2_e2, 	NULL, 			NULL}, 			// Procedures for STATE_2
//	{NULL,				NULL,			action_s3_e3, 	NULL,			action_s3_e5,	NULL} 			// Procedures for STATE_3
//};

void init_sm1(void)
{
	sm_create(&sm1, MAX_STATE, MAX_EVENT);

	sm_register_next_state(&sm1, STATE_1, EVENT_1, STATE_2);
	sm_register_callback_function(&sm1, STATE_1, EVENT_1, action_s1_e1);

	sm_register_next_state(&sm1, STATE_1, EVENT_6, STATE_3);
	sm_register_callback_function(&sm1, STATE_1, EVENT_6, action_s1_e6);

	sm_register_next_state(&sm1, STATE_2, EVENT_4, STATE_2);
	sm_register_callback_function(&sm1, STATE_2, EVENT_4, action_s2_e4);

	sm_register_next_state(&sm1, STATE_2, EVENT_2, STATE_3);
	sm_register_callback_function(&sm1, STATE_2, EVENT_2, action_s2_e2);

	sm_register_next_state(&sm1, STATE_3, EVENT_3, STATE_1);
	sm_register_callback_function(&sm1, STATE_3, EVENT_3, action_s3_e3);

	sm_register_next_state(&sm1, STATE_3, EVENT_5, STATE_2);
	sm_register_callback_function(&sm1, STATE_3, EVENT_5, action_s3_e5);
}
