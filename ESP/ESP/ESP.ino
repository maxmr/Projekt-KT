
#include "ticker_func.h"
#include "wifi_func.h"
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <SSD1306.h> // alias for `#include "SSD1306Wire.h"`

const char* ssid = "Spieleserver2";
const char* password = "GotchaWlan";
const char* host = "10.11.12.1";
const int Port = 8888;


// Initialize the OLED display using Wire library test
SSD1306  display(0x3c, SDA, SCL);  //Adaruit HUZZAH: GPIO 4 und 5

void setup()
{
	Serial.begin(115200);
	delay(10);

	display.init();
	// display.flipScreenVertically();
	display.setContrast(255);

	connect_wifi();
	// client.setNoDelay(true);

	// bind function to ticker tasks
	ticker_get_RSSI.attach(0.5, get_RSSI);
	ticker_update_oled.attach(1, update_oled);
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

	//update oled every 1sec
	if (oled_flag == 1)
	{
		update_oled_wifidata();
		oled_flag = 0;
	}

	//send tcp every 300ms
	if (tcp_send_flag == 1)
	{
		tcp_talk();
		tcp_send_flag = 0;
	}

	// important! to give esp time to do background stuff
	yield();


}