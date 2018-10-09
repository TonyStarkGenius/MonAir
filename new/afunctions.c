#include "afunctions.h"

void Delay(uint32_t ms)
{
	ms=ms*8000;
	for(int i=0;i!=ms;i++);
}
