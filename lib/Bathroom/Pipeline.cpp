namespace Bathroom{ namespace Pipeline{
	void setup() {
		leackState = false;
		autoEnabled = true;
		timerOn.set(40000);
	}
	void listen() {
		if (autoEnabled) {
			sFloor.listen();
			leackState = (sFloor.isHigh()/* || sPipeline.isHigh()*/);
		}
		gidrolock.listen();
	}
	void loop() {
		if (autoEnabled) {
			if (state.isHigh() != leackState) {
				if (leackState) {
					state.high();
					timerOn.stop();
					if (gidrolock.getState()) {
						gidrolock.close();
				Serial.println("close");
					}
				} else {
					timerOn.start();
					state.low();
				}
			} else if (timerOn.onExpire()) {
				Serial.println("open");
				gidrolock.open();
			}
		}
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_ON:
				if (!leackState) {
					gidrolock.open();
					state.low();
				}
				break;
			case C_OFF:
				gidrolock.close();
				state.high();
				break;
		}
	}
} }
