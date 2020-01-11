namespace Hallway{ namespace ModeDay{
	void setup() {
		modeListen = listen;
		modeLoop = loop;
		//MainLight::setTimeout(tAuto);
		floorStrip.off();
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
					if (MainLight::state.isLow()) MainLight::on();
					tAuto.startAuto();
				} else if (tAuto.onAuto()) {
					MainLight::off();
				}
			} else if (tAuto.onDelay()) {
				motion_1.onHigh();
				tAuto.on();
			}
		}
	}
} }
