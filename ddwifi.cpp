/* 1.0.0 VERSION */

#include "ddwifi.h"

DDWifi::DDWifi(const char *ssid, const char *password, const char *hostname, int led)
{

	this->_ssid = ssid;
	this->_password = password;
	this->_hostname = hostname;
	this->_led = led;
}

void DDWifi::connect()
{

	WiFi.mode(WIFI_STA);

	WiFi.begin(this->_ssid, this->_password);
	WiFi.hostname(this->_hostname);

	writeToSerial("Connecting to WiFi ", false);
	writeToSerial(this->_ssid, true);

	while (WiFi.status() != WL_CONNECTED)
	{

		digitalWrite(this->_led, HIGH);
		delay(500);
		digitalWrite(this->_led, LOW);
		writeToSerial(".", false);
	}

	writeToSerial("", true);
	writeToSerial("Connected to ", false);
	writeToSerial(this->_ssid, true);
	writeToSerial("IP address: ", false);
	writeToSerial(WiFi.localIP().toString(), true);
}