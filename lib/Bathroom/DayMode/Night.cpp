namespace Bathroom{ namespace DayModeNight{
	void setup() {
		dayModeListen = listen;
		dayModeLoop = loop;
		MainLight::setTimeout(tAuto);
	}
	void listen() {
		if (tAuto.isOn()) motion_1.listen();
	}
	void loop() {
		if (mainSwitch.onPress()) {
			if (tAuto.isEnabled()) {
				tAuto.off();
				tAuto.onDelay();
				if (MainLight::state.isHigh() && !tAuto.isDelay()) {
					MainLight::off();
					wallLight.off();
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
					if (MainLight::state != STATE_ON) wallLight.on();
					tAuto.startAuto();
				} else if (tAuto.onAuto()) {
					wallLight.off();
				}
			} else if (tAuto.onDelay()) {
				motion_1.onHigh();
				tAuto.on();
			}
		}
	}
} }
