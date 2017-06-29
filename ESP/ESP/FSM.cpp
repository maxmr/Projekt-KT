#include "FSM.h"
#include "wifi_func.h" 
#include"ticker_func.h"
#include "oled_func.h"

int hit_timer = 0;

void RGB_on()
{
	if (strcmp(str_Team, "RED") == 0)
	{
		digitalWrite(16, 1);
		digitalWrite(2, 0);
	}
	else if (strcmp(str_Team, "BLUE") == 0)
	{
		digitalWrite(16, 0);
		digitalWrite(2, 1);
	}
	digitalWrite(0, 1);
}

void RGB_off()
{

		digitalWrite(16, 0);
		digitalWrite(2, 0);
		digitalWrite(0, 0);
	
}

void RGB_end()
{

	digitalWrite(16, 1);
	digitalWrite(2, 1);
	digitalWrite(0, 0);

}




void State_Machine(void)
{
	strcpy(str_ClientState, str_ServerState);
	if (WiFi.status() != WL_CONNECTED)
		strcpy(str_ClientState, "NOT-CONNECTED");
	if (tcp_connected == 0)
		strcpy(str_ClientState, "PRE-GAME");
	if (strcmp(str_ClientState, "PRE-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_pregame();
			RGB_off();
		}
	}
	else if (strcmp(str_ClientState, "STARTING-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_start();
			RGB_off();
		}
	}

	else if (strcmp(str_ClientState, "IN-GAME")==0)
	{
		if (oled_flag == 1)
		{
			if (hit_timer != 0)
			{
				update_oled_hit();
				RGB_off();
			}
			else
			{
				if (strcmp(str_GameMode, "Team Deathmatch") == 0)
					update_oled_active_TM();
				else 	if (strcmp(str_GameMode, "Free For All") == 0)
					update_oled_active_FFA();
				else
					update_oled_active_TM();

				RGB_on();
			}
			oled_flag = 0;
		}
	}
	else if (strcmp(str_ClientState, "POST-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			if (strcmp(str_GameMode, "Team Deathmatch") == 0)
				update_oled_end_TM();
			else 	if (strcmp(str_GameMode, "Free For All") == 0)
				update_oled_end_FFA();
			else
				update_oled_end_TM();
			RGB_end();
		}	
	}
	else if (strcmp(str_ClientState, "NOT-CONNECTED") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_disconnected();
			RGB_off();
		}
	}
	else
	{
		Serial.println(str_ClientState);
		RGB_off();
	}
}
