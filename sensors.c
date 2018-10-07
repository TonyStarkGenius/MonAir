#include "sensors.h"

void PM_Get(char* str,char*PM2_5,char*PM10)
{
	const char* pos1;
		pos1=strstr(str,"2");
		if(!strncmp(pos1+1,"=",1))
		{
			strncpy(PM2_5,pos1+8,1);
			strncpy(PM10,pos1+10,1);
			
		}
		PM2_5[2]='\0';
		PM10[2]='\0';
}

void Convert_PM(char* PM)
{
	uint16_t INTPM=(int)PM[0];
	uint8_t INTPML=(int)PM[1];
	INTPM=(INTPM<<8)+INTPML;
	int del = 1;
	int del1 = 10;
	for (int i = 1;(INTPM / del) >= 1;i--)
	{
		PM25[i] = ((INTPM / del) % del1) + 48;
		del *= 10;
	}
}
