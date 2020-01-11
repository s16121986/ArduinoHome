#define Home_h

namespace Home{
	bool disabled;
	//ModuleA darkSensor(PIN_DARKNESS_IN, INPUT);
	
	void disable();
	void setup();
	void listen();
	void loop();
	void commandAll(byte action, byte data = 0);
	void triggerAll(byte target, byte action, byte data = 0);
	void command(byte action, byte data = 0);
	void trigger(byte target, byte action, byte data = 0);
}
