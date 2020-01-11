
#define STATE_AVAILABLE     1 // 001
#define STATE_ENABLED       2 // 010
#define STATE_ON            4 // 100

namespace Device{
	
	void send(uint8_t pckg, uint8_t pin, uint8_t param, uint8_t data) {
		Serial.write(pckg);
#ifdef DEBUG_PORT
			Serial.print(pin);
			Serial.print(" ");
			Serial.print(param);
			Serial.print(" ");
			Serial.print(data);
			Serial.println(";");
#else
			Serial.write(pin);
			Serial.write(param);// == 0 ? 254 : param
			Serial.write(data);
			Serial.write(IO_STOP_BIT);
#endif
	}
	void sendState(uint8_t pin, uint8_t state, uint8_t data = 0) { send(IO_STATE_BIT, pin, state, data); }
	void sendEvent(uint8_t pin, uint8_t e, uint8_t data = 0) { send(IO_EVENT_BIT, pin, e, data); }
	void sendData(uint8_t pin, uint8_t data) { sendState(pin, STATE_AVAILABLE | STATE_ENABLED, data); }
	
	class Pin{
	public:
		Pin() {
			pin = 0;
			pinState = STATE_AVAILABLE;
			data = 0;
		}
		Pin(uint8_t pin) : Pin() {
			setPin(pin);
		}
		bool isEmpty() { return this->pin == 0; }
		bool isEnabled() { return !isEmpty() && (this->pinState & STATE_ENABLED); }
		void state() {
			if (!isEmpty())
				sendState(pin, pinState, data);
		}
		void event(uint8_t e, uint8_t data = 0) {
			if (!isEmpty())
				sendEvent(pin, e, data);
		}
		void setPin(uint8_t pin) { this->pin = pin; }
		//Pin &operator+=( uint8_t value ) { this->pinState |= value;send();return *this; }
		/*Pin &operator|=( uint8_t value ) {
			setState(this->pinState | value);
			return *this;
		}
		//State &operator-=( uint8_t value ) { this->pinState ^= value;send();return *this; }
		Pin &operator^=( uint8_t value ) {
			if (pinState & value)
				setState(this->pinState ^= value);
			return *this;
		}
		bool operator==( uint8_t value ) { return this->pinState & value; }
		bool operator!=( uint8_t value ) { return ~this->pinState & value; }*/
		void setState(uint8_t state) {
			if (this->pinState == state)
				return;
			this->pinState = state;
			//this->state();
		}
		void setData(uint8_t data) {
			this->data = data;
			//this->state();
		}
		void enable() { setState(pinState | 3); }
		void disable() { setState(STATE_AVAILABLE); }
		void high() { setState(7); }
		void low() {
			if (isHigh())
				setState(3);
		}
		bool isHigh() { return this->pinState & STATE_ON; }
		bool isLow() { return !isHigh(); }
		
		uint8_t pin;
		uint8_t pinState;
		uint8_t data;
		
	};
}