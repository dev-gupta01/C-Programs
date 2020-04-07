#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
};
struct node1{
  int data1;
  node1 *next1;
};
struct node1 *head1;
struct node *head;
void insert(int data,int n){
  node *temp1=new node();
  temp1->data=data;
  temp1->next=NULL;
  if(n==1){
    temp1->next=head;
    head=temp1;
    return;
  }
  else{
    node *temp2=head;
    for(int i=0;i<n-2;i++){
      temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
  }
}
void insert1(int data1,int n){
  node1 *temp1=new node1();
  temp1->data1=data1;
  temp1->next1=NULL;
  if(n==1){
    temp1->next1=head1;
    head1=temp1;
    return;
  }
  else{
    node1 *temp2=head1;
    for(int i=0;i<n-2;i++){
      temp2=temp2->next1;
    }
    temp1->next1=temp2->next1;
    temp2->next1=temp1;
  }
}
void print(){
  cout<<"first\n";
  node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<"\n";
}
void printmerged(){
  cout<<"merged\n";
  node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<"\n";
}
void insertsorted(int data){
  node *temp1=new node();
  temp1->data=data;
  temp1->next=NULL;
  node *temp=head,*pretemp;
  while(temp!=NULL && temp->data<=data){
    pretemp=temp;
    temp=temp->next;
  }
  temp1->next=pretemp->next;
  pretemp->next=temp1;
}
void merge(){
  node1 *temp=head1;
  while(temp!=NULL){
    insertsorted(temp->data1);
    temp=temp->next1;
  }
}
void print1(){
  cout<<"second\n";
  node1 *temp=head1;
  while(temp!=NULL){
    cout<<temp->data1<<" ";
    temp=temp->next1;
  }
  cout<<"\n";
}
int main(){
  head=NULL;
  head1=NULL;
  for(int i=1;i<10;i++){
    insert(2*i,i);
  }
  print();
  insert1(2,1);
  insert1(4,2);
  insert1(6,3);
  insert1(7,4);
  insert1(10,5);
  insert1(118,6);
  print1();
  merge();
  printmerged();
}
