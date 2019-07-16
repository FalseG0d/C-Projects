#include <SoftwareSerial.h>
SoftwareSerial esp8266(2,3);// pins of rx and tx P.S. I might be wrong about the pin numbers to change them accordingly
void setup(){
Serial.begin(9600);// board rate of Arduino mega
esp8266.begin(115200);// board rate of ESP8266

}
void loop()
{
char c;
if(esp8266.available())
	{
	while(esp8266.available)//to read data
		{
		c=esp8266.read();
		Serial.write(c);
		}
	}
delay(1000);
String command="";
if(esp8266.available())
	{
	while(Serial.available)//to send
		{
		command+=(char)Serial.read();
		}
	esp8266.println(command);
	}
}