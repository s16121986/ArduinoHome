namespace Balcony{
	//Основной свет
	namespace MainLight{
		Server::State state(T_BL_MAINLIGHT);
		Button b = Button(PIN_BL_SWITCH);  //Выключатель
		Relay r  = Relay(PIN_BL_LIGHT);   //PWN 
		void setup() {
			
		}
		void listen() {
			b.listen();
		}
		void loop() {
			if (b.onPress()) {
				r.toggle();
			}
		}
		void off() {
			r.off();
			state.low();
		}
		void on() {
			r.on();
			state.high();
		}
		void toggle() { if (state == STATE_ON) off(); else on(); }
		void command(byte action, byte data = 0) {
			switch (action) {
				case C_ON:on();break;
				case C_OFF:off();break;
				case C_TOGGLE:toggle();break;
			}
		}
	}
	void setup() {
		MainLight::setup();
	}
	void listen() {
		MainLight::listen();
	}
	void loop() {
		MainLight::loop();
	}
	void command(byte action, byte data) {
		switch (action) {
			case C_STATE:
				MainLight::state.send();
				break;
		}
	}
	void command(byte target, byte action, byte data) {
		switch (target) {
			case T_BL_MAINLIGHT:MainLight::command(action, data);break;
		}
	}
}


