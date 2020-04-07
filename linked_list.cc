#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
};
struct node *head;
void insert(int data,int n)
{
  node *temp1=new node();
  temp1->data=data;
  temp1->next=NULL;
  if(n==1)
  {
    temp1->next=head;
    head=temp1;
    return;
  }
  else
  {
    node *temp2=head;
    for(int i=0;i<n-2;i++)
    {
      temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
  }
}
void print()
{
  node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<"\n";
}
void Delete(int n)
{
  node *temp=head;
  if(n==1)
  {
    head=temp->next;
    free(temp);
    return;
  }
  else
  {
    for(int i=0;i<n-2;i++)
    {
      temp=temp->next;

    }
    node *temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
  }
}
int main()
{
  head=NULL;
  insert(2,1);
  insert(3,2);
  insert(4,3);
  insert(5,4);
  insert(6,5);
  insert(7,6);
  cout<<"before delete\n";
  print();
  cout<<"after delete\n";
  Delete(3);
  print();
}
