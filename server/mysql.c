#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>


#define HOST "localhost"
#define ID "root"
#define PW "dlaqpelem132!"
#define DB "gnuboard"

#define PIC 0
#define MSG 1

#define DOUBLE 2
#define SINGLE 1

#define INSERT "insert into "
#define TABLE "g5_write_doorpic"
#define COL "(wr_option,wr_subject,wr_content,mb_id,wr_password,wr_name,wr_datetime,wr_last)"

#define B_TABLE "doorpic"

char * table[2] = {"g5_write_doorpic","g5_write_doorMsg"};
char * b_table[2] = {"doorpic","doorMsg"};
char * name[2] = {"bot",NULL};

int initDB(MYSQL * mysql, const char * host, const char *id,
			const char *pw, const char *db);

//int main()
void insert_quot(char *str, int * index,int type)
{
	char *dq = "&#34";
	char *q = "&#39";
	int i;
	for(i=0; q[i] != 0 ; i++)
	{	
		if(type == DOUBLE)
			str[ (*index)++] = dq[i];
		else if(type == SINGLE)
			str[ (*index)++] = q[i];
	}
}

int send_query(char * filename,int mode)
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	
	char sql[256] = {0,};
	char subject[256] = {0,};
	char content[4096] = {0,};
	int wr_id = 0;
	int n_wr_id = 0;
	int fields;
	int cnt;
	int i;
	int	index = 0;
	int count = 0;
	time_t _tt; 
	struct tm * t;

	mysql_init(&mysql);
	initDB(&mysql,HOST,ID,PW,DB);

	if(mode == PIC)
	{
		_tt = time(NULL);

		t = gmtime(&_tt);

		sprintf(subject,"%d-%d-%d ----- %d:%d:%d",t->tm_year+1900,t->tm_mon+1,t->tm_mday, t->tm_hour,t->tm_min,t->tm_sec);
	
		sprintf(content,"<p>visitor</p><img src = \"/pic/%s\">",filename); 
	}
	else if(mode == MSG)
	{
		name[1] = (char *)malloc(256);
		memset(name[1],0,256);
		for(i=0;filename[i] != 0 ; i++)
		{
			switch(count)
			{
				case 0:
					if(filename[i] == 0x27) //single quot
					{
						insert_quot(subject,&index,SINGLE);	
					}
					else if(filename[i] == 0x22) //double quot
					{
						insert_quot(subject,&index,DOUBLE);	
					
					}
					else
						subject[index++] = filename[i];

					break;
				case 1:
					if(filename[i] == 0x27) //single quot
					{
						insert_quot(name[1],&index,SINGLE);	
					}
					else if(filename[i] == 0x22) //double quot
					{
						insert_quot(name[1],&index,DOUBLE);	
					
					}
					else
						name[1][index++] = filename[i];
					break;
				case 2:
					if(filename[i] == 0x27) //single quot
					{
						insert_quot(content,&index,SINGLE);	
					}
					else if(filename[i] == 0x22) //double quot
					{
						insert_quot(content,&index,DOUBLE);	
					}
					else
						content[index++] = filename[i];
					break;
			}
			if(filename[i] == '|')
			{
				count++;

				index = 0;
			}
			
		}
		subject[strlen(subject)-1] = '\0';
		name[1][strlen(name[1])-1] = '\0';
	//	printf("table 2 :  %s\n",table[mode]);
	}

		sprintf(sql,"%s%s%s  values (2,'%s','%s','admin',password('dlaqpelem132!'),'%s',now(),now()) ",INSERT,table[mode],COL,subject,content,name[mode]);
	
	printf("query : %s\n",sql);
	if(!mysql_query(&mysql,sql))
	{
		printf("query success\n");
	}
	else
		printf("query fail\n");

	
//	while(1);
	sprintf(sql,"select MAX(wr_id) from %s",table[mode]);
	mysql_query(&mysql,sql);
	res = mysql_use_result(&mysql);
	row = mysql_fetch_row(res);

	wr_id = atoi(row[0]);
	n_wr_id = n_wr_id - wr_id;
	printf("wr_id : %d\n",wr_id);

	mysql_free_result(res);
	memset(sql,0x00,sizeof(sql));
	
//	sprintf(sql,"update g5_write_doorpic set wr_num = %d , wr_parent = %d where wr_id = %d",n_wr_id,wr_id,wr_id);
	
	sprintf(sql,"update %s set wr_num = %d , wr_parent = %d where wr_id = %d",table[mode],n_wr_id,wr_id,wr_id);
//	printf("query : %s\n",sql);
	
	if(!mysql_query(&mysql,sql))
	{
		printf("query success\n");
	}
	else
		printf("query fail\n");

//	mysql_query(&mysql,sql);
	
	 memset(sql,0x00,sizeof(sql));
	 
//	 sprintf(sql,"update g5_board set bo_count_write = bo_count_write + 1 where bo_table = '%s'",B_TABLE);


	 sprintf(sql,"update g5_board set bo_count_write = bo_count_write + 1 where bo_table = '%s'",b_table[mode]);

	printf("query : %s\n",sql);
		
	if(!mysql_query(&mysql,sql))
	{
		printf("query success\n");
	}
	else
		printf("query fail\n");

	
	mysql_close(&mysql);
	if(mode == MSG)
		free(name[1]);
	return 0;
}
int initDB(MYSQL * mysql, const char *host, const char *id,
			const char *pw, const char *db)
{
	printf("Connecting...\n");
	if(mysql_real_connect(mysql,host,id,pw,db,0,NULL,0))
	{
		printf("success Mysql Connection\n");
		return 0;
	}
	else
	{
		printf("fail..\n");
		return -1;
	}


}
