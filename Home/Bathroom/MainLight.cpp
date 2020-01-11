namespace Bathroom{ namespace MainLight{
	using namespace Bathroom;
	
	Server::State state(T_BT_MAINLIGHT);
	
	void on() {
		mainLight.on();
		state.high();
	}
	void off() {
		mainLight.off();
		state.low();
	}
	void toggle() { if (state.isHigh()) off(); else on(); }
	void listen() {
		
	}
	void loop() {
		if (mainSwitch.onPress())
			toggle();
	}
	//void setTimeout(AutoTimeout &t) { tAuto = &t; }
	void command(byte action, byte data) {
		switch (action) {
			case C_AUTOTIMEOUT:
				//autoTimeout = data * 1000;
				//flagAuto = data > 0;
				//Memory::set(M_HL_MAINLIGHT_AUTOTIMEOUT, (uint8_t)data);
				break;
			case C_ON: on(); break;
			case C_OFF: off(); break;
			case C_TOGGLE: toggle(); break;
		}
	}
	void setup() {
		//Memory::init(autoTimeout, M_BT_MAINLIGHT_AUTOTIMEOUT, 20000, 1000);
	}
} }
