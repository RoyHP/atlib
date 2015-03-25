#ifndef __AT_GSM_DEVICE_H__
#define __AT_GSM_DEVICE_H__

#include "ATDevice.h"
#include "ATGSMCommand.h"

typedef struct ATGSMDevice {
	ATDevice * device;
} ATGSMDevice;

ATGSMDevice * ATGSMDevice_construct(const ATDevice * device);
void ATGSMDevice_free(ATGSMDevice * self);
int ATGSMDevice_test(ATGSMDevice * self);
int ATGSMDevice_setCommandLineTerminationCharacter(ATGSMDevice * self, char termChar);
int ATGSMDevice_setResponseFormattingCharacter(ATGSMDevice * self, char formattingChar);
int ATGSMDevice_setCommandLineEditingCharacter(ATGSMDevice * self, char editingChar);

#endif // __AT_GSM_DEVICE_H__
