#include "ATGSMDevice.h"

#include "ATDevice.h"

ATGSMDevice * ATGSMDevice_construct(const ATDevice * device) {
	ATGSMDevice * gsm = malloc(sizeof ATGSMDevice);
	gsm->device = device;
}

void ATGSMDevice_free(ATGSMDevice * self) {
	free(self);
}

int ATGSMDevice_test(ATGSMDevice * self) {

}

int ATGSMDevice_setCommandLineTerminationCharacter(ATGSMDevice * device, char termChar) {

}

int ATGSMDevice_setResponseFormattingCharacter(ATGSMDevice * device, char formattingChar) {
	unsigned int registerID = 4;
	size_t size = 1;
}

int ATGSMDevice_setCommandLineEditingCharacter(ATGSMDevice * self, char editingChar) {
	unsigned int registerID = 5;
	size_t size = 1;
	char * buffer[size];
	buffer[0] = editingChar; 

	ATDevice_setRegister(self->device, registerID, buffer, size);
}