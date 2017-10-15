#define DEBUG_MODE

#include "lib/constants.hpp"

#include <Home.h>
//#include "./lib/pins_uno.hpp"
#ifdef DEBUG_MODE
#include "./lib/pins_test.hpp"
#else
#include "lib/pins_mega.hpp"
#endif

#include "lib/Home.h"
//#include "lib/Storage.h"   //ST
#include "lib/Hallway.h"   //HL
#include "lib/Bathroom.h"  //BT
//#include "lib/Kitchen.h"   //KH
//#include "lib/Balcony.h"   //BL
//#include "lib/Bedroom.h"   //BD

#include "lib/Home.cpp"

char buffer[4];

void listen() { 
	CURRENT_TIME = millis();
	Home::listen();
	//Serial.println(analogRead(A0));
}

void setup() {
	Serial.begin(9600);
	while (!Serial);
#ifdef DEBUG_MODE
	Serial.println("start");
#endif
	CURRENT_TIME = millis();
	Home::setup();
	delay(1000);
	Home::command(C_STATE);
	delay(1000);
	MsTimer2::set(40, listen);
	MsTimer2::start();
	delay(1000);
	//pinMode(A0, INPUT);
}

void loop() {
	Home::loop();
	if (Serial.available() > 0) {
		Serial.readBytes(buffer, 4);
		if (buffer[0] == 62) {
			Home::command(buffer[1], buffer[2], buffer[3]);
		}
		while (Serial.available()) {
			Serial.read();
			delay(1); //wait for the next byte, if after this nothing has arrived it means the text was not part of the same stream entered by the user
		}
	}
}
