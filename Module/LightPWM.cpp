class LightPWM : public PWM{
public:
	LightPWM(uint8_t id, uint8_t pin) : PWM (pin) {
		serverState.setId(id);
		flagAuto = false;
	}
	LightPWM(uint8_t pin) : LightPWM(pin, pin) {}
	void on(uint8_t brightness, unsigned int speed) {
		if (disabled) return;
		PWM::on(brightness, speed);
		if (currentBrightness == 0) serverState.low();
		else serverState.high();
	}
	void on(uint8_t brightness) { on(brightness, PWM_SPPED); }
	void on() { on(PWM_BRIGHTNESS, PWM_SPPED); }
	void setAuto(bool flag) { flagAuto = flag; }
	void state() { serverState.send(); }
	void command(uint8_t action, uint8_t data = 0) {
		switch (action) {
			case C_ON: if (data) on(data); else on(); break;
			case C_OFF: off(); break;
			case C_TOGGLE: toggle(); break;
		}
	}
protected:
	bool flagAuto;
	Server::State serverState;
};
