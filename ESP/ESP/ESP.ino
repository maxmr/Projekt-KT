#include "FSM.h"
#include "ticker_func.h"
#include "wifi_func.h"
#include "oled_func.h"

const char* ssid = "Spieleserver2";
const char* password = "Gotchawlan";
const char* host = "192.168.137.1";
const int Port = 8888;




void setup()
{
	Serial.begin(115200);
	delay(10);
	pinMode(16, INPUT);

	display.init();
	// display.flipScreenVertically();
	display.setContrast(255);
	display.setFont(ArialMT_Plain_10);

	connect_wifi();
	// client.setNoDelay(true);

	// bind function to ticker tasks
	ticker_get_RSSI.attach(0.5, get_RSSI);
	ticker_update_oled.attach(0.5, update_oled);
	ticker_tcp_send.attach_ms(150, send_tcp);
	ticker_tcp_status.attach_ms(100, get_tcp_status);
}

void loop()
{
	//check tcp connectivity every 100ms
	if (tcp_status_flag == 1)
	{
		tcp_connected = client.connected();
		tcp_status_flag = 0;
	}

	//check RSSI every 500ms
	if (RSSI_flag == 1)
	{
		RSSI_long = WiFi.RSSI();
		RSSI_Str = String(RSSI_long);
		RSSI_flag = 0;
	}
	/* verschoben in FSM
	//update oled every 1sec
	if (oled_flag == 1)
	{
		update_oled_wifidata();
		oled_flag = 0;
	}
	*/   

	//send tcp every 300ms
	if (tcp_send_flag == 1)
	{
		tcp_talk();
		tcp_send_flag = 0;
	}

	// statemachine aufrufen
	State_Machine();
	// important! to give esp time to do background stuff
	yield();
	if (digitalRead(16) == HIGH)
	{
		i_GotHit = 1;
		i_GotHit_by = 3;
		hit_timer = 1;
		ticker_hit.attach(1,got_hit);
	}


}