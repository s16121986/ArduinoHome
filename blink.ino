#define DEBUG_MODE
#define DEBUG_PORT

#include <Home.h>
#include "config/constants.hpp"

//#include "pins_uno.hpp"

//#include "Module/LightRelay.cpp"
//#include "Module/LightPWM.cpp"
//#include "Module/AutoMotion.cpp"

bool EVENTS_MODE = true;

#include "Home/Home.h"
#include "Device/Device.cpp"

#ifdef Home_h
//#include "Home/Pult.cpp"
#include "Home/Storage/Storage.h"    //ST
#include "Home/Hallway/Hallway.h"    //HL
#include "Home/Bathroom/Bathroom.h"  //BT
#include "Home/Kitchen/Kitchen.h"    //KH
#include "Home/Balcony/Balcony.h"    //BL
#include "Home/Bedroom/Bedroom.h"    //BD
#include "Home/Home.cpp"
#endif


//#include "Tests/Pult.cpp"
//#include "Tests/Port.cpp"

byte buffer[4];

void listen() { 
	CURRENT_TIME = millis();
#ifdef Home_h
	Home::listen();
#endif
	//Serial.println(analogRead(A0));
	//TestPult::listen();
}

void setup() {
	Serial.begin(9600);
	while (!Serial);
#ifdef DEBUG_PORT
	Serial.println("//setup");
#endif
	CURRENT_TIME = millis();
#ifdef Home_h
	Home::setup();
	delay(1000);
#endif
	MsTimer2::set(40, listen);
	MsTimer2::start();
#ifdef DEBUG_PORT
	Serial.println("//listen ready");
#endif
	delay(1000);
#ifdef DEBUG_PORT
	Serial.println("//started");
#endif
	//pinMode(25, INPUT);
	//TestPult::setup();
	Device::setup();
}
#ifdef DEBUG_PORT
char _strToByte(byte c[3], byte l) {
    byte b = 0, i;
	double d;
    for (i = 0; i < l; i++) {
		d = round(pow(10.0, ((double)l - (double)i - 1.0)));
        b +=  d * (c[i] - '0');
    }
	//Serial.println(b);
    return b;
}
#endif
void loop() {
	//TestPult::loop();
#ifdef Home_h
	Home::loop();
#endif
	if (Serial.available() > 0) {
#ifdef DEBUG_PORT
		byte b, l = 0, i = 1;
		byte c[3];
		if (Serial.read() == IO_TRIGGER_BIT) {
			//Serial.println("->");
			delay(10);
			buffer[0] = IO_TRIGGER_BIT;
			while (Serial.available()) {
				b = Serial.read();
				//Serial.print("//");
				//Serial.println(b);
				if (b == 32 || b == 10) { // "[space] | EOL"
					buffer[i++] = _strToByte(c, l);
					l = 0;
				} else {
					c[l++] = b;
				}
				delay(10);
			}
		}
#else
		Serial.readBytes(buffer, 4);
#endif
#ifdef Device_h
		switch (buffer[0]) {
			case IO_PING_BIT: Device::send(IO_PING_BIT, 0, 0, 0); break;
			case IO_TRIGGER_BIT:
				Device::trigger(buffer[1], buffer[2], buffer[3]);
				break;
		}
#endif
		delete buffer;
		while (Serial.available()) {
			Serial.read();
			delay(1); //wait for the next byte, if after this nothing has arrived it means the text was not part of the same stream entered by the user
		}
	}
}
