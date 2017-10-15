namespace Hallway{ namespace DayModeNight{
	void listen() {
		if (tAuto.isOn()) motion_1.listen();
		//Serial.println(motion_1.getState());
	}
	void loop() {
		if (mainSwitch.onPress()) {
			if (tAuto.isEnabled()) {
				tAuto.off();
				tAuto.onDelay();
				if (MainLight::state.isHigh() && !tAuto.isDelay()) {
					MainLight::off();
					floorStrip.on(1);
				} else {
					MainLight::on();
					tAuto.stopDelay();
				}
			} else {
				MainLight::command(C_TOGGLE);
			}
		} else if (tAuto.isEnabled()) {
			if (tAuto.isOn()) {
				if (motion_1.onHigh()) {					
					if (!floorStrip.isOn()) { floorStrip.on(128); }
					tAuto.startAuto();
				} else if (tAuto.onAuto()) {
					floorStrip.on(1);
				}
			} else if (tAuto.onDelay()) {
				motion_1.onHigh();
				tAuto.on();
			}
		}
	}
	void setup() {
		dayModeListen = listen;
		dayModeLoop = loop;
		MainLight::setTimeout(tAuto);
		floorStrip.on(1);
	}
} }
