namespace Device{
	class PWMD : public Ping{
	public:
		PWMD(int id) : Ping(id) {
			brightness = PWM_MAX_VALUE;
		}
		void init() {
			ModuleD::init();
			(*devicePin).setData(brightness);
		}
		bool isOn() { return flagOn; }
		void signal(uint8_t code) {
			if (pwmCounter)
				return;
			
			pwmFlag = true;
			pwmCounter = code;
			pwmTime = millis() + 10; // long first signal to zerocross delay fix
			D0.write(HIGH);
		}
		void on(uint8_t brightness) {
			if (!isEnabled())
				return;
			
			if (brightness == 0) { //off
				//if (!isOn())
				//	return;
				flagOn = false;
				signal(1);
			} else { //on
				if (isOn()) {
					//if (this->brightness == brightness)
						//return;
				} else {
					flagOn = true;
				}
				setBrightness(brightness);
				signal(1 + map(brightness, 0, PWM_MAX_VALUE, 0, 20));
			}
			
			if (isOn()) (*devicePin).high(); else (*devicePin).low();
			state();
			
	#ifdef DEBUG_PORT
			Serial.print("pwm (");
			Serial.print(brightness);
			Serial.print(":");
			Serial.println(")");
	#endif
		}
		void on() { on(brightness); }
		void off() { on(0); }
		void toggle() { if (isOn()) off(); else on(); }
		void setBrightness(uint8_t brightness) {
			this->brightness = brightness;
			(*devicePin).setData(brightness);
		}
		uint8_t getBrightness() { return brightness; }
		void trigger(uint8_t action, uint8_t data = 0) {
			switch (action) {
				case C_ON: on(); break;
				case C_OFF: off(); break;
				case C_TOGGLE: toggle(); break;
				case C_PWM: on(data); break;
				default: Module::trigger(action, data);
			}
		}
	protected:
		uint8_t brightness;                //Текущее значене яркости
		bool flagOn;
	};
}
