#define Hallway_h

namespace Hallway{	
	void setup();
	void listen();
	void loop();
	void command(byte action, byte data = 0);
	void trigger(byte target, byte action, byte data = 0);
}
