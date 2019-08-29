/*
 * state_machine.c
 *
 *  Created on: Aug 28, 2019
 *      Author: andri
 */


#include "state_machine.h"

#include <stdio.h>
#include <stdlib.h>


void sm_create(state_machine_t *sm, uint8_t max_state, uint8_t max_event)
{
	sm->max_state = max_state;
	sm->max_event = max_event;

	for (uint8_t i = 0; i < sm->max_state; i++)
	{
		for(uint8_t j = 0; j < sm->max_event; j++)
		{
			sm->next_state[i][j] = sm->max_state;
			sm->callback_function[i][j] = NULL;
		}
	}
}

void sm_register_next_state(state_machine_t *sm, uint8_t current_state, uint8_t current_event, uint8_t next_state)
{
	if(sm->next_state[current_state][current_event] == sm->max_state)
	{
		sm->next_state[current_state][current_event] = next_state;
	}
}

void sm_register_callback_function(state_machine_t *sm, uint8_t current_state, uint8_t current_event, void(*callback_function)(void))
{
	if(sm->callback_function[current_state][current_event] == NULL)
	{
		sm->callback_function[current_state][current_event] = callback_function;
	}
}

void sm_start(state_machine_t *sm)
{
	sm->control = ON;
}

void sm_run(state_machine_t *sm)
{
	sm->current_event = rand() % 6; // try to get new event

	if(((sm->current_state >= 0) && (sm->current_state < sm->max_state)) && ((sm->current_event >= 0) && (sm->current_event < sm->max_event)))
	{
		if(sm->callback_function[sm->current_state][sm->current_event] != NULL)
		{
			sm->callback_function[sm->current_state][sm->current_event](); // execute callback function
			sm->current_state = sm->next_state[sm->current_state][sm->current_event]; // update state
		}
	}
	else
	{
		/* @TODO: invalid state/event. */
	}
}

void sm_stop(state_machine_t *sm)
{
	sm->control = OFF;
}
