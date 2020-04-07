#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *head;
struct node *getnewnode(int x)
{
  struct node *newnode=new node();
  newnode->data=x;
  newnode->next=NULL;
  newnode->prev=NULL;
  return newnode;
}
void insertathead(int x)
{
  struct node *newnode=getnewnode(x);
  if(head==NULL)
  {
    head=newnode;
    return;
  }
  head->prev=newnode;
  newnode->next=head;
  head=newnode;
}
void print()
{
  struct node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<"\n";
}
int main()
{
  insertathead(2);
  insertathead(4);
  insertathead(5);
  print();
}
