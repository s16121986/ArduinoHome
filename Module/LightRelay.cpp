class LightRelay : public Relay{
public:
	LightRelay(uint8_t id, uint8_t pin) : Relay (pin) {
		serverState.setId(id);
		flagAuto = false;
	}
	LightRelay(uint8_t pin) : LightRelay(pin, pin) {}
	void state() { serverState.send(); }
	void on(unsigned long msec = 0) {
			Serial.println("toggle");
			Serial.println(disabled);
		if (disabled) return;
		Relay::on(msec);
		serverState.high();
	}
	void off() {
		Relay::off();
		serverState.low();
	}
	void setAuto(bool flag) { flagAuto = flag; }
	void autoOn(unsigned long msec) {
		if (!flagAuto) return;
		on(msec);
	}
	void autoOff() {
		if (!flagAuto) return;
		off();
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_ON: on(); break;
			case C_OFF: off(); break;
			case C_TOGGLE: toggle(); break;
		}
	}
protected:
	bool flagAuto;
	Server::State serverState;
};
