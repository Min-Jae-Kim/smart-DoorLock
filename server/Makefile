all: server

server: server.c mysql.c camera.c
	$(CC) -o $@ $^ $(LDFLAGS) $(OPT)

CC = gcc
OPT = -I/usr/include/mysql
LDFLAGS = -lmysqlclient -lpthread
