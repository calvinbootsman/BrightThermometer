/*
 Name:		BrightThermometer.ino
 Created:	6/4/2018 6:51:42 PM
 Author:	calvi
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "WifiSetup.h"

const char* ssid = "Ziggo5694C";
const char* password = "c7f4VvFFMPam";
const char* WiFiAPPSK = "BRIGHT!";

ESP8266WebServer  server(80);

void handleRoot() {
	server.send(200, "text/html", "<form action=\"/Test\">Network name: <br>  <input type = \"text\" name = \"SSID\"><br>Password: <br><input type = \"tex\" name = \"Password\"> <input type=\"submit\" value=\"Submit\"></form>");
}
	void Test() {
	Serial.println("got to test page");
}
// the setup function runs once when you press reset or power the board
void setup() {/*
	Serial.begin(115200);
	Serial.println();
	Serial.print("connecting to ");
	Serial.println(ssid);
	WiFi.mode(WIFI_STA);*/

	Serial.begin(115200);

	WifiSetup setup;
	setup.ScanNetworks();
	WiFi.mode(WIFI_STA);
	WiFi.softAP(WiFiAPPSK, password);
	Serial.println();
	Serial.print("Server IP address: ");
	Serial.println(WiFi.softAPIP());
	Serial.print("Server MAC address: ");
	Serial.println(WiFi.softAPmacAddress());
	server.on("/", handleRoot);
	server.on("/Test", Test);
	server.begin();


	
}

// the loop function runs over and over again until power down or reset
void loop() {
	server.handleClient();
}


