#ifndef __AT_COMMAND_H__
#define __AT_COMMAND_H__

#include <stddef.h>

/* A - ANSWER
	answers an incoming call
*/
static const char * AT_COMMAND_ANSWER = "A";
static const size_t AT_COMMAND_ANSWER_SIZE = 1;

/* A/ - REPEAT
	repeats the last command given to the device
*/
static const char * AT_COMMAND_REPEAT = "A/";
static const size_t AT_COMMAND_REPEAT_SIZE = 2;

/* D[phoneNumber][AT_COMMAND_DIAL_OPTION] - DIAL
	dials the phone number and attempts to call
*/
static const char * AT_COMMAND_DIAL = "D%s%c";
static const size_t AT_COMMAND_DIAL_SIZE = 1;
typedef enum AT_COMMAND_DIAL_OPTION {
	AT_COMMAND_DIAL_OPTION_PULSE, // P - Pulse Dial
	AT_COMMAND_DIAL_OPTION_TOUCH_TONE, // T - touch tone dial
	AT_COMMAND_DIAL_OPTION_AWAIT_TONE, // W - wait for second dial tone
	AT_COMMAND_DIAL_OPTION_REVERT, // R - revert to answer mode after dialing
	AT_COMMAND_DIAL_OPTION_AWAIT_RINGBACK, // @ - wait for one or more ringbacks (times out after 30 seconds)
	AT_COMMAND_DIAL_OPTION_PAUSE, // , - pause for the time specified in register S8 (usually 2 seconds)
	AT_COMMAND_DIAL_OPTION_REMAIN_IN_COMMAND, // ; - remain in command mode after dialing
	AT_COMMAND_DIAL_OPTION_FLASH, // ! - flash switch hook (hang up for half a second; transfers the call)
	AT_COMMAND_DIAL_OPTION_REDIAL // L - redials last number
} AT_COMMAND_DIAL_OPTION;
static const size_t AT_COMMAND_DIAL_OPTIONS_SIZE = 1;
static const char AT_COMMAND_DIAL_OPTION_PULSE_CHAR = 'P';
static const char AT_COMMAND_DIAL_OPTION_TOUCH_TONE_CHAR = 'T';
static const char AT_COMMAND_DIAL_OPTION_AWAIT_TONE_CHAR = 'W';
static const char AT_COMMAND_DIAL_OPTION_REVERT_CHAR = 'R';
static const char AT_COMMAND_DIAL_OPTION_AWAIT_RINGBACK_CHAR = '@';
static const char AT_COMMAND_DIAL_OPTION_PAUSE_CHAR = ',';
static const char AT_COMMAND_DIAL_OPTION_REMAIN_IN_COMMAND_CHAR = ';';
static const char AT_COMMAND_DIAL_OPTION_FLASH_CHAR = '!';
static const char AT_COMMAND_DIAL_OPTION_REDIAL_CHAR = 'L';

/* E[n = 0] - ECHO
	sets whether the device should echo commands to the computer

	n: default = 0
	0 - off
	1 - on
*/
static const char * AT_COMMAND_ECHO_DISABLE = "E";
static const size_t AT_COMMAND_ECHO_DISABLE_SIZE = 1;
static const char * AT_COMMAND_ECHO_ENABLE = "E1";
static const size_t AT_COMMAND_ECHO_ENABLE_SIZE = 2;

/* H<n> HOOK
	hangs up or picks up the phone

	n:
	0 - hangs up the phone
	1 - picks up the phone
*/
static const char * AT_COMMAND_HOOK_ENABLE = "H0";
static const size_t AT_COMMAND_HOOK_ENABLE_SIZE = 2;
static const char * AT_COMMAND_HOOK_DISABLE = "H1";
static const size_t AT_COMMAND_HOOK_DISABLE_SIZE = 2;

/* I<lineNum> - INFO
	requests a line of device information

	lineNum: integer 0 - 9
*/
static const char * AT_COMMAND_INFO = "I%d"; // followed by "1" to "9" based on which firmware information line to pull
static const size_t AT_COMMAND_INFO_SIZE = 1;
static const size_t AT_COMMAND_INFO_OPTIONS_SIZE = 1;
static const unsigned int AT_COMMAND_INFO_OPTION_ID_MIN = 0;
static const unsigned int AT_COMMAND_INFO_OPTION_ID_MAX = 9;

/* L<volume> - LOUDNESS
	sets the speaker's volume level

	volume level:
	0 - off
	1 - low
	2 - medium
	3 - high
*/
static const char * AT_COMMAND_LOUDNESS = "L%d"; // followed by "0" to "3", setting the loudness of the ringer speaker
static const size_t AT_COMMAND_LOUDNESS_SIZE = 1;
typedef enum AT_COMMAND_LOUDNESS_OPTION {
	AT_COMMAND_LOUDNESS_OPTION_OFF = 0,
	AT_COMMAND_LOUDNESS_OPTION_LOW = 1,
	AT_COMMAND_LOUDNESS_OPTION_MEDIUM = 2,
	AT_COMMAND_LOUDNESS_OPTION_HIGH = 3
} AT_COMMAND_LOUDNESS_OPTION;
static const size_t AT_COMMAND_LOUDNESS_OPTIONS_SIZE = 1;

/* M<mode> - SPEAKER MODE
	sets the speaker's mode

	mode:
	0 - speaker off, completely silent during dialing
	1 - speaker on until remote carrier detected
	2 - speaker always on (data sounds are heard after connect)
*/
static const char * AT_COMMAND_MUTE = "M%d";
static const size_t AT_COMMAND_MUTE_SIZE = 1;
typedef enum AT_COMMAND_MUTE_OPTION {
	AT_COMMAND_MUTE_OPTION_OFF = 0,
	AT_COMMAND_MUTE_OPTION_ON_UNTIL_CARRIER_DETECTED = 1,
	AT_COMMAND_MUTE_OPTION_ON = 2
} AT_COMMAND_MUTE_OPTION;
static const size_t AT_COMMAND_MUTE_OPTIONS_SIZE = 1;

/* O - RETURN ONLINE
	returns the modem back to the normal connected state after being interrupted
*/
static const char * AT_COMMAND_ONLINE = "O";
static const size_t AT_COMMAND_ONLINE_SIZE = 1;

/* Q - QUIET MODE
	sets whether the device should return result codes for
*/
static const char * AT_COMMAND_QUIET_ENABLED = "Q1";
static const size_t AT_COMMAND_QUIET_ENABLED_SIZE = 2;
static const char * AT_COMMAND_QUIET_DISABLED = "Q";
static const size_t AT_COMMAND_QUIET_DISABLED_SIZE = 1;

/* S - REGISTER MANIPULATION
	selects, sets, and gets registers and their values

	S<n>     - selects register n
	S?       - gets the value of the selected register
	S<n>?    - selects register n and gets the value
	S=<r>    - sets the selected register to r
	S<n>=<r> - selects register n and sets that register's value to r
*/
static const size_t AT_COMMAND_REGISTER_OPTION_N_SIZE = 1; // size of first parameter "n"
static const char * AT_COMMAND_REGISTER_SELECT = "S%d";
static const size_t AT_COMMAND_REGISTER_SELECT_SIZE = 1;
static const char * AT_COMMAND_REGISTER_GET = "S%d?";
static const size_t AT_COMMAND_REGISTER_GET_SIZE = 2;
static const char * AT_COMMAND_REGISTER_GET_SELECTED = "S?";
static const size_t AT_COMMAND_REGISTER_GET_SELECTED_SIZE = 2;
static const char * AT_COMMAND_REGISTER_SET = "S%d=%s";
static const size_t AT_COMMAND_REGISTER_SET_SIZE = 2;
static const char * AT_COMMAND_REGISTER_SET_CHAR = "S%d=%c";
static const size_t AT_COMMAND_REGISTER_SET_CHAR_SIZE = 2;
static const char * AT_COMMAND_REGISTER_SET_SELECTED = "S=%s";
static const size_t AT_COMMAND_REGISTER_SET_SELECTED_SIZE = 2;

/* V - VERBOSE RESPONSE
	enables or disables verbose(english) response values

	V  - disables verbose results, switches to numeric results
	V1 - enables verbose results
*/
static const char * AT_COMMAND_VERBOSE_ENABLE = "V1";
static const size_t AT_COMMAND_VERBOSE_ENABLE_SIZE = 2;
static const char * AT_COMMAND_VERBOSE_DISABLE = "V";
static const size_t AT_COMMAND_VERBOSE_DISABLE_SIZE = 1;

#endif // __AT_COMMAND_H__
