#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "vibration.h"


#define ADDR "192.168.25.10"
#define PORT 12345
#define BUF_SIZE 255

char cmd[MAX] = {0, };
//char filePath[100] = {0,};
char filePath[100] = "/home/pi/image.jpg"; 
char  * host = NULL;
int idx = 0;
int clnt_sock;
struct sockaddr_in serv;	


void socket_init();

void check_pic()
{
	if(access(filePath,F_OK) == 0)
	{	
		remove(filePath);
	}

}
void bell()
{
	softToneCreate(PIN_SPKR);

	softToneWrite(PIN_SPKR,440);
	delay(500);
	softToneWrite(PIN_SPKR,349);
	delay(500);
	softToneWrite(PIN_SPKR,0);
}
void vibration() //2015-11-21 19:51 start
{
	int value = 1;
	int n = 0;
	int flag = FALSE;
	int jpg_fd;
	struct stat statBuf;
	FILE * fp;
	char s[BUF_SIZE];
	pinMode(PIN_VIB, INPUT);
//	MakeFileName();
	check_pic();
	socket_init();
	while(1)
	{
		value = digitalRead(PIN_VIB);

		if(value == 0)
		{
			printf("Taking a picture...");
			sprintf(cmd,"%s%s",PIC_CMD,filePath); 
			system(cmd);	
			//take picture
			
			
			while(flag != TRUE)
			{
				if(access(filePath,F_OK) == 0)
					break;
			}
			
			
			lstat(filePath,&statBuf);
			sprintf(s,"%d",statBuf.st_size);
			write(clnt_sock,s,strlen(s)+1);

			fp = fopen(filePath,"rb"); 
			bell();

			while(1)
			{
				n=fread((void*)s, 1, BUF_SIZE, fp);
				if(n<= 0)
				{
					write(clnt_sock, s, n);
					break;
				}
					write(clnt_sock, s, n);
			}
			
			
			
//			printf("last : %d\n",write(clnt_sock, s, n));
			fclose(fp);
			/////////

			printf("  done!\n");
			check_pic();
		//	MakeFileName();
		}
	
	}
}
void MakeFileName()
{
	char path[100] = {0,};
	int i;
	while(1)	
	{
		sprintf(path,"%s%s%d%s",PIC_PATH,"image",idx++,".jpg");
		if(access(path,F_OK) != 0)
		{	
			strcpy(filePath,path);
			break;	
		}
	}
}

void socket_init(){
	
	if((clnt_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0){
		perror("can't create socket!\n");
		exit(-1);
	}
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr(host);
	serv.sin_port = htons(PORT);

	if(connect(clnt_sock, (struct sockaddr *)&serv, sizeof(serv)) < 0){
		perror("connected error");
		exit(-2);
	}
}

#ifdef CHECK
int main(int argc, char * argv[])
{
	if(wiringPiSetup() == -1)
	{
		printf("error\n");
		exit(0);
	}
	if(argc != 2)
	{
		printf("usage : sudo ./vib [HOST IP]\n");
	}

	host = argv[1];
	vibration();
	return 0;
}
#endif
