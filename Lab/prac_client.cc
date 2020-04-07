#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <errno.h>

#include <string.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <bits/stdc++.h>

using namespace std;
int main() {
    int sock; // client socket discriptor
    int a, b, c, i;
    unsigned int len;
    char ch[3] = "no", password[13], word[20], greetings[10], ser[10], rep[3], real[20];
    char ch1[3];
    char meaning[20];

    struct sockaddr_in client;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // client socket is created..
        perror("socket: ");
        exit(-1);
    }

    client.sin_family = AF_INET;
    client.sin_port = htons(10000); // initializing  socket  parameters
    client.sin_addr.s_addr = INADDR_ANY;
    //inet_addr("127.0.0.1");
    bzero( & client.sin_zero, 0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..

    len = sizeof(struct sockaddr_in);
    if ((connect(sock, (struct sockaddr * ) & client, len)) == -1) { //conneting to client
        perror("connect: ");
        exit(-1);
    }
    while (1) {
        printf("enter word: ");
        scanf("%s",word);
        send(sock,word,sizeof(word),0);
        recv(sock,meaning,sizeof(meaning),0);
        cout<<meaning<<endl;
        if((i=strcmp(meaning,"no"))==0){
            printf("enter meaning: ");
            scanf("%s",real);
            send(sock,real,sizeof(real),0);

        }

        printf("\nTo exit...press 'no'\n");

        scanf("%s", ch1);

        if ((i = strcmp(ch, ch1)) == 0) {
            close(sock);
            exit(0);
        }
    }
}