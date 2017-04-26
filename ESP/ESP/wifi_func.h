// wifi_func.h

#ifndef _WIFI_FUNC_h
#define _WIFI_FUNC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <ESP8266WiFi.h>
#include <SSD1306.h> // alias for `#include "SSD1306Wire.h"`


#endif

void connect_wifi(void);
void tcp_reconnect(void);
void tcp_talk(void);
void update_oled_wifidata(void);

extern WiFiClient client;
extern SSD1306 display;

extern const char* ssid;
extern const char* password;
extern const char* host;
extern const int Port;

extern String data;
extern String tcp_status;
extern int tcp_connected;
extern String RSSI_Str ;
extern long RSSI_long;

extern char str_begin[];
extern char str_end[];
extern int const i_ClientID;
extern char str_ClientState[14];
extern int i_GotHit;
extern int i_GotHit_by;
extern char str_ServerState[14];
extern int i_CountdownValue;
extern char str_GameMode[30];
extern char str_Team[10];
extern int i_HitAck;
extern char str_GameScore[20];
extern int i_ClientRank;
extern char str_Won[20];
extern int i_ClientPoints;
extern char str_KD[10];