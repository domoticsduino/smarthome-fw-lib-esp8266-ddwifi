/* 1.0.0 VERSION */

#ifndef ddwifi_h
#define ddwifi_h

#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "ddcommon.h"

class DDWifi
{

private:
	const char *_ssid;
	const char *_password;
	const char *_hostname;
	int _led;

public:
	DDWifi(const char *, const char *, const char *, int);
	void connect();
};

#endif