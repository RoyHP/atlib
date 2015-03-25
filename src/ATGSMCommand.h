#ifndef __AT_GSM_COMMAND_H__
#define __AT_GSM_COMMAND_H__

/* X - SET CONNECT RESUT FORMAT*/
static const char * AT_GSM_COMMAND_CONNECT_RESULT_FORMAT = "X%d";
static const size_t AT_GSM_COMMAND_CONNECT_RESULT_FORMAT_SIZE = 1;

/* &C - SET CIRCUIT 109 MODE */
static const char * AT_GSM_COMMAND_109_MODE = "&C%d";
static const size_t AT_GSM_COMMAND_109_MODE_SIZE = 2;

/* &T - SET TA 108 RESPONSE MODE */
static const char * AT_GSM_COMMAND_TA_108_MODE = "&D%d";
static const size_t AT_GSM_COMMAND_TA_108_MODE_SIZE = 2;

/* IPR - FIXED DATA RATE */
static const char * AT_GSM_COMMAND_DATA_RATE = "+IPR=%d";
static const size_t AT_GSM_COMMAND_DATA_RATE_SIZE = 5;
static const unsigned int AT_GSM_COMMAND_DATA_RATE_OPTION_AUTO = 0;

/* ICF - TE-TA CHARACTER FRAMING */
static const char * AT_GSM_COMMAND_TE_TA_CHARACTER_FRAMING = "+ICF=%d,%d";

#endif // __AT_GSM_COMMAND_H__
