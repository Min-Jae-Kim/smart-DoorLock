#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

#define MAX 300

#define PORT "-p 9090"
#define BIN "raspistill"
#define OPT1 "--nopreview"
#define RESOL "-w 640 -h 480 -q 6"
#define PATH "-o /home/pi/server/pic.jpg"
#define OPT2 "-tl 100 -t 9999999 -th 0:0:0"

#define M_BIN "LD_LIBRARY_PATH=/usr/local/lib mjpg_streamer"
#define INPUT "-i \"input_file.so -f /home/pi/server -n pic.jpg\""
#define OUTPUT_1 "output_http.so"
#define OUTPUT_2 "-w /usr/local/www"

#ifdef DEBUG
int main()
#else
int on_camera_server()
#endif
{
	char cmd[MAX] = {0,};
	sprintf(cmd,"%s %s %s %s %s & %s %s -o \"%s %s %s\"",
			BIN,OPT1,RESOL,PATH,OPT2,
			M_BIN,INPUT,OUTPUT_1,PORT,OUTPUT_2
		   );

	system(cmd);

	return 0;
}
