#ifndef __AT_GSM_H__
#define __AT_GSM_H__

#include "ATDevice.h"
#include "ATGSMCommand.h"

typedef struct ATGSMDevice {
	ATDevice * device;
} ATGSMDevice;

ATGSMDevice * ATGSMDevice_construct(const ATDevice * device);
void ATGSMDevice_free(ATDevice * device);
int ATGSMDevice_setCommandLineTerminationCharacter(ATDevice * device, char termChar);
int ATGSMDevice_setResponseFormattingCharacter(ATDevice * device, char formattingChar);
int ATGSMDevice_setCommandLineEditingCharacter(ATDevice * device, char editingChar);
int 

#endif // __AT_GSM_H__
