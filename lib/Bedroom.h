#define Bedroom_h

namespace Bedroom{	
	void setup();
	void listen();
	void loop();
	void command(byte action, byte data = 0);
	void command(byte target, byte action, byte data);
}