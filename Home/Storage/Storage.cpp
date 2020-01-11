namespace Storage{
	using namespace Device::ST;		
	
	void setup() {
		
	}
	void listen() {
		mainSwitch.listen();
		//s.listen();
	}
	void loop() {
		if (mainSwitch.onPress()) {
			if (!EVENTS_MODE)
				mainLight.toggle();
		}
		/* else if (s.onChange()) {
			if (s.isHigh()) off(); else on();
		}*/
	}
	void command(byte action, byte data) {
		/*switch (action) {
			case C_LIGHTON:
				mainLight.on();
				break;
			case C_LIGHTOFF:
				mainLight.off();
				break;
			case C_STATE:
				mainLight.state();
				break;
		}*/
	}
	void trigger(byte target, byte action, byte data = 0) {
		switch (target) {
			
		}
	}
}

