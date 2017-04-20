#include "FSM.h"

int State_Machine(int ok_flag, int stop_flag, int, int, int Zustand_old)
{
	int Zustand;
	switch (Zustand_old)
	{
	case Startup:
		if (stop_flag == 1)
			Zustand = ;
		else if (usart_start == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case In_Game:
		if (stop_flag == 1)
			Zustand = ;
		else if (usart_stop == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case Active:
		if (ok_flag == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case Shot:
		if (ok_flag == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case Out_of_Game:
		if (ok_flag == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case End:
		if (ok_flag == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	case Failmode:
		if (OK_flag == 1)
			Zustand = ;
		else
			Zustand = ;
		break;

	default:
		break;
	}
	return Zustand;
}

/*
State::State(void(*on_enter)(), void(*on_exit)())
: on_enter(on_enter),
on_exit(on_exit)
{
}


Fsm::Fsm(State* initial_state)
: m_current_state(initial_state),
m_transitions(NULL),
m_num_transitions(0)
{
}


Fsm::~Fsm()
{
free(m_transitions);
free(m_timed_transitions);
m_transitions = NULL;
m_timed_transitions = NULL;
}


void Fsm::add_transition(State* state_from, State* state_to, int event,
void(*on_transition)())
{
if (state_from == NULL || state_to == NULL)
return;

Transition transition = Fsm::create_transition(state_from, state_to, event,
on_transition);
m_transitions = (Transition*)realloc(m_transitions, (m_num_transitions + 1)
* sizeof(Transition));
m_transitions[m_num_transitions] = transition;
m_num_transitions++;
}


void Fsm::add_timed_transition(State* state_from, State* state_to,
unsigned long interval, void(*on_transition)())
{
if (state_from == NULL || state_to == NULL)
return;

Transition transition = Fsm::create_transition(state_from, state_to, 0,
on_transition);

TimedTransition timed_transition;
timed_transition.transition = transition;
timed_transition.start = 0;
timed_transition.interval = interval;

m_timed_transitions = (TimedTransition*)realloc(
m_timed_transitions, (m_num_timed_transitions + 1) * sizeof(TimedTransition));
m_timed_transitions[m_num_timed_transitions] = timed_transition;
m_num_timed_transitions++;
}


Fsm::Transition Fsm::create_transition(State* state_from, State* state_to,
int event, void(*on_transition)())
{
Transition t;
t.state_from = state_from;
t.state_to = state_to;
t.event = event;
t.on_transition = on_transition;

return t;
}

void Fsm::trigger(int event)
{
// Find the transition with the current state and given event.
for (int i = 0; i < m_num_transitions; ++i)
{
if (m_transitions[i].state_from == m_current_state &&
m_transitions[i].event == event)
{
m_current_state = m_transitions[i].make_transition();
return;
}
}
}


void Fsm::check_timer()
{
for (int i = 0; i < m_num_timed_transitions; ++i)
{
TimedTransition* transition = &m_timed_transitions[i];
if (transition->transition.state_from == m_current_state)
{
if (transition->start == 0)
{
transition->start = millis();
}
else
{
unsigned long now = millis();
if (now - transition->start >= transition->interval)
{
m_current_state = transition->transition.make_transition();
transition->start = 0;
}
}
}
}
}


State* Fsm::Transition::make_transition()
{
// Execute the handlers in the correct order.
if (state_from->on_exit != NULL)
state_from->on_exit();

if (on_transition != NULL)
on_transition();

if (state_to->on_enter != NULL)
state_to->on_enter();

return state_to;
}
*/
