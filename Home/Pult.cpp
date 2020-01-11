#define Pult_h

#define PULT_TEST

#include <IRremote.h>

namespace Pult{
	
	IRrecv irrecv(PIN_PULT);
	decode_results results;
	
	enum Codes{
#ifdef PULT_TEST
		CODE_NONE,
		CODE_NUM_1, CODE_NUM_2, CODE_NUM_3, CODE_NUM_4, CODE_NUM_5, CODE_NUM_6, CODE_NUM_7, CODE_NUM_8, CODE_NUM_9, CODE_NUM_0,
		CODE_UP, CODE_DOWN, CODE_LEFT, CODE_RIGHT,
		CODE_ASTERISK, CODE_HASH, CODE_OK,
		CODE_UNDEFINED
#endif
	};
	
	uint8_t getCodeNum(uint8_t code) {
		switch (code) {
			case CODE_NUM_0: return 10;
			case CODE_NUM_1: return 1;
			case CODE_NUM_2: return 2;
			case CODE_NUM_3: return 3;
			case CODE_NUM_4: return 4;
			case CODE_NUM_5: return 5;
			case CODE_NUM_6: return 6;
			case CODE_NUM_7: return 7;
			case CODE_NUM_8: return 8;
			case CODE_NUM_9: return 9;
		}
		return 0;
	}
	Codes getCode(unsigned int code) {
		switch (code) {
			case 0xFFFFFFFF:
				return CODE_NONE;
			case 0xFFA25D:
			case 0xE318261B:
			case 0xFFA25:
				return CODE_NUM_1;
			case 0xFF629D:
			case 0x511DBB:
				return CODE_NUM_2;
			case 0xFFE21D:
				return CODE_NUM_3;
			case 0xFF22DD:
				return CODE_NUM_4;
			case 0xFF02FD:
			case 0xD7E84B1B:
				return CODE_NUM_5;
			case 0xFFC23D:
				return CODE_NUM_6;
			case 0xFFE01F:
				return CODE_NUM_7;
			case 0xFFA857:
				return CODE_NUM_8;
			case 0xFF906F:
				return CODE_NUM_9;
			case 0xFF:
				return CODE_NUM_0;
			case 0xFF18E7:
				return CODE_UP;
			case 0x1BC0157B:
				return CODE_DOWN;
			case 0xFF10EF:
				return CODE_LEFT;
			case 0xFF5AA5:
				return CODE_RIGHT;
			case 0xC101E57B:
				return CODE_ASTERISK;
			case 0xF0C41643:
				return CODE_HASH;
			case 0xFF38C7:
				return CODE_OK;
		}
		return CODE_UNDEFINED;
	}
	
	uint8_t codeGroup;
	uint8_t codeGroupNum;
	
	
	void sendCode(uint8_t code) {
		switch (code) {
#ifdef Home_h
			case 0: Home::commandAll(C_OFF);
#endif
#ifdef Storage_h

#endif
#ifdef Hallway_h
			case 11: Hallway::command(PIN_HL_LIGHT, C_TOGGLE, 0); break;
			case 12: Hallway::command(PIN_HL_LIGHT_WALL, C_TOGGLE, 0); break;
			case 13: Hallway::command(PIN_HL_FLOORSTRIP, C_TOGGLE, 0); break;
			case 14: Hallway::command(PIN_HL_LIGHT_2, C_TOGGLE, 0); break;
			case 15: Hallway::command(PIN_HL_LIGHT_3, C_TOGGLE, 0); break;
#endif
#ifdef Bathroom_h
			case 21: Bathroom::command(PIN_BT_LIGHT, C_TOGGLE, 0); break;
			case 22: Bathroom::command(PIN_BT_WALLLIGHT, C_TOGGLE, 0); break;
			case 23: Bathroom::command(PIN_BT_LIGHT_2, C_TOGGLE, 0); break;
			case 24: Bathroom::command(PIN_BT_FAN, C_TOGGLE, 0); break;
#endif
#ifdef Kitchen_h
			case 31: Kitchen::command(PIN_KH_LIGHT, C_TOGGLE, 0); break;
			case 32: Kitchen::command(PIN_KH_LIGHT_1, C_TOGGLE, 0); break;
			case 33: Kitchen::command(PIN_KH_LIGHT_2, C_TOGGLE, 0); break;
#endif
#ifdef Balcony_h
			case 41: Balcony::command(PIN_BL_LIGHT, C_TOGGLE, 0); break;
#endif
#ifdef Bedroom_h
			case 51: Bedroom::command(PIN_BD_LIGHT_1, C_TOGGLE, 0); break;
			case 52: Bedroom::command(PIN_BD_LIGHT_2, C_TOGGLE, 0); break;
			case 53: Bedroom::command(PIN_BD_LIGHTNING_BED, C_TOGGLE, 0); break;
#endif
		}
	}
	
	void setCodeGroup(uint8_t num) {
		codeGroup = num;
		codeGroupNum = 0;
	}
	
	void setup() {
		irrecv.enableIRIn(); // запускаем прием
		Serial.println("irrecv ready");
		codeGroup = 0;
		codeGroupNum = 0;
	}	

	void loop() {
		if (irrecv.decode( &results )) { // если данные пришли
			uint8_t code = getCode(results.value);
#ifdef DEBUG_PORT
			Serial.print("pult code: ");
			switch (code) {
				case CODE_NONE: Serial.print("NONE"); break;
				case CODE_UNDEFINED: Serial.print("UNDEFINED"); break;
				case CODE_NUM_0: Serial.print("NUM_0"); break;
				case CODE_NUM_1: Serial.print("NUM_1"); break;
				case CODE_NUM_2: Serial.print("NUM_2"); break;
				case CODE_NUM_3: Serial.print("NUM_3"); break;
				case CODE_NUM_4: Serial.print("NUM_4"); break;
				case CODE_NUM_5: Serial.print("NUM_5"); break;
				case CODE_NUM_6: Serial.print("NUM_6"); break;
				case CODE_NUM_7: Serial.print("NUM_7"); break;
				case CODE_NUM_8: Serial.print("NUM_8"); break;
				case CODE_NUM_9: Serial.print("NUM_9"); break;
				case CODE_ASTERISK: Serial.print("ASTERISK"); break;
				case CODE_HASH: Serial.print("HASH"); break;
				case CODE_OK: Serial.print("OK"); break;
				case CODE_UP: Serial.print("UP"); break;
				case CODE_DOWN: Serial.print("DOWN"); break;
				case CODE_LEFT: Serial.print("LEFT"); break;
				case CODE_RIGHT: Serial.print("RIGHT"); break;
			}
			Serial.print(" : ");
			Serial.println( results.value, HEX); // печатаем данные
			
#endif
			if (code == CODE_NONE || code == CODE_UNDEFINED) {
				
			} else {
				uint8_t num = getCodeNum(code);
				if (codeGroup == 0) {
					if (num > 0) {
						setCodeGroup(num);
					} else {
						
					}
				} else {
					if (num > 0) {
						if (codeGroupNum > 0) {
							setCodeGroup(num);
						} else {
							codeGroupNum = num;
							sendCode(codeGroup * 10 + num);
						}
					} else {
						
					}
					//lastCode = currentCode;
					//currentCode.reset();
				}
			}			
			irrecv.resume(); // принимаем следующую команду
		}
	}
	
}