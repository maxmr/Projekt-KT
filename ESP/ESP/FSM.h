
#ifndef FSM_H
#define FSM_H



#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>		//for older Arduino versions
#endif

#endif

//States


void State_Machine(void);
void RGB_on(void);
void RGB_off(void);
void RGB_end(void);
void ard_en_off(void);
void ard_en_on(void);
extern int hit_timer;
