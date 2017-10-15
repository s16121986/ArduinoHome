namespace Storage{
	//Основной свет
	namespace MainLight{
		Server::State state(T_ST_MAINLIGHT);
		
		Gercon s = Gercon(PIN_ST_DOOR);  //Датчик двери
		Button b = Button(PIN_ST_SWITCH);  //Выключатель
		Relay r  = Relay(PIN_ST_LIGHT);  //PWM
		
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
		void setup() {
			
		}
		void listen() {
			b.listen();
			s.listen();
		}
		void loop() {
			if (b.onPress()) {
				toggle();
			} else if (s.onChange()) {
				if (s.getState() == HIGH) off();
				else on();
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
			case T_ST_MAINLIGHT:MainLight::command(action, data);break;
		}
	}
}

