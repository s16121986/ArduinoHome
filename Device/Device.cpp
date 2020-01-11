#include "Pin.cpp"
#include "Device.h"

#ifdef DEBUG_MODE
#include "Pins/uno.h"
#else
#include "Pins/mega.h"
#endif

#include "Modules/Module.cpp"
#include "Modules/ModuleD.cpp"
#include "Modules/ModuleA.cpp"
#include "Modules/Button.cpp"
#include "Modules/Relay.cpp"
#include "Modules/PWM.cpp"
	
namespace Device{
	
	//unsigned int PWM_DELAY = 500;
	//uint8_t PWM_BRIGHTNESS = 254;
	
	namespace ST{
		Button mainSwitch(M_ST_SWITCH);
		Relay mainLight(M_ST_LIGHT);
		//Gercon s(PIN_ST_DOOR);  //Датчик двери
	}
	namespace HL{
		Relay mainLight(M_HL_LIGHT);         //PWM
		Relay wallLight(M_HL_LIGHT_WALL);    //Подсветка стена
		Relay hallLight(M_HL_LIGHT_HALL);       //Коридор 2шт PWM
		//LightRelay hallLight(M_HL_LIGHT_3);       //Коридор 3шт PWM
		PWM floorStrip(M_HL_FLOORSTRIP);     //Подсветка плинтус
		
		Button mainSwitch(M_HL_SWITCH);      //Выключатель
		Button hallSwitch(M_HL_SWITCH_HALL);      //Выключатель
		
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
	}
	namespace KH{
		Button mainSwitch(M_KH_SWITCH);
		Relay mainLight(M_KH_LIGHT);
		Relay lampLight(M_KH_LIGHT_LAMP);
		Relay tableLight(M_KH_LIGHT_TABLE);
		PWM floorLightning(M_KH_LIGHTNING_FLOOR);
	}
	namespace BL{
		Relay mainLight(M_BL_LIGHT);   //PWN 
		Button mainSwitch(M_BL_SWITCH);  //Выключатель
	}
	namespace BD{
		Button mainSwitch(M_BD_SWITCH);  //Выключатель
		Relay bedLight(M_BD_LIGHT_BED);
		Relay christmasLight(M_BD_CHRISTMAS);
		PWM bedLightning(M_BD_LIGHTNING_BED);
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
		
	}
	
	void state() {
		for (uint8_t i = 0; i < _pins_count; i++) {
			if (pins[i].isEnabled())
				pins[i].state();
		}
	}
	
	void debug(uint8_t data) {
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
			
			case M_BD_SWITCH:          BD::mainSwitch.trigger(action, data); break;
			case M_BD_LIGHT_BED:       BD::bedLight.trigger(action, data); break;
			case M_BD_LIGHTNING_BED:   BD::bedLightning.trigger(action, data); break;
			
#ifdef Home_h
			default:
				Home::trigger(target, action, data);
#endif
		}
	}
	
	
}