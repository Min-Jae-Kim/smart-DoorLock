#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define PORT 12345 
#define M_PORT 9091
#define FALSE 0
#define TRUE 1

#define PIC 0
#define MSG 1

#define S_PATH "/var/www/pic/"


#define MAX 255

char filePath[MAX] = {0,};
char fileName[MAX] = {0,};
int idx = 0;

void MakeFilePath() 
{
	char path[100] = {0,};
	int i;
	while(1)
	{
		sprintf(fileName,"image%d.jpg",idx);
		sprintf(path,"%s%s%d%s",S_PATH,"image",idx++,".jpg");
		if(access(path,F_OK) != 0)
		{
			strcpy(filePath,path);
			break;
		}
	
	}

}
void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	 exit(1);

}
void *MessageServer(void *arg)
{

	//NOT IMPLEMENT
	int serv_sock,clnt_sock;
	struct sockaddr_in serv_addr,clnt_addr;
	socklen_t clnt_addr_sz;
	int i;
	char buf[4096];
	char subject[MAX] = {0,};
	char name[MAX] = {0,};
	char content[MAX] = {0,};

	if( (serv_sock = socket(PF_INET, SOCK_STREAM,0)) < 0)
		error_handling("socket() error\n");
	
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(M_PORT);

	if(bind(serv_sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		{
			printf("errno : %s\n",strerror(errno));
			error_handling("bind() error\n");
		}
	while(1)
	{
		
		if(listen(serv_sock, 5) == -1)
			error_handling("listen() error\n");

		printf("waiting for message client..\n");
		clnt_addr_sz = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);
		printf("connect from QT\n");
		read(clnt_sock,buf,sizeof(buf));

		printf("test : %s\n",buf);
		
		send_query(buf,MSG);

		close(clnt_sock);	

	}
	return NULL;
}

void *VisitPicServer (void *arg)
{
	int serv_sock,clnt_sock;
	int n,nsize;
	struct sockaddr_in serv_addr,clnt_addr;
	socklen_t clnt_addr_sz;
	int i,index;
	char file_buf[MAX];
	int file_size;
	int recv_size = 0;
	FILE * fp;


	if( (serv_sock = socket(PF_INET, SOCK_STREAM,0)) < 0)
		error_handling("socket() error\n");
	
	memset(&serv_addr,0,sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	if(bind(serv_sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
		printf("errno : %s\n",strerror(errno));
		error_handling("bind() error\n");
	}
	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error\n");

	clnt_addr_sz = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);

	while(1)
	{
		
		if(clnt_sock == -1)
			error_handling("accept() error\n");
	
		MakeFilePath();
		fp = fopen(filePath,"wb");
	
		printf("ing..\n");	
		read(clnt_sock,file_buf,MAX);
		file_size = atoi(file_buf);
		printf("file_size : %d\n",file_size);

		while( (nsize = read(clnt_sock,file_buf,MAX)) != 0)
		{
				
				fwrite((void *)file_buf,1,nsize,fp);
					
				recv_size = recv_size + nsize;
				printf("nsize = %d MAX = %d\n",nsize,MAX);

				

				if(recv_size == file_size)
				{
					recv_size = 0;
					break;
				}
/*				
if(nsize < MAX)
				{
						printf("//////////////////////////////\n");
						break;
				}*/
		}
					
		printf("received the picture \n");
		send_query(fileName, PIC);
		fclose(fp);
	}

	close(clnt_sock);
	return NULL;
}
int main(void)
{
	pthread_t threads[2];

	pthread_create(&threads[0],NULL,&VisitPicServer,NULL);
	pthread_create(&threads[1],NULL,&MessageServer,NULL);

	on_camera_server();
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);

	return 0;
}
