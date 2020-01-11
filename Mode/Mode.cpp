#define MODE_AUTO             0
#define MODE_DAY              1
#define MODE_VACATION         2
#define MODE_NOTHOME          3
#define MODE_SLEEP            4
#define MODE_WORK             5
#define MODE_CLEAN            6
#define MODE_CINEMA           7
#define MODE_EVENING          8
#define MODE_NIGHT            9
#define MODE_MORNING         10

namespace Mode{
	
	bool modeAuto = true;
	byte mode;
	
	//unsigned int PWM_DELAY = 1500;
	//byte PWM_BRIGHTNESS = 255;
	
	
	void _default() {
		//Hallway::Light::enableAuto();
		//Hallway::Lightning::disableAuto();
	}
	void setAuto(bool flag) {
		modeAuto = flag;
	}
	void set(byte mode) {
		//Hallway::Light::motionMain.disable();
		switch (mode) {
			case MODE_AUTO:
				
				break;
		}
	}
}