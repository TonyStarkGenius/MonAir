#include "MonAir.h"

void Send_MonAir_Data(void)
{
	char str[85];
	strcpy(str,"https://api.thingspeak.com/update?api_key=2NH271GFFL0J508H&field1=");
	strcat(str,PM_2_5_C);
	strcat(str,"&field2=");
	strcat(str,PM_10_C);
	Send_to_TCP("api.thingspeak.com","80",str);
}