/*
 * sm1.h
 *
 *  Created on: Aug 30, 2019
 *      Author: andri
 */

#ifndef SM1_TOP_H_
#define SM1_TOP_H_

#include "state_machine.h"

// Define States
typedef enum STATE_e {
	STATE_1,
	STATE_2,
	STATE_3,
	MAX_STATE	// Used for counting size of STATE_e
} STATE_e;

// Define Events
typedef enum EVENT_e {
	EVENT_1,
	EVENT_2,
	EVENT_3,
	EVENT_4,
	EVENT_5,
	EVENT_6,
	MAX_EVENT 	// Used for counting size of EVENT_e
} EVENT_e;

// Declare callback functions
void action_s1_e1(void);
void action_s1_e6(void);
void action_s2_e4(void);
void action_s2_e2(void);
void action_s3_e3(void);
void action_s3_e5(void);

// Declare state machine struct
state_machine_t sm1;

// Initialize state machine
void init_sm1(void);

#endif /* SM1_TOP_H_ */
