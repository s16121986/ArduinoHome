#define BathroomFan_h

namespace Bathroom{ namespace Fan{
	using namespace Bathroom;
	
	Button fanSwitch(PIN_BT_FAN_SWITCH);  //Выключатель
	LightRelay fanRelay(PIN_BT_FAN);

	bool flagAuto;
	Timeout tOff; //Таймер выключения
	Timeout tAuto; //60 min
	unsigned long int autoOnTimeout;
	unsigned long int autoOffTimeout;
	float crossValue;

	void off(bool fAuto) {
		fanRelay.off();

		/*if (!fAuto) {
			//Отключаем проверку влажности при ручном выключении
			tAuto.start(autoOffTimeout);
		}
		tOff.stop();
		flagAuto = fAuto;*/
	}
	void on(bool fAuto) {
		fanRelay.on();
		/*if (!fAuto && tAuto.isEnabled()) {
			tAuto.start(autoOnTimeout);
		}
		tOff.start();
		flagAuto = fAuto;*/
	}
	void toggle() {
		fanRelay.toggle();
	}
	void command(byte action, byte data) {
		fanRelay.command(action, data);
	}
	void state() { fanRelay.state(); }
	void setup() {
		//crossValue = 22;        //Граничное значение влажности
		//autoOnTimeout = 60000;  //Отключение датчика после ручного выключения
		//autoOffTimeout = 30000; 
		//tOff.set(600000);       //Выключать через 10 мин
#ifndef PIN_BT_DHT
		tAuto.disable();
#endif
		/*flagOn = false;
		flagAutoTime = 0;*/
	}
	void toggleAuto() {
#ifdef PIN_BT_DHT
		if (state.isHigh()) {
			if (tOff.onExpire() || dht.readHumidity() < crossValue) {
				off(true);
			}
		} else {
			if (dht.readHumidity() >= crossValue) {
				on(true);
			}
		}
#endif
	}
	void listen() {
		fanSwitch.listen();
		/*if (tAuto.isEnabled()) {
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
		}*/
	}
	void loop() {
		if (fanSwitch.onPress()) {
			toggle();
		}
	}
} }
