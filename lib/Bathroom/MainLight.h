namespace Bathroom{ namespace MainLight{
	using namespace Bathroom;
	Server::State state(T_BT_MAINLIGHT);
	AutoTimeout *tAuto;

	void on(bool flagAuto = false);
	void off(bool flagAuto = false);
	void command(byte action, byte data = 0);
	void setup();
	void setTimeout(AutoTimeout &t);
} }
