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
}

void RGB_off()
{
	if (i_GotHit == 1)
	{
		digitalWrite(16, 0);
		digitalWrite(2, 0);
	}
}

void RGB_end()
{
	if (i_GotHit == 1)
	{
		digitalWrite(16, 1);
		digitalWrite(2, 1);
	}
}
/*
void ard_en_on()
{
	digitalWrite(0, 1);
}

void ard_en_off()
{
	digitalWrite(0, 0);
}
*/
void State_Machine(void)
{
	strcpy(str_ClientState, str_ServerState);
	//ard_en_off();
	if (WiFi.status() != WL_CONNECTED)
		strcpy(str_ClientState, "NOT-CONNECTED");
	if (tcp_connected == 0)
		strcpy(str_ClientState, "PRE-GAME");
	if (strcmp(str_ClientState, "PRE-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			//update_oled_pregame(); Hier evtl Team Bekanntgabe? Oder Punkteanzeige (also wie viel pkt pro kill oder so?)
			update_oled_wifidata();
			RGB_off();
			//ard_en_off();
		}
	}
	else if (strcmp(str_ClientState, "STARTING-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_start();
			//hier rgb teamfarbe ansteuern.		
			//RGB_on();
			RGB_off();
			//ard_en_off();
		}
	}

	else if (strcmp(str_ClientState, "IN-GAME")==0)
	{
	/*	Serial.print("oled_flag: ");
		Serial.println(oled_flag);
		Serial.print("hit_timer: ");
		Serial.println(hit_timer);*/

		if (oled_flag == 1)
		{
			if (hit_timer != 0)
			{
				update_oled_hit();
				//rgb' s ausschalten
				RGB_off();
				//ard_en_off();
			}
			else
			{
				update_oled_active();
				//rgb' s einschalten
				RGB_on();
				//ard_en_on();
			}
			oled_flag = 0;
		}
	}
	else if (strcmp(str_ClientState, "END-GAME") == 0)
	{
		if (oled_flag == 1)
		{
			//funktion zur Bekanntgabe der Points bzw. Kill/Ratio?
			//hier ruecksetzen der rgb farben machen!!! bzw. ausmachen!!! 
			//update_oled_endgame();
			//RGB_end();
			RGB_off();
			//ard_en_off();
		}	
	}
	else if (strcmp(str_ClientState, "NOT-CONNECTED") == 0)
	{
		if (oled_flag == 1)
		{
			update_oled_disconnected();
			RGB_off();
			//ard_en_off();
		}
	}
	else
	{
	// kein gültiger state? evlt error_function();
		Serial.println(str_ClientState);
		RGB_off();
	}
}
