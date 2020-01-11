namespace Hallway{ namespace Lightning{
	using namespace Hallway;
	
	Server::State state(T_HL_LIGHTNING);
	
	void command(byte action, byte data) {
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
