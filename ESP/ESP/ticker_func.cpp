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
int reconnect_check_flag = 0;


//create ticker objects
Ticker ticker_get_RSSI;
Ticker ticker_update_oled;
Ticker ticker_tcp_send;
Ticker ticker_tcp_status;
Ticker ticker_hit;
Ticker ticker_reconnect_check;

int hit_counter = 0;



// tasks function to set only flags, no long delay, called with ticker with defined intervalls
void reconnect_check(void)
{
	reconnect_check_flag = 1;
}

void get_RSSI(void)
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
		//i_GotHit = 0;
		i_GotHit_by = 0;
		hit_counter = 0;
		ticker_hit.detach();
	}
}

void ticker_init(void)
{
	ticker_get_RSSI.attach(0.5, get_RSSI);
	ticker_update_oled.attach(0.25, update_oled);
	ticker_tcp_send.attach_ms(100, send_tcp);
	ticker_tcp_status.attach_ms(50, get_tcp_status);
	ticker_reconnect_check.attach(2, reconnect_check);
}

