#include "ATTest.h"

#include <string.h>
#include <stdio.h>

#include "../src/ATCommand.h"
#include "../src/ATDevice.h"

int ATTest_TestDevice() {
	printf("--- testing construct...");
	struct ATDevice * device = ATDevice_construct();
	printf("\n--- done...");

	printf("\n--- testing write...");
	const char * writeTestBuffer = "write test";
	ATDevice_write(device, writeTestBuffer, 0, strlen(writeTestBuffer));
	printf("\n--- done");

	printf("\n--- testing answer...");
	ATDevice_answer(device);
	printf("\n--- done");

	printf("\n--- testing repeat...");
	ATDevice_repeat(device);
	printf("\n--- done");

	printf("\n--- testing dial...");
	const char * dialTestPhoneNumber = "1234567890";
	const size_t phoneNumberLength = strlen(dialTestPhoneNumber);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_PULSE);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_TOUCH_TONE);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_AWAIT_TONE);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_REVERT);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_AWAIT_RINGBACK);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_PAUSE);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_REMAIN_IN_COMMAND);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_FLASH);
	ATDevice_dial(device, dialTestPhoneNumber, phoneNumberLength, AT_COMMAND_DIAL_OPTION_REDIAL);
	printf("\n--- done");

	printf("\n--- testing enable echo...");
	ATDevice_enableEcho(device);
	printf("\n--- done");

	printf("\n--- testing disable echo...");
	ATDevice_disableEcho(device);
	printf("\n--- done");

	printf("\n--- testing hang up...");
	ATDevice_hangUp(device);
	printf("\n--- done");

	printf("\n--- testing pick up...");
	ATDevice_pickUp(device);
	printf("\n--- done");

	printf("\n--- testing inquire...");
	int id;
	for (id = 0; id <= 9; id++) {
		ATDevice_inquire(device, id);
	}
	printf("\n--- done");

	printf("\n--- testing set loudness...");
	ATDevice_setLoudness(device, AT_COMMAND_LOUDNESS_OPTION_OFF);
	ATDevice_setLoudness(device, AT_COMMAND_LOUDNESS_OPTION_LOW);
	ATDevice_setLoudness(device, AT_COMMAND_LOUDNESS_OPTION_MEDIUM);
	ATDevice_setLoudness(device, AT_COMMAND_LOUDNESS_OPTION_HIGH);
	printf("\n--- done");

	printf("\n--- testing mute setting");
	ATDevice_setMute(device, AT_COMMAND_MUTE_OPTION_OFF);
	ATDevice_setMute(device, AT_COMMAND_MUTE_OPTION_ON_UNTIL_CARRIER_DETECTED);
	ATDevice_setMute(device, AT_COMMAND_MUTE_OPTION_ON);
	printf("\n--- done");

	printf("\n--- testing going online");
	ATDevice_goOnline(device);
	printf("\n--- done");

	printf("\n--- testing supress result codes");
	ATDevice_supressResultCodes(device);
	printf("\n--- done");

	printf("\n--- testing enable result codes");
	ATDevice_enableResultCodes(device);
	printf("\n--- done");

	printf("\n--- testing select register");
	ATDevice_selectRegister(device, 0);
	ATDevice_selectRegister(device, 1);
	printf("\n--- done");

	printf("\n--- testing set register");
	char * value = "foo";
	char * value2 = "bar";
	ATDevice_setRegister(device, 0, value, strlen(value));
	ATDevice_setRegister(device, 1, value2, strlen(value2));
	printf("\n--- done");

	printf("\n--- testing set selected register");
	ATDevice_setSelectedRegister(device, value, strlen(value));
	ATDevice_setSelectedRegister(device, value2, strlen(value2));
	printf("\n--- done");

	printf("\n--- testing get register");
	char * output;
	size_t outputSize;
	ATDevice_getRegister(device, 0, &output, &outputSize);
	printf("\n--- done");

	printf("\n--- testing get selected register");
	ATDevice_getSelectedRegister(device, &output, &outputSize);
	printf("\n--- done");

	printf("\n--- testing enable/disable verbose");
	ATDevice_enableVerbose(device);
	ATDevice_disableVerbose(device);
	printf("\n--- done");

	printf("\n--- testing destroy...");
	ATDevice_destroy(device);
	printf("\n--- done\n");
	return 1;
}
