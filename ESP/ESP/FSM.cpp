#include "FSM.h"
#include "wifi_func.h" 
#include"ticker_func.h"
#include "oled_func.h"

int hit_timer = 0;

void State_Machine(void)
{
	strcpy(str_ClientState, str_ServerState);
	if (WiFi.status() != WL_CONNECTED)
		strcpy(str_ClientState, "NOT-CONNECTED");
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
			update_oled_start();
		
		}
	}

	else if (strcmp(str_ClientState, "IN-GAME")==0)
	{
		Serial.print("oled_flag: ");
		Serial.println(oled_flag);
		Serial.print("hit_timer: ");
		Serial.println(hit_timer);

		if (oled_flag == 1)
		{
			if (hit_timer != 0)
			{
				update_oled_hit();
			}
			else
			{
				update_oled_active();
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
	else if (strcmp(str_ClientState, "NOT-CONNECTED") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_disconnected();
		}
	}
	else
	{
	// kein gültiger state? evlt error_function();
		Serial.println(str_ClientState);
	}
}
