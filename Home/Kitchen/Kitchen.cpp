namespace Kitchen{
	using namespace Device::KH;
	
	void setup() {
		
	}
	void listen() {
		mainSwitch.listen();
		tableLight.listen();
	}
	void loop() {
		if (mainSwitch.onPress()) {
			if (!EVENTS_MODE)
				tableLight.toggle();
		}
	}
	void command(uint8_t action, uint8_t data = 0) {
		/*switch (action) {
			case C_LIGHTON:
			case C_LIGHTOFF:
			case C_LIGHTTOGGLE:
				mainLight.trigger(action, data);
				break;
			case C_STATE:
				mainLight.state();
				break;
		}*/
	}
	void trigger(uint8_t target, uint8_t action, uint8_t data = 0) {
		switch (target) {
			//case T_KH_MAINLIGHT: mainLight.command(action, data); break;
		}
	}
}

