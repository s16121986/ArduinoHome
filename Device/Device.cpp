#include "Pin.cpp"
#include "Device.h"

#ifdef DEBUG_MODE
#include "Pins/uno.h"
#else
#include "Pins/mega.h"
#endif

#include "Modules/Util/Module.cpp"
#include "Modules/Util/ModuleD.cpp"
#include "Modules/Util/ModuleA.cpp"
#include "Modules/Button.cpp"
#include "Modules/Relay.cpp"
#include "Modules/PWM.cpp"
#include "Modules/Ping.cpp"
#include "Modules/PWMD.cpp"
	
namespace Device{
	
	//unsigned int PWM_DELAY = 500;
	//uint8_t PWM_BRIGHTNESS = 254;
	
	namespace ST{
		Button mainSwitch(M_ST_SWITCH);
		Relay mainLight(M_ST_LIGHT);
		PWMD vent(M_ST_VENTILATION);
		//Gercon s(PIN_ST_DOOR);  //Датчик двери
	}
	namespace HL{
		Relay mainLight(M_HL_LIGHT);           //PWM
		Relay wallLight(M_HL_LIGHT_WALL);      //Подсветка стена
		PWMD hallLight(M_HL_LIGHT_HALL);       //Коридор 2шт PWM
		//LightRelay hallLight(M_HL_LIGHT_3);  //Коридор 3шт PWM
		PWM floorStrip(M_HL_FLOORSTRIP);       //Подсветка плинтус
		
		Button mainSwitch(M_HL_SWITCH);        //Выключатель
		Button hallSwitch(M_HL_SWITCH_HALL);   //Выключатель
		
		//AutoMotion motionMain(M_HL_MOTION_MAIN, 10000); //Датчик движения пуфик
	}
	namespace BT{
		//Motion motion_1(M_BT_MOTION_1);
#ifdef M_BT_DHT
		//DHT dht(M_BT_DHT, DHT11);
#endif
		Button mainSwitch(M_BT_SWITCH);    //Выключатель
		Button fanSwitch(M_BT_SWITCH_FAN);    //Выключатель
		Relay mainLight(M_BT_LIGHT);       //PWM
		Relay wallLight(M_BT_LIGHT_WALL);
		Relay fan(M_BT_FAN);
		PWMD warmFloor(M_BT_WARMFLOOR);
	}
	namespace KH{
		Button mainSwitch(M_KH_SWITCH);
		PWMD mainLight(M_KH_LIGHT);
		Relay lampLight(M_KH_LIGHT_LAMP);
		PWMD tableLight(M_KH_LIGHT_TABLE);
		PWM floorLightning(M_KH_LIGHTNING_FLOOR);
	}
	namespace BL{
		PWMD mainLight(M_BL_LIGHT);   //PWN 
		Button mainSwitch(M_BL_SWITCH);  //Выключатель
		Ping curtains(M_BL_CURTAINS);
		PWMD warmFloor(M_BL_WARMFLOOR);
	}
	namespace BD{
		Button mainSwitch(M_BD_SWITCH);  //Выключатель
		PWMD mainLight(M_BD_LIGHT);
		PWMD bedLight(M_BD_LIGHT_BED);
		//Relay christmasLight(M_BD_CHRISTMAS);
		PWM bedLightning(M_BD_LIGHTNING_BED);
		Ping curtains(M_BD_CURTAINS);
	}
	
	bool hasPin(uint8_t pin) {
		for (uint8_t i = 0; i < _pins_count; i++) {
			if (pins[i].pin == pin)
				return true;
		}
		return false;
	}
	
	Pin& getPin(uint8_t pin) {
		for (uint8_t i = 0; i < _pins_count; i++) {
			if (pins[i].pin == pin)
				return pins[i];
		}
	}
	
	void setup() {
		delay(1000);
		Device::sendEvent(T_HOME, EVENT_INIT); //pins request
	}
	
	void loop() {
		//digital pwm loop
		HL::hallLight.loop();
		
		BT::warmFloor.loop();
		
		KH::mainLight.loop();
		KH::tableLight.loop();
		
		BL::mainLight.loop();
		BL::warmFloor.loop();
		BL::curtains.loop();
		
		BD::mainLight.loop();
		BD::bedLight.loop();
		BD::curtains.loop();
		
		ST::vent.loop();
	}
	
	void state() {
		for (uint8_t i = 0; i < _pins_count; i++) {
			if (pins[i].isEnabled())
				pins[i].state();
		}
	}
	
	void debug(uint8_t action, uint8_t data) {
		switch (data) {
			case 0:
				uint8_t buf[5];
				buf[0] = IO_STATE_BIT;
				buf[1] = 17;
				buf[2] = 4;
				buf[3] = 19;
				buf[4] = IO_STOP_BIT;
				Serial.write(buf, 5);
				break;
		}
	}
	
	void trigger(uint8_t target, uint8_t action, uint8_t data) {
		switch (target) {
			
			case M_ST_SWITCH:          ST::mainSwitch.trigger(action, data); break;
			case M_ST_LIGHT:           ST::mainLight.trigger(action, data); break;
			case M_ST_VENTILATION:     ST::vent.trigger(action, data); break;
			
			case M_HL_LIGHT:           HL::mainLight.trigger(action, data); break;
			case M_HL_LIGHT_WALL:      HL::wallLight.trigger(action, data); break;
			case M_HL_LIGHT_HALL:      HL::hallLight.trigger(action, data); break;
			case M_HL_FLOORSTRIP:      HL::floorStrip.trigger(action, data); break;
			case M_HL_SWITCH:          HL::mainSwitch.trigger(action, data); break;
			case M_HL_SWITCH_HALL:     HL::hallSwitch.trigger(action, data); break;
			//case M_HL_MOTION_MAIN: HL::motionMain.trigger(action, data); break;
			
			case M_BT_SWITCH:          BT::mainSwitch.trigger(action, data); break;
			case M_BT_SWITCH_FAN:      BT::fanSwitch.trigger(action, data); break;
			case M_BT_LIGHT:           BT::mainLight.trigger(action, data); break;
			case M_BT_LIGHT_WALL:      BT::wallLight.trigger(action, data); break;
			case M_BT_FAN:             BT::fan.trigger(action, data); break;
			
			case M_KH_SWITCH:          KH::mainSwitch.trigger(action, data); break;
			case M_KH_LIGHT:           KH::mainLight.trigger(action, data); break;
			case M_KH_LIGHT_LAMP:      KH::lampLight.trigger(action, data); break;
			case M_KH_LIGHT_TABLE:     KH::tableLight.trigger(action, data); break;
			case M_KH_LIGHTNING_FLOOR: KH::floorLightning.trigger(action, data); break;
			
			case M_BL_SWITCH:          BL::mainSwitch.trigger(action, data); break;
			case M_BL_LIGHT:           BL::mainLight.trigger(action, data); break;
			case M_BL_CURTAINS:        BL::curtains.trigger(action, data); break;
			
			case M_BD_SWITCH:          BD::mainSwitch.trigger(action, data); break;
			case M_BD_LIGHT_BED:       BD::bedLight.trigger(action, data); break;
			case M_BD_LIGHTNING_BED:   BD::bedLightning.trigger(action, data); break;
			case M_BD_CURTAINS:        BD::curtains.trigger(action, data); break;
			
#ifdef Home_h
			default:
				Home::trigger(target, action, data);
#endif
		}
	}
	
	
}