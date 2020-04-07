#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* getnode(int data){
    node* newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node* root,int data){
    if(root==NULL)
        root=getnode(data);
    else if(data<=root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
bool searchnum(node* root,int data){
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data<root->data)
        searchnum(root->left,data);
    else
        searchnum(root->right,data);
}
void printlevel(node* root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
    cout<<"\n";
}
int height(node* root){
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}
int findmax(node* root){
    if(root==NULL)
        return -1;
    node* temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->data;
}
int findmin(node* root){
    if(root==NULL)
        return -1;
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}
void printreverselevel(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        s.push(root);
        if(root->right!=NULL)q.push(root->right);
        if(root->left!=NULL)q.push(root->left);
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    cout<<"\n";
}
int count1=0;
void halfnodes(node* root){
    if(root==NULL)
        return;
    if((root->left==NULL && root->right!=NULL) || (root->right==NULL && root->left!=NULL)) count1++;
    halfnodes(root->left);
    halfnodes(root->right);
}
int main(){
    node* root=NULL;
    root=insert(root,12);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,13);
    root=insert(root,17);
    root=insert(root,1);
    root=insert(root,9);
    if(searchnum(root,90))
        cout<<"FOUND\n";
    else
        cout<<"NOT FOUND\n";
    cout<<"LEVEL ORDER\n";
    printlevel(root);
    cout<<"REVERSE LEVEL ORDER\n";
    printreverselevel(root);
    cout<<"Height= "<<height(root)<<endl;
    cout<<"Max= "<<findmax(root)<<endl;
    cout<<"Min= "<<findmin(root)<<endl;
    cout<<"NUMBER OF HALF NODES= ";
    halfnodes(root);
    cout<<count1<<endl;
}