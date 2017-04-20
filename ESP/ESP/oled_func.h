// oled_func.h

#ifndef _OLED_FUNC_h
#define _OLED_FUNC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Wire.h>  
#include <SSD1306.h> // alias for `#include "SSD1306Wire.h"`

#endif

// Initialize the OLED display using Wire library test
extern SSD1306  display;  //Adaruit HUZZAH: GPIO 4 und 5