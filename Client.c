#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
void *recvmg(void *socket)
{
	int their_socket = *((int *)socket);
	char message[500];
	int length;
	while((length = recv(their_socket,message,500,0)) > 0) {
		message[length] = '\0';
		fputs(message,stdout);
		memset(message,'\0',sizeof(message));
	}
}
int main(int argc, char *argv[])
{
	struct sockaddr_in their_addr;
	int my_socket;
	int their_socket;
	int their_addr_size;
	int portno;
	pthread_t sendt,recvt;
	char message[500];
	char username[100];
	char res[600];
	char ip[INET_ADDRSTRLEN];
	int length;

	if(argc > 3) {
		printf("too many arguments");
		exit(1);
	}
	portno = atoi(argv[2]);
	strcpy(username,argv[1]);
	my_socket = socket(AF_INET,SOCK_STREAM,0);
	memset(their_addr.sin_zero,'\0',sizeof(their_addr.sin_zero));
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(portno);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(my_socket,(struct sockaddr *)&their_addr,sizeof(their_addr)) < 0) {
		perror("connection not established");
		exit(1);
	}
	inet_ntop(AF_INET, (struct sockaddr *)&their_addr, ip, INET_ADDRSTRLEN);
	printf("connected to %s, start chatting\n",ip);
	pthread_create(&recvt,NULL,recvmg,&my_socket);
	while(fgets(message,500,stdin) > 0) {
		strcpy(res,username);
		strcat(res,":");
		strcat(res,message);
		length = write(my_socket,res,strlen(res));
		if(length < 0) {
			perror("message not sent");
			exit(1);
		}
		memset(message,'\0',sizeof(message));
		memset(res,'\0',sizeof(res));
	}
	pthread_join(recvt,NULL);
	close(my_socket);

}
