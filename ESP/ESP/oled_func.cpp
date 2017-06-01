// 
// 
// 

#include "oled_func.h"
#include "images.h"
#include "wifi_func.h"
//
// Initialize the OLED display using Wire library test
SSD1306  display(0x3c, SDA, SCL);  //Adaruit HUZZAH: GPIO 4 und 5

char	playerStr[] = { "Player:" }, dBmStr[] = { "dBm" }, rankStr[] = { "Rank:" },
pointStr[] = { "Points:" }, str_hitBy[] = { "Hit by: Player " }, scoreStr[] = { "Score:" }, lifeStr[] = { "Lifes:" }, strKD[] = { "K/D:" };

void update_oled_start()
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_16);
	display.drawString(64, 5, str_GameMode);
	display.setFont(Arimo_40);
	display.drawString(64, 22, String(i_CountdownValue));
	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_10);
	display.drawString(90, 50, str_Team);
	display.display();
}

void update_oled_disconnected()
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_10);
	display.drawString(64, 5, str_ClientState);
	display.setFont(ArialMT_Plain_10);
	display.drawString(64, 25,"reconnecting...");
	display.display();
}

void update_oled_active_TM(void)
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 0, playerStr);
	display.drawString(33, 0, String(i_ClientID));
	display.drawString(106, 0, dBmStr);
	display.drawString(90, 0, String(RSSI_Str));
	display.drawHorizontalLine(0, 49, 128);

	display.drawString(90, 18, rankStr);
	display.setFont(ArialMT_Plain_16);
	display.drawString(0, 23, str_GameClock);
	display.drawString(90, 30, String(i_ClientRank));
	display.drawHorizontalLine(0, 15, 128);

	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 53, scoreStr);
	display.drawString(40, 53, str_GameScore);
	display.drawString(90, 50, str_Team);
	display.display();
}

void update_oled_active_FFA(void)
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 0, playerStr);
	display.drawString(33, 0, String(i_ClientID));
	display.drawString(106, 0, dBmStr);
	display.drawString(90, 0, String(RSSI_Str));
	display.drawHorizontalLine(0, 49, 128);

	display.drawString(90, 18, rankStr);
	display.setFont(ArialMT_Plain_16);
	display.drawString(0, 23, str_GameClock);
	display.drawString(90, 30, String(i_ClientRank));
	display.drawHorizontalLine(0, 15, 128);

	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 53, lifeStr);
	display.drawString(40, 53, String(i_ClientLife));
	display.drawString(90, 50, str_Team);
	display.display();
}

void update_oled_hit(void)
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_10);
	display.drawString(60, 50, str_hitBy);
	display.drawString(100, 50, String(i_GotHit_by));
	display.drawXbm(16, 0, Skull_Logo_width, Skull_Logo_height, Skull_Logo_bits);
	display.display();
}

void update_oled_end_TM(void)
{
	display.clear();

	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_24);
	display.drawString(64, 0, String(str_Won));
	display.drawHorizontalLine(0, 25, 128);
	display.drawVerticalLine(64, 25, 71);

	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 27, pointStr);
	display.drawString(33, 27, String(i_ClientPoints));

	display.drawString(0, 47, scoreStr);
	display.drawString(33, 47,str_GameScore );

	display.drawString(68, 27, strKD);
	display.drawString(92, 27, str_KD);

	display.drawString(68, 47, rankStr);
	display.drawString(100, 47, String(i_ClientRank));


	display.display();
}

void update_oled_end_FFA(void)
{
	display.clear();

	display.setTextAlignment(TEXT_ALIGN_CENTER);
	display.setFont(ArialMT_Plain_24);
	display.drawString(64, 0, String(str_Won));
	display.drawHorizontalLine(0, 25, 128);
	display.drawVerticalLine(64, 25, 71);

	display.setTextAlignment(TEXT_ALIGN_LEFT);
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 27, pointStr);
	display.drawString(33, 27, String(i_ClientPoints));

	display.drawString(0, 47, lifeStr);
	display.drawString(33, 47, String(i_ClientLife));

	display.drawString(68, 27, strKD);
	display.drawString(92, 27, str_KD);

	display.drawString(68, 47, rankStr);
	display.drawString(100, 47, String(i_ClientRank));


	display.display();
}

void update_oled_pregame(void)
{
	display.clear();
	display.drawString(0, 0, "Wifi connected");
	display.drawString(0, 12, "IP address: ");
	String IP = WiFi.localIP().toString();
	display.drawString(0, 24, IP);
	display.drawString(80, 24, "ID: ");
	display.drawString(100, 24, String(i_ClientID));
	display.drawString(0, 36, "RSSI: ");
	display.drawString(40, 36, RSSI_Str);
	display.drawString(65, 36, "dBm");
	display.drawString(0, 48, tcp_status);
	display.display();
}