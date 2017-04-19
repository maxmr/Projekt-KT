// 
// 
// 

#include "wifi_func.h"
#include <string.h>

WiFiClient client;

String tcp_status = "TCP not connected";
int tcp_connected = 0;
String RSSI_Str = "XX";
long RSSI_long = 0;

char str_dataSend[200];
char str_dataReceive[200];

char str_begin[] = "BEGIN";
char str_end[] = "END!";
static const int i_ClientID = 1;
char str_ClientState[14] = "PRE-GAME";
int i_GotHit = 0;
int i_GotHit_by = 0;
char str_ServerState[14] = "X";
int i_CountdownValue;
char str_GameMode[30] = "X";
char str_Team[10] = "X";
int i_HitAck = 0;
char str_GameScore[20]  = "X";
int i_ClientRank = 0;
char str_Won[20] = "X";
int i_ClientPoints = 0;
char str_KD[10] = "X";



void connect_wifi(void)
{
	display.drawString(0, 0, "Connecting to ");
	display.drawString(0, 12, ssid);
	display.display();

	// We start by connecting to a WiFi network

	Serial.println();
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	display.clear();
	display.drawString(0, 0, "Wifi connected");
	display.drawString(0, 12, "IP address: ");
	String IP = WiFi.localIP().toString();
	display.drawString(0, 24, IP);
	display.display();
}

void build_send_string(void)
{
	char buffer[20];
	strcpy(str_dataSend, str_begin);
	strcat(str_dataSend, "_");

	itoa(i_ClientID, buffer, 10);
	strcat(str_dataSend, buffer);
	strcat(str_dataSend, "_");

	strcat(str_dataSend, str_ClientState);
	strcat(str_dataSend, "_");

	itoa(i_GotHit, buffer, 10);
	strcat(str_dataSend, buffer);
	strcat(str_dataSend, "_");

	itoa(i_GotHit_by, buffer, 10);
	strcat(str_dataSend, buffer);
	strcat(str_dataSend, "_");
	strcat(str_dataSend, str_end);
}

void parse_receive_string(String tcp_receive)
{
	tcp_receive.toCharArray(str_dataReceive, 200);
	char *p_str;
	char *saveptr;

	p_str = strtok_r(str_dataReceive, "_", &saveptr);			// take first token
	if (p_str != NULL  && strcmp(p_str, str_begin) == 0	)		 // check for first token begins with "BEGIN"
	{
		p_str = strtok_r(NULL, "_", &saveptr); 
		if (p_str != NULL && atoi(p_str) == i_ClientID)			 // check next token has the right clientID inside
		{
			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)					
				strcpy(str_ServerState, p_str);			//get Server State

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				i_CountdownValue = atoi(p_str);			//get CountdownValue

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				strcpy(str_GameMode, p_str);			//get GameMode

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				strcpy(str_Team, p_str);			//get Team

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				i_HitAck = atoi(p_str);		//get HitAcknowledge

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				strcpy(str_GameScore, p_str);			//get Game Score

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				i_ClientRank = atoi(p_str);		// get Client Rank

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				strcpy(str_Won, p_str);			//get Won Information

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				i_ClientPoints = atoi(p_str);		//get Clients Points

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL)
				strcpy(str_KD, p_str);			//get Kill Death Ratio

			p_str = strtok_r(NULL, "_", &saveptr);
			if (p_str != NULL && strcmp(p_str, "END") == 0)
				Serial.println("Parse finished successfull");
		}		
	}
}

void tcp_talk(void)
{
	//send data if connected to tcp-server
	if (tcp_connected == 1)
	{
		tcp_status = "TCP connected";
		build_send_string();
		Serial.print("data to send: ");
		Serial.println(str_dataSend);

		// This will send the request to the server
		client.print(str_dataSend);

		while (client.available())
		{
			String line = client.readStringUntil('!');
			client.flush();

			Serial.println(line);
			parse_receive_string(line);
		}
		yield();
		Serial.println(i_ClientID);
		Serial.println(str_ServerState);
		Serial.println(i_GotHit);
		Serial.println(i_GotHit_by);

		Serial.println(i_CountdownValue);
		Serial.println(str_GameMode);
		Serial.println(str_Team);
		Serial.println(i_HitAck);
		Serial.println(str_GameScore);
		Serial.println(i_ClientRank);
		Serial.println(str_Won);
		Serial.println(i_ClientPoints);
		Serial.println(str_KD);
	}
	// else try to reconnect
	else
	{
		tcp_reconnect();
	}
		
}

void tcp_reconnect(void)
{
	tcp_status = "TCP not connected";
	Serial.print("connecting to ");
	Serial.println(host);

	if (client.connect(host, Port))
	{
		Serial.println("connected to: ");
		Serial.println(host);
	}
	else
		Serial.println("connection failed");

}

//just for debugging in development
void update_oled_wifidata(void)
{
	display.clear();
	display.drawString(0, 0, "Wifi connected");
	display.drawString(0, 12, "IP address: ");
	String IP = WiFi.localIP().toString();
	display.drawString(0, 24, IP);
	display.drawString(0, 36, "RSSI: ");
	display.drawString(40, 36, RSSI_Str);
	display.drawString(65, 36, "dBm");
	display.drawString(0, 48, tcp_status);
	display.display();
}
