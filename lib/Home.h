namespace Home{
	Server::State state(T_HOME);
	bool disabled;
	uint8_t MODE;
	uint8_t DAY_MODE;
	ModuleA darkSensor(PIN_DARKNESS, INPUT);
	//unsigned time;
	//unsigned dayMode;
	
	void disable();
	void setup();
	void listen();
	void loop();
	void commandAll(byte action, byte data = 0);
	void commandAll(byte target, byte action, byte data);
	void setMode(uint8_t mode);
	void setDayMode(uint8_t mode);
	void command(byte action, byte data = 0);
	void command(byte target, byte action, byte data);
}
