#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
  node *prev;
};
struct node *head;
struct node *getNewNode(int x){
  node *newNode=new node();
  newNode->data=x;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}
void insertAtHead(int x){
  node *newNode=getNewNode(x);
  
}
