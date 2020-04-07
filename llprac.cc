#include<bits/stdc++.h>
using namespace std;
struct node{
  int roll;
  string name;
  int marks;
  struct node *next;
};
struct node *head;
void insert(int roll,string name,int marks,int n){
  node *temp1=new node();
  temp1->roll=roll;
  temp1->name=name;
  temp1->marks=marks;
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
void insertsorted(int data){ //data inserted at particular
  node *temp1=new node();    //position in sorted linked
  temp1->data=data;          //list
  temp1->next=NULL;
  node *temp=head,*pretemp;
  while(temp!=NULL && temp->data<=data){
    pretemp=temp;
    temp=temp->next;
  }
  temp1->next=pretemp->next;
  pretemp->next=temp1;
}
void print(){
  node *temp=head;
  int count=0;
  while(temp!=NULL){
    cout<<"ROLL: "<<temp->roll<<"\nNAME: "<<temp->name<<"\nMARKS: "<<temp->marks<<"\n\n";
    temp=temp->next;
    count++;
  }
  cout<<"No. of Students= "<<count<<"\n\n";
}
void find(string name){
  node *temp=head;
  while(temp!=NULL){
    if(name==temp->name){
      cout<<name<<" FOUND at roll "<<temp->roll<<"\n";
      return;
    }
    else{
      temp=temp->next;
    }
  }
  cout<<name<<" NOT FOUND\n";
}
int main(){
  head=NULL;
  insert(1,"rahul",78,1);
  insert(2,"vinod",89,2);
  insert(3,"dev",100,3);
  insert(4,"xyz",85,4);
  cout<<"DETAILS:\n\n";
  print();
  find("vinod");
}
