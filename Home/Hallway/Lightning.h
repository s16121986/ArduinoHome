namespace Hallway{ namespace Lightning{
	using namespace Hallway;
	Server::State state(T_HL_LIGHTNING);
	void command(byte action, byte data = 0);
	void setup();
	void listen();
	void loop();
} }
