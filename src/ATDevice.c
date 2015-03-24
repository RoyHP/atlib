#include "ATDevice.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ATCommand.h"

struct ATDevice * ATDevice_construct() {
	struct ATDevice * self = malloc(sizeof(struct ATDevice));
	return self;
}

void ATDevice_destroy(struct ATDevice * self) {
	if (self) {
		free(self);
	}
}

int ATDevice_write(struct ATDevice * self, const char * buffer, size_t start, size_t length) {
	// TODO: Write to correct stream
	// TODO: Ensure stream locking so that no more than one command may be sent
	// temporarily printing to console output stream
	printf("\n%s", buffer);
}

int ATDevice_answer(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_ANSWER, 0, AT_COMMAND_ANSWER_SIZE);
}

int ATDevice_repeat(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_REPEAT, 0, AT_COMMAND_REPEAT_SIZE);
}

int ATDevice_dial(struct ATDevice * self, const char * number, size_t numberLength, enum AT_COMMAND_DIAL_OPTION option) {
	unsigned int cursor = 0, size;

	if (!self || !number) {
		return 0;
	}

	size = AT_COMMAND_DIAL_SIZE + numberLength + AT_COMMAND_DIAL_OPTIONS_SIZE;
	char buffer[size];

	// write command to the buffer
	strncpy(buffer, AT_COMMAND_DIAL, AT_COMMAND_DIAL_SIZE);
	cursor += AT_COMMAND_DIAL_SIZE;

	// write phone number to the buffer
	strncpy(buffer + cursor, number, numberLength);
	cursor += numberLength;

	// write option to the buffer
	switch (option) {
		case AT_COMMAND_DIAL_OPTION_PULSE:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_PULSE_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_TOUCH_TONE:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_TOUCH_TONE_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_AWAIT_TONE:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_AWAIT_TONE_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_REVERT:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_REVERT_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_AWAIT_RINGBACK:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_AWAIT_RINGBACK_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_PAUSE:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_PAUSE_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_REMAIN_IN_COMMAND:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_REMAIN_IN_COMMAND_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_FLASH:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_FLASH_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		case AT_COMMAND_DIAL_OPTION_REDIAL:
			strncpy(buffer + cursor, AT_COMMAND_DIAL_OPTION_REDIAL_CHAR, AT_COMMAND_DIAL_OPTIONS_SIZE);
			break;
		default:
			return 0;
	}
	cursor += AT_COMMAND_DIAL_OPTIONS_SIZE;

	return ATDevice_write(self, buffer, 0, size);
}

int ATDevice_enableEcho(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_ECHO_ENABLE, 0, AT_COMMAND_ECHO_ENABLE_SIZE);
}

int ATDevice_disableEcho(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_ECHO_DISABLE, 0, AT_COMMAND_ECHO_DISABLE_SIZE);
}

int ATDevice_hangUp(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_HOOK_DISABLE, 0, AT_COMMAND_HOOK_DISABLE_SIZE);
}

int ATDevice_pickUp(struct ATDevice * self) {
	return ATDevice_write(self, AT_COMMAND_HOOK_ENABLE, 0, AT_COMMAND_HOOK_ENABLE_SIZE);
}

int ATDevice_inquire(struct ATDevice * self, unsigned int id) {
	size_t cursor = 0;
	size_t size = AT_COMMAND_INFO_SIZE + AT_COMMAND_INFO_OPTIONS_SIZE;
	char buffer[size];

	// write command to buffer
	strncpy(buffer + cursor, AT_COMMAND_INFO, AT_COMMAND_INFO_SIZE);
	cursor += AT_COMMAND_INFO_SIZE;

	// write option to buffer
	snprintf(buffer + cursor, AT_COMMAND_INFO_OPTIONS_SIZE + 1, "%d", id);
	cursor += AT_COMMAND_INFO_OPTIONS_SIZE;

	// write buffer to stream
	ATDevice_write(self, buffer, 0, size);
}

int ATDevice_setLoudness(struct ATDevice * self, AT_COMMAND_LOUDNESS_OPTION level) {
	size_t cursor = 0;
	size_t size = AT_COMMAND_LOUDNESS_SIZE + AT_COMMAND_LOUDNESS_OPTIONS_SIZE;
	char buffer[size];

	// ensure level is between 0 and 3
	if (0 < level || level > 3) {
		return 0;
	}

	// write command to buffer
	strncpy(buffer + cursor, AT_COMMAND_LOUDNESS, AT_COMMAND_LOUDNESS_SIZE);
	cursor += AT_COMMAND_LOUDNESS_SIZE;

	// write option to buffer
	snprintf(buffer + cursor, AT_COMMAND_LOUDNESS_OPTIONS_SIZE, "%d", level);

	// write buffer to stream
	ATDevice_write(self, buffer, 0, size);
}
