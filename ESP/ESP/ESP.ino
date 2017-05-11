#include <hspi_slave.h>
#include "spislave.h"
#include "FSM.h"
#include "ticker_func.h"
#include "wifi_func.h"
#include "oled_func.h"

const char* ssid = "Spieleserver2";
const char* password = "Gotchawlan";
const char* host = "10.11.12.1";
const int Port = 10000;
const int Amount_Players = 16;

void setup()
{
	Serial.begin(115200);
	delay(10);
	//pinMode(16, INPUT);		//for debuging spi, not urgent anymore
	
	//Output pins for MOSFETs for RGBs
	pinMode(16, OUTPUT);	    //for rgb colour red
	pinMode(2, OUTPUT);			//for rgb colour blue

	display.init();
	// display.flipScreenVertically();
	display.setContrast(255);
	display.setFont(ArialMT_Plain_10);

	connect_wifi();
	// client.setNoDelay(true);
	// bind function to ticker tasks
	ticker_init();
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
		if (reconnect_check_flag == 1)
		{
			if (RSSI_long < -80)
			{
				Serial.println("start reconnect");
				WiFi.reconnect();
			}
			reconnect_check_flag = 0;
		}
	}
	//send tcp every 300ms
	if (tcp_send_flag == 1)
	{
		tcp_talk();
		tcp_send_flag = 0;
	}
	//for testing without spi
	/*/
	if (digitalRead(16) == HIGH)
	{
		i_GotHit = 1;
		i_GotHit_by = 3;
		hit_timer = 1;
		ticker_hit.attach(1, got_hit);
	}
	/*/
	if (spi.spi_received == 1)		
	{
		i_GotHit = 1;
		i_GotHit_by = spi.readData();
		Serial.println(i_GotHit_by);
		if (i_GotHit_by > Amount_Players)
		{
			i_GotHit = 0;
			i_GotHit_by = 0;
		}
		else
		{
			hit_timer = 1;
			ticker_hit.attach(1, got_hit);
			spi.spi_received = 0;
		}
	}
	
	// statemachine aufrufen
	State_Machine();
	// important! to give esp time to do background stuff
	yield();
}