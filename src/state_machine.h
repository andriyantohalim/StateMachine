/*
 * state_machine.h
 *
 *  Created on: Aug 28, 2019
 *      Author: andri
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h> // for rand


typedef enum SM_CTRL_e {
	OFF,
	ON
} SM_CTRL_e;

typedef struct state_machine_t {
	uint8_t current_state;
	uint8_t current_event;
	uint8_t max_state;
	uint8_t max_event;
	SM_CTRL_e control;
	uint8_t next_state[1][1];
	void (*callback_function[1][1])(void);
} state_machine_t;


// Create and intialize state machine data structure, state transition table and callback function pointers table
void sm_create(state_machine_t *sm, uint8_t max_state, uint8_t max_event);

void sm_register_next_state(state_machine_t *sm, uint8_t current_state, uint8_t current_event, uint8_t next_state);
void sm_register_callback_function(state_machine_t *sm, uint8_t current_state, uint8_t current_event, void(*callback_function)(void));

void sm_start(state_machine_t *sm);
void sm_run(state_machine_t *sm);
void sm_stop(state_machine_t *sm);



#endif /* STATE_MACHINE_H_ */
