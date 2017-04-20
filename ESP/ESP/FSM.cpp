#include "FSM.h"

int State_Machine(char str_ClientState[])
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

