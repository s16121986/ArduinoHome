class Motion : public ModuleD{
public:
	Motion(): ModuleD() { setMode(INPUT); }
	Motion(uint8_t pin) : ModuleD(pin, INPUT) {
		reset();
	}
	void listen() {
		if (isOn() && stateFlag == false && getState() == HIGH) {
			stateFlag = true;
		}
		return false;
	}
	bool onHigh() {
		if (isOn() && stateFlag) {
			stateFlag = false;
			if (EVENTS_MODE)
				event(EVENT_MOTION_HIGH);
			return true;
		}
		return false;
	}
	void reset() {
		offTime = 0;
		offDelay = 0;
		stateFlag = false;
	}
	void disable() {
		ModuleD::disable();
		reset();
	}
	void on() { reset(); }
	void off() {
		reset();
		offTime = CURRENT_TIME;
	}
	void off(unsigned long int delay) {
		off();
		offDelay = delay;
	}
	bool isOn() {
		if (!isEnabled())
			return false;
		if (offTime) {
			if (offDelay == 0) return false;
			if (CURRENT_TIME - offTime <= offDelay)
				return false;
			offTime = 0;
		}
		return true;
	}
private:
	bool stateFlag;
	unsigned long int offTime;
	unsigned long int offDelay;
};
