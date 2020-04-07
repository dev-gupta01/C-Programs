#include<bits/stdc++.h>
using namespace std;
struct node{
  char data;
  node* next;
};
node* head=NULL;
void push(int data){
  if(head==NULL){
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    head=temp;
  }
  else{
    node* temp=new node();
    temp->data=data;
    temp->next=head;
    head=temp;
  }
}
void pop(){
  node* temp=head;
  head=temp->next;
  free(temp);
}
void print(){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<"\n";
}
int main(){
  /*push(2);push(5);push(10);push(1);push(8);
  print();
  pop();print();*/
  string s;
  cout<<"Enter a string: ";cin>>s;
  for(int i=0;i<s.length();i++){
    push(s[i]);
  }
  print();
}
