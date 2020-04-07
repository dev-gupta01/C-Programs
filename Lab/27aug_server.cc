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
#include<string>
using namespace std;

int main(){

int ssock,csock;      
int a,b,c, id, eid;
int cl, el;
char passeid[13], meaning[20], ser[10], rep[3], real[20];
unsigned int len;

struct sockaddr_in server,client;   

if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1){     
	perror("socket: ");
	exit(-1);
}

server.sin_family=AF_INET;
server.sin_port=htons(10000);       

// initializing server socket parameters..
server.sin_addr.s_addr=INADDR_ANY;

//inet_addr("127.0.0.1");
bzero(&server.sin_zero,0); 

//appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.. 


len=sizeof(struct sockaddr_in);

if((bind(ssock,(struct sockaddr *)&server,len))==-1){ 
 // binding port & IP  
	perror("bind error: ");
	exit(-1);
}

if((listen(ssock,5))==-1){     
// listening for client
	perror("listen error: ");                     
	exit(-1);
}


if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1){  
// accepting connectn
	perror("accept error: ");                         
	exit(-1);
}
while(1)
{
	while(1)
	{
		recv(csock, &eid, sizeof(eid), 0); 
		cout << "eid Received" << endl;
		int f = 0;
		ifstream infile;
		infile.open("EmployDetails.txt");
		ofstream ofs;
		ofs.open("temp.txt", ofstream::out);
		string line;
		while(infile.is_open())
		{
			while(getline(infile, line))
			{
				sscanf(line.c_str(), "%d %d %d", &id, &a, &b);
				//cout<<a<<b<<id<<endl;
				if(id == eid){
					f = 1;
					send(csock, &f, sizeof(f), 0);
					send(csock, &a, sizeof(a), 0);
					send(csock, &b, sizeof(b), 0);
					recv(csock, &cl, sizeof(cl), 0);
					recv(csock, &el, sizeof(el), 0);
					ofs<<id<<" "<<a - cl<<" "<<b - el<<endl;
				}
				else
				{
					ofs<<id<<" "<<a<<" "<<b<<endl;
				}
			}
			if(f==0)
			{
				send(csock, &f, sizeof(f), 0);
			}
			
			infile.close();
			ofs.close();
			remove("EmployDetails.txt");
			rename("temp.txt", "EmployDetails.txt");
		}
	}
}


close(ssock);









}