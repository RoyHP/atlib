#include "src/ATDevice.h"
#include "src/ATCommand.h"
#include "src/ATGSMDevice.h"
#include "test/ATTest.h"

int main(int argc, char ** argv) {
	//ATTest_TestDevice();
	ATDevice * device = ATDevice_construct();
	ATGSMDevice * gsm = ATGSMDevice_construct(device);
	ATGSMDevice_test(gsm);
}
