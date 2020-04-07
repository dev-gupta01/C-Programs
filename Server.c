#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
struct client_data {
	int socketno;
	char ip[INET_ADDRSTRLEN];
};
int clients[100];
int n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void sendtoall(char *message,int current)
{
	int i;
	pthread_mutex_lock(&mutex);
	for(i = 0; i < n; i++) {
		if(clients[i] != current) {
			if(send(clients[i],message,strlen(message),0) < 0) {
				perror("sending failure");
				continue;
			}
		}
	}
	pthread_mutex_unlock(&mutex);
}
void *recvmg(void *sock)
{
	struct client_data cl = *((struct client_data *)sock);
	char message[500];
	int length;
	int i;
	int j;
	while((length = recv(cl.socketno,message,500,0)) > 0) {
		message[length] = '\0';
		sendtoall(message,cl.socketno);
		memset(message,'\0',sizeof(message));
	}
	pthread_mutex_lock(&mutex);
	printf("%s disconnected\n",cl.ip);
	for(i = 0; i < n; i++) {
		if(clients[i] == cl.socketno) {
			j = i;
			while(j < n-1) {
				clients[j] = clients[j+1];
				j++;
			}
		}
	}
	n--;
	pthread_mutex_unlock(&mutex);
}
int main(int argc,char *argv[])
{
	struct sockaddr_in my_addr,their_addr;
	int my_socket;
	int their_sock;
	socklen_t their_addr_size;
	int portno;
	pthread_t sendt,recvt;
	char message[500];
	int length;
	struct client_data cl;
	char ip[INET_ADDRSTRLEN];;
	;
	if(argc > 2) {
		printf("too many arguments");
		exit(1);
	}
	portno = atoi(argv[1]);
	my_socket = socket(AF_INET,SOCK_STREAM,0);
	memset(my_addr.sin_zero,'\0',sizeof(my_addr.sin_zero));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(portno);
	my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	their_addr_size = sizeof(their_addr);

	if(bind(my_socket,(struct sockaddr *)&my_addr,sizeof(my_addr)) != 0) {
		perror("binding error");
		exit(1);
	}

	if(listen(my_socket,5) != 0) {
		perror("listening error");
		exit(1);
	}

	while(1) {
		if((their_sock = accept(my_socket,(struct sockaddr *)&their_addr,&their_addr_size)) < 0) {
			perror("accept unsuccessful");
			exit(1);
		}
		pthread_mutex_lock(&mutex);
		inet_ntop(AF_INET, (struct sockaddr *)&their_addr, ip, INET_ADDRSTRLEN);
		printf("%s connected\n",ip);
		cl.socketno = their_sock;
		strcpy(cl.ip,ip);
		clients[n] = their_sock;
		n++;
		pthread_create(&recvt,NULL,recvmg,&cl);
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}
