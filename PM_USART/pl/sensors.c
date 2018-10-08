#include "sensors.h"

char PM_2_5[3];
char PM_10[3];
char PM_2_5_C[6];
char PM_10_C[6];

void PM_Get(char* str,char* PM2_5,char* PM10)
{
	char* pos1;
		pos1=strstr(str,"2");//find 0x32 in str
		if(!strncmp(pos1+1,"=",1))//if 0x3D is after 0x32(start signal from sensor)
		{
			strncpy(PM2_5,pos1+7,1);
			strncpy(PM10,pos1+9,1);
		}
		PM2_5[2]='\0';
		PM10[2]='\0';
}

void Convert_PM(char* PM1, char* PM2)
{
	uint8_t INTPM=(int)PM1[0];
	//uint8_t INTPML=(int)PM1[1];
	//INTPM=(INTPM<<8)+INTPML;//keep data of PM value in INT
	int del = 1;
	int del1 = 10;
	int delt=1;
	int var=-1;
	while(INTPM/delt>=1)//to know how many ciphers we have in number
	{
		var++;
		delt*=10;
	}
	for (int i = var;(INTPM / del) >= 1;i--)
	{
		PM2[i] = ((INTPM / del) % del1) + 48;//convert INT cipher to the same CHAR
		del *= 10;
	}
	PM2[5]='\0';
}

void Transmit_PM_USART2(void)
{
	My_USART2_Send_StrRN("PM Concentration in mcg/m^3:");
	My_USART2_Send_Str("PM2.5: ");
	My_USART2_Send_StrRN(PM_2_5_C);
	My_USART2_Send_Str("PM10: ");
	My_USART2_Send_StrRN(PM_10_C);
}
