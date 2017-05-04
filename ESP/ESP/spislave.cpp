/*
SPI Slave Demo Sketch
Connect the SPI Master device to the following pins on the esp8266:
GPIO    NodeMCU   Name  |   Uno
===================================
15       D8       SS   |   D10
13       D7      MOSI  |   D11
12       D6      MISO  |   D12
14       D5      SCK   |   D13
Note: If the ESP is booting at a moment when the SPI Master has the Select line HIGH (deselected)
the ESP8266 WILL FAIL to boot!
See SPISlave_SafeMaster example for possible workaround
*/

#include "spislave.h"

ESPSlave spi;

void ESPSlave::init()
{
	// data has been received from the master. Beware that len is 
	onData([](uint8_t * data, size_t len) {
		if (len > sizeof(spi.data))
		{
			len = sizeof(spi.data);
		}
		memcpy(spi.data, data, len);

		spi.counter++;
		spi.spi_received = 1;
	});
	data[32] = 0;
	begin();
}

void ESPSlave::writeData(const char* data)
{
	setData(data);
}

int ESPSlave::readData()
{
	return atoi(data);
}