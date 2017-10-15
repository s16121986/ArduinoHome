namespace Hallway{ namespace Lightning{
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_ON:
			case C_PWM:
				floorStrip.on(data);
				state.set(STATE_ON, data);
				break;
			case C_OFF:
				floorStrip.off();
				state.low();
				break;
		}
	}
	void setup() {

	}
	void listen() { floorStrip.listen(); }
	void loop() {

	}
} }
