#define Bathroom_h
#ifdef PIN_BT_FAN_SWITCH
#include "Bathroom/Fan.h"
#endif
#include "Bathroom/MainLight.h"
#include "Bathroom/Pipeline.h"
//#include "Bathroom/WarmFloor.h"
//#include "Bathroom/Flowers.h"
//#include "Bathroom/Lightning.h"
//#include "Bathroom/Installation.h"

#include "Bathroom/DayMode/Day.h"
#include "Bathroom/DayMode/Night.h"

namespace Bathroom{
	Motion motion_1(PIN_BT_MOTION_1);
#ifdef PIN_BT_DHT
	DHT dht(PIN_BT_DHT, DHT11);
#endif
	Button mainSwitch(PIN_BT_SWITCH);    //Выключатель
	Relay mainLight(PIN_BT_LIGHT);       //PWM
	Relay wallLight(PIN_BT_WALLLIGHT);
	
	void (*dayModeListen)();
	void (*dayModeLoop)();
	
	void setup();
	void listen();
	void loop();
	void update();
	void command(byte action, byte data = 0);
	void command(byte target, byte action, byte data);
}
