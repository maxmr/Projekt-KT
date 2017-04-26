#include "FSM.h"


void State_Machine(void)
{
	if (strcmp(str_ClientState, "PRE-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			//update_oled_pregame(); Hier evtl Team Bekanntgabe? Oder Punkteanzeige (also wie viel pkt pro kill oder so?)
			update_oled_wifidata();
		}
	}
	else if (strcmp(str_ClientState, "STARTING-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			//update_oled_startinggame();
			//10Sekunden OLED runterzaehlen -> Funktion von Philipp??	
		}
	}

	else if (strcmp(str_ClientState, "IN-GAME"))
	{
		if (oled_flag == 1)
		{
			if (i_GotHit != 0)
			{
				//update_oled_hit();
			}
			else
			{
				//update_oled_active();
			}
			oled_flag = 0;
		}
	}
	else if (strcmp(str_ClientState, "END-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			// funktion zur Bekanntgabe der Points bzw. Kill/Ratio?
			//update_oled_endgame();
		}
	}
	else
	{
	// kein gültiger state? evlt error_function();
	}
}
