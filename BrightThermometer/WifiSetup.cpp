#include "WifiSetup.h"
#include<bits/stdc++.h>
#include <string>  
#include <iostream>  
#include <ESP8266WebServer.h>
#include <vector>

WifiSetup::WifiSetup()
{
	std::vector<String> ScanNetworks();
}

std::vector<String> WifiSetup::ScanNetworks()
{
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);
	std::vector <String> networks;
	String network;
	int n = WiFi.scanNetworks();
	Serial.println("scan done");
	if (n == 0) {
		Serial.println("no networks found");
	}
	else {
		Serial.print(n);
		Serial.println(" networks found");
		for (int i = 0; i < n; ++i) {
			// Print SSID and RSSI for each network found
			network = WiFi.SSID(i);
			Serial.print(i + 1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(" (");
			Serial.print(WiFi.RSSI(i));
			Serial.print(")");
			Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
			delay(10);
			networks.push_back(network);
		}
	}
	Serial.println("");
	return networks;
}