#include "FSM.h"
#include "oled_func.h"
#include "images.h"

void State_Machine(void)
{
	if (strcmp(str_ClientState, "PRE_GAME") == 0)
	{
		//update_oled_pregame(); Hier evtl Team Bekanntgabe? Oder Punkteanzeige (also wie viel pkt pro kill oder so?)
	}
	else if (strcmp(str_ClientState, "STARTING_GAME") == 0)
	{
		//10Sekunden OLED runterzaehlen -> Funktion von Philipp??				
	else if (strcmp(str_ClientState, "IN_GAME"))
	{
		update_oled_active(); 
		if (i_GotHit != 0)
		{
			update_oled_hit(); 
		}
	}
	else if (strcmp(str_ClientState, "END_GAME") == 0)
	{
		// funktion zur Bekanntgabe der Points bzw. Kill/Ratio?
	}
	else
	{
		// Funktion das Verbindung abgebrochen ist? 
		// oder versuchen neue verbindung aufzubauen?
	}
}
