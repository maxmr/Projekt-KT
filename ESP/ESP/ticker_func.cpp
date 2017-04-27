// 
// 
// 

#include "ticker_func.h"
#include "FSM.h"
#include "wifi_func.h"

int RSSI_flag = 0;
int oled_flag = 0;
int tcp_send_flag = 0;
int tcp_status_flag = 0;


//create ticker objects
Ticker ticker_get_RSSI;
Ticker ticker_update_oled;
Ticker ticker_tcp_send;
Ticker ticker_tcp_status;
Ticker ticker_hit;

int hit_counter = 0;

// tasks function to set only flags, no long delay, called with ticker with defined intervalls
void get_RSSI()
{
	RSSI_flag = 1;
}

void update_oled(void)
{
	oled_flag = 1;
}

void send_tcp(void)
{
	tcp_send_flag = 1;
}

void get_tcp_status(void)
{
	tcp_status_flag = 1;
}

void got_hit(void)
{
	hit_counter++;
	Serial.println(hit_counter);
	if (hit_counter >= 4)
	{
		hit_timer = 0;
		i_GotHit = 0;
		i_GotHit_by = 0;
		hit_counter = 0;
		ticker_hit.detach();
	}
}

