namespace Device{
	class Button : public ModuleD {
	public:
		Button() : ModuleD() {}
		Button(uint8_t id) : ModuleD(id, INPUT) {
			lastState = LOW;
			currentState = LOW;
			pressedState = HIGH;

			lastDebouncedState = 0;
			currentDebouncedState  = 0;
			debounceTimerStartTime = 0;
			debounceDelay = 30;

			pressed = false;
			released = true;

			changed = false;
			justPressed = false;
			justReleased = false;
			justHolded = false;
			pressCount = 0;

			doubleClickDelay = 400; 
			holdDelay = 1200;

			lastPressTime = 0;
			currentPressTime = 0;
			lastReleaseTime = 0;
			currentReleaseTime = 0;
			pressCountDelay = 0;
		}
		void setPressCountDelay(unsigned long int delay) { pressCountDelay = delay; }
		bool onPress() {
			if (justPressed) {
				justPressed = false;
				if (EVENTS_MODE)
					event(EVENT_BUTTON_PRESS);
				return true;
			}
			return false;
		}
		bool onRelease() {
			if (justReleased) {
				justReleased = false;
				if (EVENTS_MODE)
					event(EVENT_BUTTON_RELEASE);
				return true;
			}
			return false;
		}
		bool onChange(){
			if (changed) {
				changed = false;
				return true;
			}
			return false;
		}
		bool onDoubleClick(void)  { return (justReleased && (currentReleaseTime - lastReleaseTime) <= doubleClickDelay); }
		unsigned char getPressCount() { return pressCount; }
		void resetPressCount() { pressCount = 0; }
		bool onHold()  {
			if (holded) {
				holded = false;
				justHolded = true;
				currentPressTime = CURRENT_TIME;
				if (EVENTS_MODE)
					event(EVENT_BUTTON_HOLD);
				return true;
			}
			return false;
		}
		void listen() {
			if (!isEnabled())
				return;
			currentState = getState();

			if (currentState != lastState) {
				debounceTimerStartTime = CURRENT_TIME;
			} else if (debounceTimerStartTime > 0 && (CURRENT_TIME - debounceTimerStartTime) > debounceDelay) { //debounced
				debounceTimerStartTime = 0;
				lastDebouncedState = currentDebouncedState;
				currentDebouncedState = currentState;
				
				holded = false;
				if (currentDebouncedState == pressedState) {
					pressed = true;
					released = false;
					justReleased = false;
				} else {
					pressed = false;
					released = true;
					justPressed = false;
				}

				if (lastDebouncedState != currentDebouncedState) {
					changed = true;
				} else {
					changed = false;
					justPressed = false;
					justReleased = false;
				}
				if (justHolded) {
					justHolded = false;
				} else if (changed) {
					if (pressed) {
	#ifdef DEBUG_PORT
			Serial.print("button (");
			Serial.print(id);
			Serial.print(":");
			Serial.print(getPin());
			Serial.println(") pressed");
	#endif
						justPressed = true;
						justReleased = false;
						if (pressCountDelay) {
							if (lastPressTime && CURRENT_TIME - lastPressTime < pressCountDelay) pressCount++;
							else pressCount = 1;
						}
						lastPressTime = currentPressTime;
						currentPressTime = CURRENT_TIME;
					} else if (released) {
						justPressed = false;
						justReleased = true;
						lastReleaseTime = currentReleaseTime;
						currentReleaseTime = CURRENT_TIME;
					}
				}
			} else if (pressed && (CURRENT_TIME - currentPressTime) > holdDelay)
				holded = true;
			//wrap up the funtion
			lastState = currentState;
		}
	protected:
		bool pressedState; //HIGH == pressed (1) or LOW == pressed (0)

		bool lastState;
		bool currentState;

		bool lastDebouncedState;
		bool currentDebouncedState;
		unsigned long int debounceTimerStartTime;
		unsigned int debounceDelay;

		bool pressed;
		bool released;
		bool holded;
		bool justHolded;

		bool changed;
		bool justPressed;
		bool justReleased;
		unsigned long int pressCountDelay;
		unsigned char pressCount;
		//unsigned int releaseCount;


		unsigned int doubleClickDelay;
		unsigned int holdDelay;

		unsigned long int lastPressTime;
		unsigned long int currentPressTime;
		unsigned long int lastReleaseTime;
		unsigned long int currentReleaseTime;
	};
}