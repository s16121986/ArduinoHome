class AutoMotion{
public:
	AutoMotion(uint8_t pin, unsigned long int onTimeout) {
		motion.setPin(pin);
		motion.init();
		motionHighTime = 0;
		autoTimeout.set(onTimeout);
	}
	void listen() { motion.listen(); }
	void reset() {
		motionHighTime = 0; //Сброс вемени включения по датчику
		autoTimeout.stop();
	}
	bool isActive() {
		bool flag = motionHighTime > 0;
		motionHighTime = 0;
		return flag;
	}
	bool inTimeout() { return CURRENT_TIME - motionHighTime < 9000; }
	bool onHigh() {
		if (motion.onHigh()) { //Сработал датчик движения
			if (!motionHighTime) { //Время первого срабатывания датчика
				motionHighTime = CURRENT_TIME;
			}
			autoTimeout.start();
			return true;
		}
		return false;
	}
	bool onExpire() { return autoTimeout.onExpire(); }
	void off() { motion.off();reset(); }
	void off(unsigned long int delay) { motion.off(delay);reset(); }
	void on() { motion.on(); }
protected:
	Motion motion;
	Timeout autoTimeout; // таймер времени включения
	unsigned long motionHighTime;
};