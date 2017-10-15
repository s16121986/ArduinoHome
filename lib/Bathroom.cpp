
#ifdef BathroomFan_h
#include "Bathroom/Fan.cpp"
#endif
#include "Bathroom/MainLight.cpp"
#ifdef BathroomPipeline_h
#include "Bathroom/Pipeline.cpp"
#endif
#ifdef BathroomWarmFloor_h
#include "Bathroom/WarmFloor.cpp"
#endif
#ifdef BathroomFlowers_h
#include "Bathroom/Flowers.cpp"
#endif
#ifdef BathroomLightning_h
#include "Bathroom/Lightning.cpp"
#endif
#ifdef BathroomInstallation_h
#include "Bathroom/Installation.cpp"
#endif

#include "Bathroom/DayMode/Day.cpp"
#include "Bathroom/DayMode/Night.cpp"

namespace Bathroom{
	
	void setup() {
		MainLight::setup();
		//WarmFloor::setup();
#ifdef BathroomFan_h
		Fan::setup();
#endif
#ifdef BathroomPipeline_h
		Pipeline::setup();
#endif
		update();
#ifdef PIN_BT_DHT
		dht.begin();
#endif
	}
	void listen() {
		mainSwitch.listen();
		//MainLight::listen();
#ifdef BathroomFan_h
		Fan::listen();
#endif
#ifdef BathroomPipeline_h
		Pipeline::listen();
#endif
		dayModeListen();
	}
	void loop() {
		//MainLight::loop();
		//WarmFloor::loop();
#ifdef BathroomFan_h
		Fan::loop();
#endif
#ifdef BathroomPipeline_h
		Pipeline::loop();
#endif
		dayModeLoop();
	}
	void update() {
		switch (Home::DAY_MODE) {
			case DAY_MODE_NIGHT:
				Bathroom::DayModeNight::setup();
				break;
			default:
				Bathroom::DayModeDay::setup();
		}
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_LIGHTON:
				MainLight::on();
				break;
			case C_LIGHTOFF:
				MainLight::off();
				break;
			case C_STATE:
				MainLight::state.send();
#ifdef BathroomWarmFloor_h
				WarmFloor::state.send();
#endif
#ifdef BathroomFan_h
				Fan::state.send();
#endif
#ifdef BathroomPipeline_h
				Pipeline::state.send();
#endif
#ifdef PIN_BT_DHT
				command(C_GET_TEMP);
				command(C_GET_WETNESS);
#endif
				break;
#ifdef PIN_BT_DHT
			case C_GET_TEMP:
				Server::sendData(T_BT_TEMP, (byte)dht.readTemperature());
				break;
			case C_GET_WETNESS:
				Server::sendData(T_BT_WETNESS, (byte)dht.readHumidity());
				break;
#endif
		}
	}
	void command(byte target, byte action, byte data) {
		switch (target) {
			case T_BT_MAINLIGHT:MainLight::command(action, data);break;
#ifdef BathroomWarmFloor_h
			case T_BT_WARMFLOOR:WarmFloor::command(action, data);break;
#endif
#ifdef BathroomFan_h
			case T_BT_FAN:Fan::command(action, data);break;
#endif
#ifdef BathroomPipeline_h
			case T_BT_PIPELINE:Pipeline::command(action, data);break;
#endif
		}
	}
}