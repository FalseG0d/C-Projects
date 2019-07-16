#include <ESP8266Wifi.h>
void setup()
{
	Serial.begin(115200);
	Serial.println();
	Wifi.begin("SSID","PSWD");
	Serial.println("Connecting....");
	while(Wifi.status()!=WL_CONNECTED)
		{
		delay(500);
		Serial.print(".");
		}
	Serial.println("Connected");	
	Serial.println(Wifi.localIP());
	Serial.println(Wifi.RSSI());//signal strength
}
void loop()
{
//empty since has to be done only once
}