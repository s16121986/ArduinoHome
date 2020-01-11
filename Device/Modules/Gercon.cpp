class Gercon : public ModuleD{
public:
	Gercon(int pin): ModuleD(pin, INPUT) {
		lastState = 0;
		currentState = 0;
		changed = false;
	}
	void listen() {
		currentState = getState();
		if (currentState != lastState) {
			changed = true;
			lastState = currentState;
		}
	}
	bool onChange() {
		if (changed) {
			changed = false;
			return true;
		}
		return false;
	}
	bool isHigh() { return getState() == HIGH; }
	bool isLow() { return !isHigh(); }
private:
	bool lastState;
	bool currentState;
	bool changed;
};
