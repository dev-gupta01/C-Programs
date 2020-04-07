#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int ssock,csock;
// creating server and client socket discriptor
int a,b,c;
unsigned int len;
struct sockaddr_in server,client;
// creating server & client socket object
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1)
// creating socket
{
perror("socket: ");
exit(-1);
}
server.sin_family=AF_INET;
server.sin_port=htons(10000);
// initializing server socket parameters.
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,0);
// appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.
len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1)
// binding port & IP
{
perror("bind error: ");
exit(-1);
}
if((listen(ssock,5))==-1)
// listening for client
{
perror("listen error: ");
exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1)
// accepting connection
{
perror("accept error: ");
exit(-1);
}
while(1)
{
	int s5;
	recv(csock,&s5,sizeof(s5),0);
	if(s5!=12345)		
		break;
	char z[50];
	recv(csock,&z,sizeof(z),0);
	cout<<z<<endl;
	char str[]="Hello Client\n";
	send(csock,&str,sizeof(str),0);
	char s1[50];
	int n;
	recv(csock,&s1,sizeof(s1),0);
	recv(csock,&n,sizeof(n),0);
	map<char,int> m;
	for(int i=0;i<strlen(s1);i++){
		m[s1[i]]++;
	}
	char c1='1',c2;
	int maxi=0;
	for(map<char,int>::iterator it=m.begin();it!=m.end();++it){
		if((*it).second==n){
			c1=(*it).first;
			break;
		}
		else if(maxi<(*it).second){
			maxi=(*it).second;
			c2=(*it).first;
		}
	}
	if(c1!='1'){
		send(csock,&c1,sizeof(c1),0);
		cout<<"sent char: "<<c1<<endl;
	}
	else{
		send(csock,&c2,sizeof(c2),0);
		cout<<"sent char: "<<c2<<endl;
	}
}
close(ssock);
}
