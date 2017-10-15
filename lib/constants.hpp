
//ROOMS
#define T_ALL				255
#define T_HOME				254
#define T_STORAGE            70
#define T_ST_MAINLIGHT       71
#define T_HALLWAY           100
#define T_HL_MAINLIGHT      101
#define T_HL_LIGHT1         102
#define T_HL_LIGHT2         103
#define T_HL_LIGHTNING      104
#define T_BATHROOM          130
#define T_BT_MAINLIGHT      131
#define T_BT_FAN            132
#define T_BT_LIGHTNING      133
#define T_BT_PIPELINE       134
#define T_BT_WARMFLOOR      135
#define T_BT_FLOORTEMP      136
#define T_BT_TEMP           137
#define T_BT_WETNESS        138
#define T_KITCHEN           160
#define T_KH_MAINLIGHT      161
#define T_BALCONY           190
#define T_BL_MAINLIGHT      191
#define T_BEDROOM           220
#define T_BD_MAINLIGHT      221

//COMMANDS
#define C_DISABLE             1
#define C_ENABLE              2
#define C_ON                  3
#define C_OFF                 4
#define C_TOGGLE              5
#define C_AUTOTIMEOUT         6
#define C_BRIGHTNESS          7
#define C_LIGHTON             3
#define C_LIGHTOFF            4
#define C_PWM                 8

#define C_GET_TEMP           21
#define C_GET_WETNESS        22

#define C_MODE                8
#define C_DAY_MODE            9
#define C_DATA               10
#define C_PWM_DELAY          11

#define C_STATE             254
#define C_PING              255

#define MODE_NONE             0
#define MODE_VACATION         1
#define MODE_NOTHOME          2
#define MODE_SLEEP            3
#define MODE_WORK             4
#define MODE_CLEAN            5
#define MODE_CINEMA           6

#define DAY_MODE_MORNING      1
#define DAY_MODE_DAY          2
#define DAY_MODE_EVENONG      3
#define DAY_MODE_NIGHT        4
