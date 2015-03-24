#ifndef __AT_DEVICE_H__
#define __AT_DEVICE_H__

#include <stddef.h>

#include "ATCommand.h"

typedef struct ATDevice {

} ATDevice;

ATDevice * ATDevice_construct();
void ATDevice_destroy(ATDevice * self);
int ATDevice_write(ATDevice * self, const char * buffer, size_t start, size_t length);
int ATDevice_answer(ATDevice * self);
int ATDevice_repeat(ATDevice * self);
int ATDevice_dial(ATDevice * self, const char * number, size_t numberLength, AT_COMMAND_DIAL_OPTION option);
int ATDevice_enableEcho(ATDevice * self);
int ATDevice_disableEcho(ATDevice * self);
int ATDevice_hangUp(ATDevice * self);
int ATDevice_pickUp(ATDevice * self);
int ATDevice_inquire(ATDevice * self, unsigned int id);
int ATDevice_setLoudness(ATDevice * self, AT_COMMAND_LOUDNESS_OPTION level);

#endif // __AT_DEVICE_H__
