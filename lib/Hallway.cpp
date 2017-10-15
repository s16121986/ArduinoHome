#include "Hallway/MainLight.cpp"
#include "Hallway/Lightning.cpp"

#include "Hallway/DayMode/Day.cpp"
#include "Hallway/DayMode/Night.cpp"

namespace Hallway{
	
	void setup() {
		MainLight::setup();
		//HallLight::setup();
		Lightning::setup();
		update();
	}
	void listen() {
		//HallLight::listen();
		Lightning::listen();
		dayModeListen();
	}
	void loop() {
		//HallLight::loop();
		//Lightning::loop();
		dayModeLoop();
	}
	void update() {
		switch (Home::DAY_MODE) {
			case DAY_MODE_NIGHT:
				Hallway::DayModeNight::setup();
				break;
			default:
				Hallway::DayModeDay::setup();
		}
	}
	void command(byte action, byte data) {
		switch (action) {
			case C_LIGHTON:
				MainLight::command(C_ON);
				break;
			case C_LIGHTOFF:
				MainLight::command(C_OFF);
				floorStrip.off();
				break;
			case C_STATE:
				MainLight::state.send();
				break;
		}
	}
	void command(byte target, byte action, byte data) {
		switch (target) {
			case T_HL_MAINLIGHT:MainLight::command(action, data);break;
			case T_HL_LIGHTNING:Lightning::command(action, data);break;
		}
	}
}

