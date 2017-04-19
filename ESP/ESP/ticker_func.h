// ticker_func.h

#ifndef _TICKER_FUNC_h
#define _TICKER_FUNC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Ticker.h>

#endif

void get_RSSI();
void update_oled(void);
void send_tcp(void);
void get_tcp_status(void);

extern int RSSI_flag;
extern int oled_flag;
extern int tcp_send_flag;
extern int tcp_status_flag;

//create ticker objects
extern Ticker ticker_get_RSSI;
extern Ticker ticker_update_oled;
extern Ticker ticker_tcp_send;
extern Ticker ticker_tcp_status;