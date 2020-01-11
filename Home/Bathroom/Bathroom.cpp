
//#include "MainLight.cpp"
//#include "Fan.cpp"

#ifdef BathroomPipeline_h
#include "Pipeline.cpp"
#endif
#ifdef BathroomWarmFloor_h
#include "WarmFloor.cpp"
#endif
#ifdef BathroomFlowers_h
#include "Flowers.cpp"
#endif
#ifdef BathroomLightning_h
#include "Lightning.cpp"
#endif
#ifdef BathroomInstallation_h
#include "Installation.cpp"
#endif

namespace Bathroom{
	using namespace Device::BT;
	
	void setup() {
		//MainLight::setup();
		//WarmFloor::setup();
#ifdef BathroomFan_h
		Fan::setup();
#endif
#ifdef BathroomPipeline_h
		Pipeline::setup();
#endif
#ifdef PIN_BT_DHT
		dht.begin();
#endif
	}
	void listen() {
		mainSwitch.listen();
		fanSwitch.listen();
		//mainLight.listen();
#ifdef BathroomFan_h
		Fan::listen();
#endif
#ifdef BathroomPipeline_h
		Pipeline::listen();
#endif
	}
	
	void loop() {
		
		if (mainSwitch.onPress()) {
			if (!EVENTS_MODE)
				mainLight.toggle();
		}
		if (fanSwitch.onPress()) {
			
		}
		
		//WarmFloor::loop();
#ifdef BathroomFan_h
		Fan::loop();
#endif
#ifdef BathroomPipeline_h
		Pipeline::loop();
#endif
	}
	void command(uint8_t action, uint8_t data /*= 0*/) {
		/*switch (action) {
			case C_LIGHTON:
				mainLight.on();
				break;
			case C_LIGHTOFF:
				mainLight.off();
				break;
			case C_STATE:
				mainLight.state();
#ifdef BathroomWarmFloor_h
				WarmFloor::state.send();
#endif
#ifdef BathroomFan_h
				Fan::state();
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
				Server::sendData(T_BT_TEMP, (uint8_t)dht.readTemperature());
				break;
			case C_GET_WETNESS:
				Server::sendData(T_BT_WETNESS, (uint8_t)dht.readHumidity());
				break;
#endif
		}
*/
	}
	void trigger(uint8_t target, uint8_t action, uint8_t data) {
		switch (target) {
			
			//case T_BT_MAINLIGHT: mainLight.command(action, data); break;
			
#ifdef BathroomWarmFloor_h
			case T_BT_WARMFLOOR: WarmFloor::command(action, data); break;
#endif
#ifdef BathroomFan_h
			case PIN_BT_FAN:
			case T_BT_FAN: Fan::command(action, data); break;
#endif
#ifdef BathroomPipeline_h
			case T_BT_PIPELINE: Pipeline::command(action, data); break;
#endif

			//case PIN_BT_LIGHT: mainLight.command(action, data); break;
		}
	}
}