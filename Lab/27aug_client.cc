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
int main()
{
  int sock; // client socket discriptor
  int a, b, c, i, eid, f;
  int cl, el;
  int tcl = 10, tel = 30;
  unsigned int len;
  char leaveType[10];
  char ch[3] = "no", password[13], word[20], greetings[10], ser[10], rep[3], real[20];
  char ch1[3];
  char meaning[20];

  struct sockaddr_in client;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  { // client socket is created..
    perror("socket: ");
    exit(-1);
  }

  client.sin_family = AF_INET;
  client.sin_port = htons(10000); // initializing  socket  parameters
  client.sin_addr.s_addr = INADDR_ANY;
  //inet_addr("127.0.0.1");
  bzero(&client.sin_zero, 0); //appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'..

  len = sizeof(struct sockaddr_in);
  if ((connect(sock, (struct sockaddr *)&client, len)) == -1)
  { //conneting to client
    perror("connect: ");
    exit(-1);
  }
  while (1)
  {
    cout << "Enter Employ ID : ";
    scanf("%d", &eid);
    send(sock, &eid, sizeof(eid), 0);
    recv(sock, &f, sizeof(f), 0);
    if (f)
    {
      recv(sock, &a, sizeof(a), 0);
      recv(sock, &b, sizeof(b), 0);
      cout << "Employ ID: " << eid << endl
           << "No. of CL left: " << a << ", No. of EL left: " << b << endl;
      cout << "Enter no. of days for leaves for cl and el:" << endl;
      cin >> cl >> el;
      if (cl > a || el > b)
      {
        cl = 0;
        el = 0;
        cout << "Leave not Approved" << endl;
        send(sock, &cl, sizeof(cl), 0);
        send(sock, &el, sizeof(el), 0);
      }
      else
      {
        send(sock, &cl, sizeof(cl), 0);
        send(sock, &el, sizeof(el), 0);
        cout << "Leave Approved" << endl;
        cout << "Employ ID: " << eid << endl
             << "No. of CL left: " << a - cl << ", No. of EL left: " << b - el << endl;
      }
    }
    else
    {
      cout << "No employ found" << endl;
    }

    printf("\nTo exit...press 'no'\n");

    scanf("%s", ch1);

    if ((i = strcmp(ch, ch1)) == 0)
    {
      close(sock);
      exit(0);
    }
  }
}