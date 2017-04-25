// 
// 
// 

#include "oled_func.h"
#include "images.h"
#include "wifi_func.h"

// Initialize the OLED display using Wire library test
SSD1306  display(0x3c, SDA, SCL);  //Adaruit HUZZAH: GPIO 4 und 5

int mode = 0, lifes = 0, munition = 0, points = 0;

char	playerStr[] = { "Player:" }, modeStr[] = { "Mode:" }, dBmStr[] = { "dBm" }, lifeStr[] = { "Lifes:" },
muniStr[] = { "Munition:" }, pointStr[] = { "Points:" };

void update_oled_active(void)
{
	display.clear();
	display.setTextAlignment(TEXT_ALIGN_LEFT);//hallo
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 0, playerStr);
	display.drawString(35, 0, String(i_ClientID));
	display.drawString(48, 0, modeStr);
	display.drawString(80, 0, str_GameMode);
	//display.drawString(85, 0, "RSSI:");
	display.drawString(98, 0, RSSI_Str);
	display.drawString(106, 0, dBmStr);
	display.drawHorizontalLine(0, 49, 128);

	display.drawString(0, 17, lifeStr);
	display.drawString(48, 17, muniStr);
	display.setFont(ArialMT_Plain_16);
	display.drawString(0, 29, String(lifes));
	display.drawString(48, 29, String(munition));

	display.drawHorizontalLine(0, 15, 128);
	display.setFont(ArialMT_Plain_10);
	display.drawString(0, 53, pointStr);
	display.drawString(35, 53, String(i_ClientPoints));
	display.display();
}

void update_oled_hit(void)
{
	display.clear();
	display.drawXbm(0, 0, Skull_Logo_width, Skull_Logo_height, Skull_Logo_bits);
	display.display();
}