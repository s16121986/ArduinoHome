#define BathroomPipeline_h

namespace Bathroom{ namespace Pipeline{
	Server::State state(T_BT_PIPELINE);
	Gidrolock gidrolock(PIN_BT_GIDROLOCK, PIN_BT_GIDROLOCK, true);
	Leak sFloor(PIN_BT_LEACK_1);
	//ModuleD sPipeline(PIN_BT_LEACK_2);
	Timeout timerOn;
	bool leackState;
	bool autoEnabled;
	
	void setup();
	void listen();
	void loop();
	void command(byte action, byte data = 0);
} }
