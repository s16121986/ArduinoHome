namespace Bathroom{ namespace Fan{

	void off(bool fAuto = false) {
		r.off();
		state.low();

		if (!fAuto) {
			//Отключаем проверку влажности при ручном выключении
			tAuto.start(autoOffTimeout);
		}
		tOff.stop();
		flagAuto = fAuto;
	}
	void on(bool fAuto = false) {
		r.on();
		state.high();
		if (!fAuto && tAuto.isEnabled()) {
			tAuto.start(autoOnTimeout);
		}
		tOff.start();
		flagAuto = fAuto;
	}
	void toggle() {
		if (state.isHigh()) off(); else on();
	}
	void command(byte action, byte data = 0) {
		switch (action) {
			case C_ON:on();break;
			case C_OFF:off();break;
			case C_TOGGLE:toggle();break;
		}
	}
	void setup() {
		crossValue = 22;        //Граничное значение влажности
		autoOnTimeout = 60000;  //Отключение датчика после ручного выключения
		autoOffTimeout = 30000; 
		tOff.set(600000);       //Выключать через 10 мин
#ifndef PIN_BT_DHT
		tAuto.disable();
#endif
		/*flagOn = false;
		flagAutoTime = 0;*/
	}
	void toggleAuto() {
		if (state.isHigh()) {
			if (tOff.onExpire() || dht.readHumidity() < crossValue) {
				off(true);
			}
		} else {
			if (dht.readHumidity() >= crossValue) {
				on(true);
			}
		}
	}
	void listen() {
		b.listen();
		if (tAuto.isEnabled()) {
			if (flagAuto) {
				toggleAuto();
			} else {
				tAuto.update();
				if (!tAuto.isStarted()) {
					toggleAuto();
				}
			}
		} else if (tOff.onExpire()) {
			off();
		}
	}
	void loop() {
		if (b.onPress()) {
			toggle();
		}
	}
} }
