// room-home / 254
#define PIN_TEMP_IN               A0 // Температура в квартире
#define PIN_TEMP_OUT              A1 // Температура на улице
#define PIN_DARKNESS_IN           A4 // Освещенность в квартире
#define PIN_LEAK                   0 // Датчик утечки

// room-storage / 70
#define PIN_ST_LIGHT               4 // Основной
#define PIN_ST_SWITCH              8 // Выключатель
#define PIN_ST_DOOR                7 // Датчик двери

// room-hallway / 100
#define PIN_HL_LIGHT              12 // Основной
#define PIN_HL_LIGHT_WALL         18 // Стена
#define PIN_HL_LIGHT_2            16 // Коридор 1
#define PIN_HL_LIGHT_3             0 // Коридор 2
#define PIN_HL_FLOORSTRIP          5 // Плинтус
#define PIN_HL_SWITCH             14 // Выключатель
#define PIN_HL_DOOR                0 // Датчик двери
#define PIN_HL_MOTION_MAIN        15 // Датчик движения
#define PIN_HL_MOTION_2            0 // Датчик движения 2

// room-bathroom / 130
#define PIN_BT_FAN                22 // Вытяжка
#define PIN_BT_FAN_SWITCH         23 // Выключатель вытяжки
#define PIN_BT_SWITCH             24 // Выключатель свет
#define PIN_BT_LIGHT              25 // Основной свет
#define PIN_BT_WALLLIGHT          28 // Свет стена
#define PIN_BT_LIGHT_2             0 // Подсветка
#define PIN_BT_DOOR                0 // Датчик двери
#define PIN_BT_MOTION_1           26 // Датчик движения 1
#define PIN_BT_MOTION_2            0 // Датчик движения 2
#define PIN_BT_LEACK_1            35 // Датчик утечки 1
#define PIN_BT_LEACK_2            36 // Датчик утечки 2
#define PIN_BT_GIDROLOCK_COLD     37 // Холодная вода
#define PIN_BT_GIDROLOCK_HOT      38 // Горячая вода
#define PIN_BT_WARMFLOOR          27 // Теплый пол

// room-kitchen / 160
#define PIN_KH_SWITCH             33 // Выключатель
#define PIN_KH_LIGHT              34 // Основной свет
#define PIN_KH_LIGHT_1             0 // Люстра
#define PIN_KH_LIGHT_2             0 // Свет над столом

// room-balcony / 190
#define PIN_BL_LIGHT              41 // Основной свет
#define PIN_BL_SWITCH             42 // Выключатель
#define PIN_BL_CURTAIN             0 // Портьеры

// room-bedroom / 220
#define PIN_BD_LIGHT               0 // Основной свет
#define PIN_BD_LIGHT_1             0 // light_1
#define PIN_BD_LIGHT_2             0 // light_2
#define PIN_BD_LIGHTNING_BED       0 // Подсветка кровати
#define PIN_BD_SWITCH             43 // Выключатель
#define PIN_BD_SWITCH_2            0 // switch_2
#define PIN_BD_CURTAIN             0 // Портьеры

uint8_t PIN_TEST1 = 1;
