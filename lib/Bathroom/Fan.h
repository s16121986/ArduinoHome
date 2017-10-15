#define BathroomFan_h

namespace Bathroom{ namespace Fan{
	Server::State state(T_BT_FAN);
	Button b(PIN_BT_FAN_SWITCH);  //Выключатель
	Relay r(PIN_BT_FAN);

	bool flagAuto;
	Timeout tOff; //Таймер выключения
	Timeout tAuto; //60 min
	unsigned long int autoOnTimeout;
	unsigned long int autoOffTimeout;
	float crossValue;
	void off(bool fAuto = false);
	void on(bool fAuto = false);
	void toggle();
	void command(byte action, byte data = 0);
	void setup();
	void toggleAuto();
	void listen();
	void loop();
} }
