#define Balcony_h

namespace Balcony{	
	void setup();
	void listen();
	void loop();
	void command(uint8_t action, uint8_t data = 0);
	void trigger(uint8_t target, uint8_t action, uint8_t data = 0);
}
