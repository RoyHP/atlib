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

/* IPR - FIXED DATA RATE 
	request: +IPR=[<rate>]
*/
static const char * AT_GSM_COMMAND_DATA_RATE = "+IPR=%d";
static const size_t AT_GSM_COMMAND_DATA_RATE_SIZE = 5;
static const unsigned int AT_GSM_COMMAND_DATA_RATE_OPTION_AUTO = 0;

/* ICF - TE-TA CHARACTER FRAMING 
	request: +ICF=[<format>],[<parity>]
*/
static const char * AT_GSM_COMMAND_TE_TA_CHARACTER_FRAMING = "+ICF=%d,%d";
static const size_t AT_GSM_COMMAND_TE_TA_CHARACTER_FRAMING_SIZE = 6;

/* IFC - TE-TA LOCAL FLOW CONTROL
	request: +IFC=[<te_flow>],[<ta_flow>]
*/
static const char * AT_GSM_COMMAND_TE_TA_FLOW_CONTROL = "+IFC=%d,%d";
static const size_t AT_GSM_COMMAND_TE_TA_FLOW_CONTROL = 6;

/* ILRR - TE-TA DATA RATE SUBSCRIPTION 
	request: +ILRR=[<value>]
*/
static const char * AT_GSM_COMMAND_TE_TA_FLOW_CONTROL_SUBSCRIBE = "+ILRR=%d";
static const size_t AT_GSM_COMMAND_TE_TA_FLOW_CONTROL_SUBSCRIBE_SIZE = 6;

/* CGMI - REQUEST MANUFACTURER IDENTIFICATION 
	request:  +CGMI
	response: <manufacturer> or +CME ERROR: <err>
*/
static const char * AT_GSM_COMMAND_REQUEST_MANUFACTURER_ID = "+CGMI";
static const size_t AT_GSM_COMMAND_REQUEST_MANUFACTURER_ID_SIZE = 5;
static const char * AT_GSM_COMMAND_REQUEST_MANUFACTURER_ID_QUERY = "+CGMI=?";
static const size_t AT_GSM_COMMAND_REQUEST_MANUFACTURER_ID_QUERY_SIZE = 7;

/* 

*/



#endif // __AT_GSM_COMMAND_H__
