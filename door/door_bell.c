#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIN_SPRK 25

void close_bell()
{
	softToneCreate(PIN_SPRK);
	softToneWrite(PIN_SPRK,196);
	delay(250);
	softToneWrite(PIN_SPRK,164.81);
	delay(250);
	softToneWrite(PIN_SPRK,130.81);
	delay(500);
	softToneWrite(PIN_SPRK,0);


}
void open_bell()
{
	softToneCreate(PIN_SPRK);
	softToneWrite(PIN_SPRK,130.81);
	delay(250);
	softToneWrite(PIN_SPRK,164.81);
	delay(250);
	softToneWrite(PIN_SPRK,196);
	delay(500);
	softToneWrite(PIN_SPRK,0);
}


int main(int argc,char *argv[])
{
	if(wiringPiSetup() == -1)
	{
		printf("error\n");
		exit(0);
	}
	if(strcmp(argv[1], "-o") == 0)
		open_bell();
	else if(strcmp(argv[1], "-c") == 0)
		close_bell();

}
