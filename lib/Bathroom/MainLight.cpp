namespace Bathroom{ namespace MainLight{
	void on(bool flagAuto = false) {
		mainLight.on();
		state |= STATE_ON;
		if (flagAuto) (*tAuto).startDelay();
	}
	void off(bool flagAuto = false) {
		mainLight.off();
		state ^= STATE_ON;
		if (!flagAuto && tAuto != 0) (*tAuto).startDelay();
	}
	void setTimeout(AutoTimeout &t) { tAuto = &t; }
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_AUTOTIMEOUT:
				//autoTimeout = data * 1000;
				//flagAuto = data > 0;
				//Memory::set(M_HL_MAINLIGHT_AUTOTIMEOUT, (uint8_t)data);
				break;
			case C_ON:on();break;
			case C_OFF:off();break;
			case C_TOGGLE:
				if (state == STATE_ON) off(); else on();
				break;
		}
	}
	void setup() {
		//Memory::init(autoTimeout, M_BT_MAINLIGHT_AUTOTIMEOUT, 20000, 1000);
		tAuto = 0;
	}
} }
