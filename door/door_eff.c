#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>

#define PIN_SPRK 25

void open_bell()
{
	softToneCreate(PIN_SPRK);
	softToneWrite(PIN_SPRK,369.99);
	delay(100);
	softToneWrite(PIN_SPRK,0);
}


int main()
{
	if(wiringPiSetup() == -1)
	{
		printf("error\n");
		exit(0);
	}

	open_bell();

}
