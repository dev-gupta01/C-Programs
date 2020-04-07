#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* left;
  node* right;
};

node* getnewnode(int data){
  node* newNode=new node();
  newNode->data=data;
  newNode->left=newNode->right=NULL;
  return newNode;
}

node* insert(node* root,int data){
  if(root==NULL)
    root=getnewnode(data);
  else if(data<=root->data)
    root->left=insert(root->left,data);
  else
    root->right=insert(root->right,data);
  return root;
}

void findmin(node* root){
  if(root==NULL){
    cout<<"\nempty tree\n";
    return;
  }
  node* temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  cout<<"\nmin is: "<<temp->data;
}

void findmax(node* root){
  if(root==NULL){
    cout<<"\nempty tree\n";
    return;
  }
  node* temp=root;
  while(temp->right!=NULL){
    temp=temp->right;
  }
  cout<<"\nmax is: "<<temp->data<<"\n";
}

bool search(node* root,int data){
  if(root==NULL) return false;
  else if(root->data==data) return true;
  else if(data<=root->data) return search(root->left,data);
  else return search(root->right,data);
}

int height(node* root){
  if(root==NULL)
    return -1;
  return (max(height(root->left),height(root->right))+1);  
}

int main(){
  node* root=NULL;
    root=insert(root,1);
    root=insert(root,12);
    root=insert(root,32);
    root=insert(root,54);
    root=insert(root,5);
    root=insert(root,26);
    root=insert(root,70);
    root=insert(root,18);
    root=insert(root,9);
    if(search(root,120)==true) cout<<"found";
    else cout<<"not found";
    findmin(root);
    findmax(root);
    int h=height(root);
    cout<<"height is: "<<h<<"\n";
}
