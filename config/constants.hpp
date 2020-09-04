//------------Port codes------------

#define IO_PING_BIT               48 // "0"
#define IO_CONFIG_BIT             59 // ";"
#define IO_EVENT_BIT              60 // "<"
#define IO_TRIGGER_BIT            61 // "="
#define IO_STATE_BIT              62 // ">"
#define IO_STOP_BIT              255 // "�"
#define IO_DEBUG_BIT              33 // "!"

//------------Modules ID------------

#define T_ALL                    254 // Всем

#define T_HOME                   253 // Дом
#define M_TEMP_IN                  1 // Температура в квартире
#define M_DARKNESS_IN              2 // Освещенность в квартире
#define M_LEAK                    37 // Датчик утечки

#define T_HALLWAY                201 // Прихожая
#define M_HL_LIGHT                 6 // Основной
#define M_HL_LIGHT_WALL            7 // Стена
#define M_HL_LIGHT_HALL            8 // Коридор
#define M_HL_SWITCH_HALL           9 // Выключатель холл
#define M_HL_FLOORSTRIP           10 // Плинтус
#define M_HL_SWITCH               11 // Выключатель
#define M_HL_DOOR                 12 // Датчик двери
#define M_HL_MOTION_MAIN          13 // Датчик движения
#define M_HL_MOTION_2             14 // Датчик движения 2

#define T_BATHROOM               202 // Ванная
#define M_BT_FAN                  15 // Вытяжка
#define M_BT_SWITCH_FAN           16 // Выключатель вытяжки
#define M_BT_SWITCH               17 // Выключатель свет
#define M_BT_LIGHT                18 // Основной
#define M_BT_LIGHT_WALL           19 // Стена
#define M_BT_LIGHT_MIRROR         20 // Свет зеркало
#define M_BT_DOOR                 21 // Датчик двери
#define M_BT_MOTION_1             22 // Датчик движения 1
#define M_BT_MOTION_2             23 // Датчик движения 2
#define M_BT_GIDROLOCK            26 // Вода
#define M_BT_WARMFLOOR            30 // Теплый пол

#define T_KITCHEN                203 // Кухня
#define M_KH_LIGHT_MODULE         25 // Освещение модули
#define M_KH_LIGHTNING_FLOOR      27 // Подсветка пол
#define M_KH_SWITCH               32 // Выключатель
#define M_KH_LIGHT                33 // Основной свет
#define M_KH_LIGHT_LAMP           34 // Люстра
#define M_KH_LIGHT_TABLE          35 // Свет над столом

#define T_BEDROOM                204 // Спальня
#define M_BD_PROJECTOR            36 // Проектор
#define M_BD_LIGHT                41 // Основной свет
#define M_BD_LIGHT_BED            42 // Кровать 1
#define M_BD_CINEMA_SCREEN        43 // Экран проектора
#define M_BD_LIGHTNING_BED        44 // Подсветка кровати
#define M_BD_SWITCH               45 // Выключатель
#define M_BD_CURTAINS             47 // Портьеры
#define M_BD_LIGHT                48 // Основной свет

#define T_BALCONY                205 // Балкон
#define M_BL_WARMFLOOR            24 // Теплый пол
#define M_BL_CURTAIN_LIGHT        31 // Подсветка шторы
#define M_BL_LIGHT                38 // Основной свет
#define M_BL_SWITCH               39 // Выключатель
#define M_BL_CURTAINS             40 // Портьеры

#define T_STORAGE                206 // Кладовка
#define M_ST_LIGHT                 3 // Основной
#define M_ST_SWITCH                4 // Выключатель
#define M_ST_DOOR                  5 // Датчик двери
#define M_ST_VENTILATION          49 // Вентиляция


//-------------Commands-------------

#define C_DISABLE                  1 // Деактивировать
#define C_ENABLE                   2 // Активировать
#define C_ON                       3 // Включить
#define C_OFF                      4 // Выключить
#define C_TOGGLE                   5 // Переключить
#define C_PWM                      6 // ШИМ
#define C_TEMPERATURE             21 // Температура
#define C_DEBUG                  251 // Отладка
#define C_SETPIN                 252 // Задать pin
#define C_PING                   253 // ping
#define C_STATE                  254 // Состояние

//--------------Events--------------

#define EVENT_INIT                 1 // 
#define EVENT_BUTTON_PRESS        11 // 
#define EVENT_BUTTON_RELEASE      12 // 
#define EVENT_BUTTON_HOLD         13 //