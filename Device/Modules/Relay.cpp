namespace Device{
	class Relay : public ModuleD{
	public:
		Relay(uint8_t id): ModuleD(id, OUTPUT) {
			currentState = !highState;
		}
		void disable() {
			Module::disable();
			off();
		}
		void on(unsigned long msec = 0) {
			if (!isEnabled()) return;
			currentState = highState;
			if (msec > 0)
				ti.start(msec);
			else
				ti.stop();
			setState(currentState);
			state();
		}
		void off() {
			currentState = !highState;
			ti.stop();
			setState(currentState);
			state();
		}
		void toggle() {
			if (currentState == highState) off(); else on();
		}
		void listen() { if (ti.onExpire()) off(); }
		bool isOn() { return isHigh(); }
		bool isOff() { return !isHigh(); }
		unsigned long getTimeout() { return ti.getTimeout(); }
		void trigger(uint8_t action, uint8_t data = 0) {
			switch (action) {
				case C_ON: on(); break;
				case C_OFF: off(); break;
				case C_TOGGLE: toggle(); break;
				default: Module::trigger(action, data);
			}
		}
	protected:
		Timeout ti;
		bool currentState;
	};
}