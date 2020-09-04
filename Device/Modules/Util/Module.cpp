//using ::NSTrigger::Action;
namespace Device{
	
	class Module{
	public:
		Module() {
			id = 0;
			devicePin = 0;
			enabled = true;
		}
		Module(uint8_t id) : Module() { setId(id); }
		Module(uint8_t id, uint8_t mode) : Module(id) {
			setMode(mode);
		};
		virtual bool writeOnly() { return false; }
		virtual void init() {}
		virtual void enable() { enabled = true; }
		virtual void disable() { enabled = false; }
		void setId(uint8_t id) { this->id = id; }
		void setMode(uint8_t mode) { this->mode = mode; }
		bool hasPin() { return devicePin != 0; }
		void setPin(uint8_t pinId) {
			if (pinId == 0) {
				if (!hasPin())
					return;
				disable();
				devicePin = 0;
			} else {
				if (hasPin() && pinId == (*devicePin).pin)
					return;
				if (Device::hasPin(pinId)) {
					devicePin = &Device::getPin(pinId);
					init();
					(*devicePin).enable();
				}
			}
			
		}
		uint8_t getPin() { return (*devicePin).pin; }
		bool isEnabled() { return enabled && (*devicePin).isEnabled(); }
		void state() {
			if (hasPin())
				(*devicePin).state();
		}
		void event(uint8_t e, uint8_t data = 0) {
			if (hasPin())
				(*devicePin).event(e, data);
		}
		void trigger(uint8_t action, uint8_t data = 0) {
			switch (action) {
				case C_SETPIN:
					setPin(data);
					state(); 
					break;
			}
		}
		
		uint8_t id;
		uint8_t mode;
	protected:
		Pin *devicePin;
		bool enabled;
	};
}