namespace Hallway{ namespace Light{
	using namespace Hallway;
	Server::State state(T_HL_MAINLIGHT);

	void on();
	void off();
	void command(byte action, byte data = 0);
	void setup();
} }
