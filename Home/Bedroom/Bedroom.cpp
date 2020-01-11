namespace Bedroom{
	using namespace Device::BD;
	
	void setup() {
		
	}
	void listen() {
		mainSwitch.listen();
	}
	void loop() {
		if (mainSwitch.onPress()) {
			if (!EVENTS_MODE)
				bedLight.toggle();
		}
	}
	void command(uint8_t action, uint8_t data = 0) {
		
	}
	void trigger(uint8_t target, uint8_t action, uint8_t data = 0) {
		
	}
}


