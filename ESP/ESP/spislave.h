#pragma once

#include <SPISlave.h>

class ESPSlave : public SPISlaveClass {
private:
	char data[33];
public:
	int counter = 0;
	int spi_received = 0;
	ESPSlave() : SPISlaveClass() {}

	void init();
	void writeData(const char* data);
	int readData();
};

extern ESPSlave spi;