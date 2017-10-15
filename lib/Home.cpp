#ifdef Storage_h
#include "Storage.cpp"
#endif
#ifdef Hallway_h
#include "Hallway.cpp"
#endif
#ifdef Balcony_h
#include "Balcony.cpp"
#endif
#ifdef Bathroom_h
#include "Bathroom.cpp"
#endif
#ifdef Bedroom_h
#include "Bedroom.cpp"
#endif
#ifdef Kitchen_h
#include "Kitchen.cpp"
#endif

namespace Home{
	void disable() {
		disabled = true;
	}
	void setup() {
		MODE = MODE_NONE;
		DAY_MODE = DAY_MODE_NIGHT;
#ifdef Storage_h
		Storage::setup();
#endif
#ifdef Hallway_h
		Hallway::setup();
#endif
#ifdef Bathroom_h
		Bathroom::setup();
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
#ifdef Kitchen_h
		Kitchen::listen();
#endif
#ifdef Balcony_h
		Balcony::listen();
#endif
		if (darkSensor.read() > 990) {
			if (DAY_MODE != DAY_MODE_NIGHT) setDayMode(DAY_MODE_NIGHT);
		} else  if (DAY_MODE == DAY_MODE_NIGHT) {
			setDayMode(DAY_MODE_DAY);
		}
	}
	void loop() {
#ifdef Storage_h
		Storage::loop();
#endif
#ifdef Hallway_h
		Hallway::loop();
#endif
#ifdef Bathroom_h
		Bathroom::loop();
#endif
#ifdef Kitchen_h
		Kitchen::loop();
#endif
#ifdef Balcony_h
		Balcony::loop();
#endif
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
#ifdef Kitchen_h
		Kitchen::command(action, data);
#endif
#ifdef Balcony_h
		Balcony::command(action, data);
#endif
	}
	void commandAll(byte target, byte action, byte data) {
#ifdef Storage_h
		Storage::command(target, action, data);
#endif
#ifdef Hallway_h
		Hallway::command(target, action, data);
#endif
#ifdef Bathroom_h
		Bathroom::command(target, action, data);
#endif
#ifdef Kitchen_h
		Kitchen::command(target, action, data);
#endif
#ifdef Balcony_h
		Balcony::command(target, action, data);
#endif
	}
	void setMode(uint8_t mode) {
		MODE = mode;
		switch (mode) {
			case MODE_NOTHOME:
				commandAll(C_LIGHTOFF);
				break;
			case MODE_SLEEP:
				commandAll(C_LIGHTOFF);
				break;
		}
		//state.setData(mode);
	}
	void setDayMode(uint8_t mode) {
		DAY_MODE = mode;
#ifdef Bathroom_h
		Bathroom::update();
#endif
#ifdef Hallway_h
		Hallway::update();
#endif
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_LIGHTON:
			case C_LIGHTOFF:
				commandAll(action, data);
				break;
			case C_MODE:setMode((uint8_t)data);break;
			case C_DAY_MODE:setDayMode((uint8_t)data);break;
			case C_PWM_DELAY:
				PWM_DELAY = (int)data;
				break;
			case C_STATE:
				state.send();
				commandAll(C_STATE);
				break;
			case C_PING:Server::sendState(T_HOME, 1);break;
		}
	}
	void command(byte target, byte action, byte data) {
	switch (target) {
		case T_ALL:commandAll(action, data);break;
		case T_HOME:command(action, data);break;
#ifdef Storage_h
		case T_STORAGE:Storage::command(action, data);break;
#endif
#ifdef Hallway_h
		case T_HALLWAY:Hallway::command(action, data);break;
#endif
#ifdef Bathroom_h
		case T_BATHROOM:Bathroom::command(action, data);break;
#endif
#ifdef Kitchen_h
		case T_KITCHEN:Kitchen::command(action, data);break;
#endif
#ifdef Balcony_h
		case T_BALCONY:Balcony::command(action, data);break;
#endif
		default:
			commandAll(target, action, data);
	}
}
}
