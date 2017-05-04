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
pointStr[] = { "Points:" }, str_hitBy[] = { "Hit by: Player " };

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

void update_oled_active(void)
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
	display.drawString(0, 53, pointStr);
	display.drawString(35, 53, String(i_ClientPoints));
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
