#ifdef Storage_h
#include "Storage/Storage.cpp"
#endif
#ifdef Hallway_h
#include "Hallway/Hallway.cpp"
#endif
#ifdef Balcony_h
#include "Balcony/Balcony.cpp"
#endif
#ifdef Bathroom_h
#include "Bathroom/Bathroom.cpp"
#endif
#ifdef Bedroom_h
#include "Bedroom/Bedroom.cpp"
#endif
#ifdef Kitchen_h
#include "Kitchen/Kitchen.cpp"
#endif

#include "../Mode/Mode.cpp"

namespace Home{

	/*namespace Brightness{
		uint16_t brightness;
		void listen() {
			brightness = darkSensor.read();
			if (brightness < 10) {
			Serial.println(" - Dark");
			} else if (brightness < 200) {
			Serial.println(" - Dim");
			} else if (brightness < 500) {
			Serial.println(" - Light");
			} else if (brightness < 800) {
			Serial.println(" - Bright");
			} else {
			Serial.println(" - Very bright");
			}
		}
	}*/
	void disable() { disabled = true; }
	void setup() {
#ifdef Pult_h
		Pult::setup();
#endif
#ifdef Storage_h
		Storage::setup();
#endif
#ifdef Hallway_h
		Hallway::setup();
#endif
#ifdef Bathroom_h
		Bathroom::setup();
#endif
#ifdef Bedroom_h
		Bedroom::setup();
#endif
#ifdef Kitchen_h
		Kitchen::setup();
#endif
#ifdef Balcony_h
		Balcony::setup();
#endif
	}
	void listen() {
#ifdef Storage_h
		Storage::listen();
#endif
#ifdef Hallway_h
		Hallway::listen();
#endif
#ifdef Bathroom_h
		Bathroom::listen();
#endif
#ifdef Bedroom_h
		Bedroom::listen();
#endif
#ifdef Kitchen_h
		Kitchen::listen();
#endif
#ifdef Balcony_h
		Balcony::listen();
#endif
		/*if (darkSensor.read() > 990) {
			if (DAY_MODE != DAY_MODE_NIGHT) setDayMode(DAY_MODE_NIGHT);
		} else  if (DAY_MODE == DAY_MODE_NIGHT) {
			setDayMode(DAY_MODE_DAY);
		}*/
	}
	void loop() {
#ifdef Pult_h
		Pult::loop();
#endif
#ifdef Storage_h
		Storage::loop();
#endif
#ifdef Hallway_h
		Hallway::loop();
#endif
#ifdef Bathroom_h
		Bathroom::loop();
#endif
#ifdef Bedroom_h
		Bedroom::loop();
#endif
#ifdef Kitchen_h
		Kitchen::loop();
#endif
#ifdef Balcony_h
		Balcony::loop();
#endif
	}
	void setMode(unsigned char mode) {
		Mode::set(mode);
	} 
	void commandAll(byte action, byte data = 0) {
#ifdef Storage_h
		Storage::command(action, data);
#endif
#ifdef Hallway_h
		Hallway::command(action, data);
#endif
#ifdef Bathroom_h
		Bathroom::command(action, data);
#endif
#ifdef Bedroom_h
		Bedroom::command(action, data);
#endif
#ifdef Kitchen_h
		Kitchen::command(action, data);
#endif
#ifdef Balcony_h
		Balcony::command(action, data);
#endif
	}
	void triggerAll(byte target, byte action, byte data = 0) {
#ifdef Storage_h
		Storage::trigger(target, action, data);
#endif
#ifdef Hallway_h
		Hallway::trigger(target, action, data);
#endif
#ifdef Bathroom_h
		Bathroom::trigger(target, action, data);
#endif
#ifdef Bedroom_h
		Bedroom::trigger(target, action, data);
#endif
#ifdef Kitchen_h
		Kitchen::trigger(target, action, data);
#endif
#ifdef Balcony_h
		Balcony::trigger(target, action, data);
#endif
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			//case C_LIGHTON:
			//case C_LIGHTOFF:
			//	commandAll(action, data);
			//	break;
			//case C_MODE:setMode((uint8_t)data);break;
			//case C_PWM_DELAY:
			//	Device::PWM_DELAY = (int)data;
			//	break;
			case C_STATE: Device::state(); break;
			case C_PING: Device::sendState(T_HOME, 1); break;
		}
	}
	void trigger(byte target, byte action, byte data = 0) {
		switch (target) {
			case T_ALL: commandAll(action, data); break;
			case T_HOME: command(action, data); break;
#ifdef Storage_h
			case T_STORAGE: Storage::command(action, data); break;
#endif
#ifdef Hallway_h
			case T_HALLWAY: Hallway::command(action, data); break;
#endif
#ifdef Bathroom_h
			case T_BATHROOM: Bathroom::command(action, data); break;
#endif
#ifdef Kitchen_h
			case T_KITCHEN: Kitchen::command(action, data); break;
#endif
#ifdef Balcony_h
			case T_BALCONY: Balcony::command(action, data); break;
#endif
			default:
				triggerAll(target, action, data);
		}
	}
}
