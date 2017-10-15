namespace Hallway{ namespace MainLight{
	using namespace Hallway;
	Server::State state(T_HL_MAINLIGHT);
	AutoTimeout *tAuto;

	void on(bool flagAuto = false);
	void off(bool flagAuto = false);
	void command(byte action, byte data = 0);
	void setup();
	void setTimeout(AutoTimeout &t);
} }
