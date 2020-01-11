#define Bathroom_h
//#include "MainLight.h"
//#include "Pipeline.h"
//#include "Bathroom/WarmFloor.h"
//#include "Bathroom/Flowers.h"
//#include "Bathroom/Lightning.h"
//#include "Bathroom/Installation.h"

namespace Bathroom{	
	void setup();
	void listen();
	void loop();
	void command(byte action, byte data = 0);
	void trigger(byte target, byte action, byte data);
}
