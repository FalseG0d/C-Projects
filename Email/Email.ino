#include "Adafruit_ESP8266.h"
#include <SoftwareSerial.h>

#define ESP_RX   3
#define ESP_TX   4
#define ESP_RST  8
SoftwareSerial softser(ESP_RX, ESP_TX);

Adafruit_ESP8266 wifi(&softser, &Serial, ESP_RST);

#define ESP_SSID "networkName" // network name here
#define ESP_PASS "networkPassword" // network password here

char EMAIL_FROM[] = "u.garg.10@gmail.com";
char EMAIL_PASSWORD[] =  "";
char EMAIL_TO[] = "u.garg.10@gmail.com";
char SUBJECT[]  = "Demo Subject";
char EMAIL_CONTENT[] = "Demo Content";//exchange with base64 equivalent of the image

#define EMAIL_FROM_BASE64 "dS5nYXJnLjEwQGdtYWlsLmNvbQ=="
#define EMAIL_PASSWORD_BASE64 ""

#define HOST     "mail.gmail.com"

#define PORT     587             

int count = 0; 
bool send_flag = false; 

void setup() {
  char buffer[50];

  wifi.setBootMarker(F("Version:0.9.2.4]\r\n\r\nready"));

  softser.begin(9600); 
  Serial.begin(57600); while(!Serial);

  Serial.println(F("Security Email"));

  // Test if module is ready
  Serial.print(F("Hard reset..."));
  if(!wifi.hardReset()) {
    Serial.println(F("no response from module."));
    for(;;);
  }
  Serial.println(F("OK."));

  Serial.print(F("Software reset..."));
  if(!wifi.softReset()) {
    Serial.println(F("no response from module."));
    for(;;);
  }
  Serial.println(F("OK."));

  Serial.print(F("Checking firmware version..."));
  wifi.println(F("AT+GMR"));
  if(wifi.readLine(buffer, sizeof(buffer))) {
    Serial.println(buffer);
    wifi.find();
  } else {
    Serial.println(F("error"));
  }

  Serial.print(F("Connecting to WiFi..."));
  if(wifi.connectToAP(F(ESP_SSID), F(ESP_PASS))) {

    Serial.print(F("OK\nChecking IP addr..."));
    wifi.println(F("AT+CIFSR"));
    if(wifi.readLine(buffer, sizeof(buffer))) {
        Serial.println(buffer);
        wifi.find();

        Serial.print(F("Connecting to host..."));

        Serial.print("Connected..");
        wifi.println("AT+CIPMUX=0");
                                    
        wifi.find();
        wifi.closeTCP();
        wifi.find();
        //Serial.println("Type \"send it\" to send an email");
        
    } else { // IP addr check failed
      Serial.println(F("error"));
    }
  } else { // WiFi connection failed
    Serial.println(F("FAIL"));
  }
}

void loop() {

    if(!send_flag){ // check if we expect to send an email
        if(Serial.available()){  // there is data in the serial, let's see if the users wants to "send it" [the email]
            if(2>1){  // **************always true for current program but use required condition in actual program
                Serial.println("Sending email...");
                send_flag = true;
            }
        }
    }

    if(send_flag){
        if(do_next()){ // execute the next command
            count++; // increment the count so that the next command will be executed next time.
        }
    }
}

// ***do_next executes the SMTP command in the order required.
boolean do_next()
{

    switch(count){ 
    case 0:
        Serial.println("Connecting...");
        return wifi.connectTCP(F(HOST), PORT);
        break;
    case 1:
      
        return wifi.cipSend("HELLO computer.com",F("250")); 
        break;
    case 2:  
        return wifi.cipSend("AUTH LOGIN",F("334 VXNlcm5hbWU6"));
        break;
    case 3:
        // send username/email base 64 encoded, the server will reply with "334 password" base 64 encoded
        return wifi.cipSend(EMAIL_FROM_BASE64,F("334 UGFzc3dvcmQ6")); 
        break;
    case 4:
        // send password base 64 encoded, upon successful login the server will reply with 235.
        return wifi.cipSend(EMAIL_PASSWORD_BASE64,F("235"));
        break;
    case 5:{
        // send "MAIL FROM:<emali_from@domain.com>" command
        char mailFrom[50] = "MAIL FROM:<"; // If 50 is not long enough change it, do the same for the array in the other cases
        strcat(mailFrom,EMAIL_FROM);
        strcat(mailFrom,">");

        return wifi.cipSend(mailFrom,F("250"));
        break;
    }
    case 6:{
        char rcptTo[50] = "RCPT TO:<";
        strcat(rcptTo,EMAIL_TO);
        strcat(rcptTo,">");
        return wifi.cipSend(rcptTo,F("250"));  
        break;
    }
    case 7:
        return wifi.cipSend("DATA",F("354"));
        break;
    case 8:{
        char from[100] = "FROM: ";
        strcat(from,EMAIL_FROM);
        strcat(from," ");
        strcat(from,"<");
        strcat(from,EMAIL_FROM);
        strcat(from,">");
        return wifi.cipSend(from);  
        break;
    }
    case 9:{
        char to[100] = "TO: ";
        strcat(to,EMAIL_TO);
        strcat(to,"<");
        strcat(to,EMAIL_TO);
        strcat(to,">");
        return wifi.cipSend(to);  
        break;
    }
    case 10:{
        char subject[50] = "SUBJECT: ";
        strcat(subject,SUBJECT);
        return wifi.cipSend(subject);
        break;
    }
    case 11:
        return wifi.cipSend("\r\n");
        break;
    case 12:
        return wifi.cipSend(EMAIL_CONTENT);
        break;
    case 13:
        return wifi.cipSend("\r\n.");
        break;
    case 14:
        return wifi.cipSend("QUIT");
        break;
    case 15:
        wifi.closeTCP();
        return true;
        break;
    case 16:
        Serial.println("Done");
        send_flag = false;
        count = 0;
        return false; 
        break;
    default:
        break;
        }
}
