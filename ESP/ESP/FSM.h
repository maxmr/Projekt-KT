
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
#define Failmode 7

int State_Machine(int ok_flag, int stop_flag, int usart_start, int usart_stop, int Zustand_old);

/*
struct State
{
State(void(*on_enter)(), void(*on_exit)());

void(*on_enter)();
void(*on_exit)();
};


class Fsm
{
public:
Fsm(State* initial_state);
~Fsm();

void add_transition(State* state_from, State* state_to, int event,
void(*on_transition)());

void add_timed_transition(State* state_from, State* state_to,
unsigned long interval, void(*on_transition)());

void trigger(int event);
void check_timer();

private:
struct Transition
{
State* state_from;
State* state_to;
int event;
void(*on_transition)();

State* make_transition();
};
struct TimedTransition
{
Transition transition;
unsigned long start;
unsigned long interval;
};

static Transition create_transition(State* state_from, State* state_to,
int event, void(*on_transition)());

private:
State* m_current_state;
Transition* m_transitions;
int m_num_transitions;

TimedTransition* m_timed_transitions;
int m_num_timed_transitions;
};


#endif
*/
