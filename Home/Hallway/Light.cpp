namespace Hallway{ namespace Light{
	using namespace Hallway;
	
	Server::State state(T_HL_MAINLIGHT);
	
	bool isOn() { return mainLight.isOn(); }
	void autoOn() {
		//mainLight.on();
		//wallLight.on();
		floorStrip.on(10);
	}
	void on() {
		mainLight.on();
		//wallLight.on();
		floorStrip.on(10);
		motionMain.off();
	}
	void off() {
		mainLight.off();
		wallLight.off();
		floorStrip.off();
		motionMain.off(10000);
	}
	void toggle() { if (isOn()) off(); else on(); }
	//void disableMain() {  }
	void listen() {
		if (motionMain.onExpire()) off();
	}
	void loop() {
		
		if (mainSwitch.onHold()) {
			Home::commandAll(C_OFF); //Выключить все
		} else if (mainSwitch.onRelease()) { //Выключатель
			if (motionMain.isActive()) { //Если включено по датчику
				if (motionMain.inTimeout())
					on(); //Включить свет если датчик сработал менее 10 сек назад
				else
					off();
			} else {
				toggle();
			}
		} else if (motionMain.onHigh()) { //Сработал датчик движения
			autoOn();
		}
	}
	void command(byte action, byte data) {
		switch (action) {
			case C_ON: on(); break;
			case C_OFF: off(); break;
			case C_TOGGLE: toggle(); break;
		}
	}
	
} }
