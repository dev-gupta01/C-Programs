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
 // creating server and clinet socket discriptor
int a,b,c;
char password[13], word[20], meaning[20], ser[10], rep[3], real[20];
unsigned int len;
//string word2, meaning2, req;

struct sockaddr_in server,client;   
// creating server & client socket object

if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1){     
// creating socket
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
while(1){
	char cid[20];
	recv(csock, &cid, sizeof(cid), 0);
	cout<<"CID="<<cid<<endl; 
	int f = 0;
	ifstream infile;
	infile.open("20aug_leave.txt");
	string line;
	char id[20],cl[20],el[20];
	//string a, b;
	//char el_left[20],cl_left[20];
	int i;
	while(infile.is_open()){
		while(getline(infile, line)){
			sscanf(line.c_str(), "%s %s %s",id,cl,el);
			cout<<id<<" "<<cl<<" "<<el<<endl;
			if(i=strcmp(id,cid)==0){
				cout<<"done"<<endl;
				f = 1;
				char msg[]="CL left: ";
				//send(csock,&msg,sizeof(msg),0);
				//send(csock,&cl,sizeof(cl),0);
				char msg1[]="EL left: ";
				//send(csock,&msg1,sizeof(msg),0);
				//send(csock,&el,sizeof(el),0);
				//recv(csock,&msg,sizeof(msg),0);
				char leave[20];
				recv(csock,&leave,sizeof(leave),0);
				ifstream fin;
				ofstream fout;
				char id[20],cl[20],el[20];
				char EL[]="EL";
				char CL[]="CL";
				infile.close();
				fin.open("20aug_leave.txt");
				fout.open("20aug_leave.txt",ios::app|ios::out);
				int i;
				while(fin.is_open()){
					sscanf(line.c_str(), "%s %s %s",id,cl,el);
					if(i=strcmp(id,cid)==0){
						if(i=strcmp(msg,EL)==0){
							//el-=leave;
							fout<<id<<'\t'<<cl<<'\t'<<el;
						}
						else{
							//cl-=leave;
							fout<<id<<'\t'<<cl<<'\t'<<el;
						}
						break;
					}
				}
				fin.close();
				fout.close();
				break;
			}	
		}
		infile.close();
	}
}


close(ssock);









}
