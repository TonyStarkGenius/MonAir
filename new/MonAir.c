#include "MonAir.h"

void Send_MonAir_Data_Thingspeak(void)
{
	char str[85];
	strcpy(str,"GET /update?api_key=2NH271GFFL0J508H&field1=");
	strcat(str,PM_2_5_C);
	strcat(str,"&field2=");
	strcat(str,PM_10_C);
	strcat(str," HTTP/1.1\r\nHost: api.thingspeak.com\r\n");
	Send_to_TCP("api.thingspeak.com","80",str);
	clear_RXBuffer(PM_2_5_C,0,6);
	clear_RXBuffer(PM_10_C,0,6);
}
