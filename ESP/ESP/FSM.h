
#ifndef FSM_H
#define FSM_H


#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>		//for older Arduino versions
#endif

#endif

//States
#define Startup 1
#define In_Game 2
#define Active 3
#define Shot 4
#define Out_of_Game 5
#define End 6
#define Failmode7 

int State_Machine(char str_ClientState[]);

