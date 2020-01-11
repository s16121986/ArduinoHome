//#include "Light.cpp"
//#include "Lightning.cpp"

namespace Hallway{
	using namespace Device::HL;		
	
	void setup() {
		//MainLight::setup();
		//HallLight::setup();
		//Lightning::setup();
		//update();
		//Memory::init(autoTimeout, M_BT_MAINLIGHT_AUTOTIMEOUT, 20000, 1000);
	}
	void listen() {
		//HallLight::listen();
		//Lightning::listen();
		mainSwitch.listen();
		hallSwitch.listen();
		//motionMain.listen();
		//Light::listen();
	}
	void loop() {
		//HallLight::loop();
		//Lightning::loop();
		//Light::loop();
		
		if (mainSwitch.onHold()) {
			if (!EVENTS_MODE)
				Home::commandAll(C_OFF); //Выключить все
		} else if (mainSwitch.onRelease()) { //Выключатель
			/*if (motionMain.isActive()) { //Если включено по датчику
				if (motionMain.inTimeout())
					command(C_LIGHTON, 0); //Включить свет если датчик сработал менее 10 сек назад
				else
					command(C_LIGHTOFF, 0);
			} else {
				command(C_LIGHTTOGGLE, 0);
			}*/
			if (!EVENTS_MODE)
				mainLight.toggle();
				//command(C_LIGHTTOGGLE, 0);
		}// else if (motionMain.onHigh()) { //Сработал датчик движения
			//autoOn();
		//}
		if (hallSwitch.onPress()) {
			if (!EVENTS_MODE)
				hallLight.toggle();
		}
	}
	void command(byte action, byte data) {
		/*switch (action) {
			case C_LIGHTON:
				mainLight.on();
				break;
			case C_LIGHTOFF:
				mainLight.off();
				wallLight.off();
				hallLight.off();
				break;
			case C_LIGHTTOGGLE:
				mainLight.toggle();
				break;
			case C_STATE:
				mainLight.state();
				wallLight.state();
				hallLight.state();
				floorStrip.state();
				break;
			case C_AUTOTIMEOUT:
				//autoTimeout = data * 1000;
				//flagAuto = data > 0;
				//Memory::set(M_HL_MAINLIGHT_AUTOTIMEOUT, (uint8_t)data);
				break;
		}*/
	}
	void trigger(byte target, byte action, byte data = 0) {
		switch (target) {
			//case T_HL_MAINLIGHT: mainLight.command(action, data); break;
			//case T_HL_LIGHTNING: floorStrip.command(action, data); break;
			
			//case motionMain.getPin(): motionMain.command(action, data); break;
		}
	}
}

