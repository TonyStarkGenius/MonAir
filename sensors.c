#include "sensors.h"

void PM_Get(const char* str, char* PM2_5, char* PM10)
{
	char* pos1;
	if(strstr(str,"2"))
	{
		pos1=strstr(str,"2");
		if(pos+1=='=')
		{
			strncpy(PM2_5,pos1+6,2);
			strncpy(PM10,pos1+8,2);
		}
		PM2_5[2]='\0';
		PM10[2]='\0';
	}
}
