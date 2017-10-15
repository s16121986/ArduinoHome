#define Hallway_h

#include "Hallway/MainLight.h"
#include "Hallway/Lightning.h"

#include "Hallway/DayMode/Day.h"
#include "Hallway/DayMode/Night.h"

namespace Hallway{
	Button mainSwitch(PIN_HL_SWITCH);      //Выключатель
	Relay mainLight(PIN_HL_LIGHT);         //PWM
	Motion motion_1(PIN_HL_MOTION_1);    //Датчик движения пуфик
	PWM floorStrip(PIN_HL_FLOORSTRIP);    //Подсветка плинтус
	
	void (*dayModeListen)();
	void (*dayModeLoop)();
	
	void setup();
	void listen();
	void loop();
	void update();
	void command(byte action, byte data = 0);
	void command(byte target, byte action, byte data);
}
