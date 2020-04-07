/*Binary Search tree*/

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* getnewnode(int data){
    node* newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node *root,int data){
    if(root==NULL){
        root=getnewnode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
bool search(node* root,int data){
    if(root==NULL)
        return false;
    if(data==root->data)
        return true;
    else if(data<=root->data)
        return search(root->left,data);
    else
        return search(root->right,data);       
}
//recursive implementation
void findmax(node* root){
    if(root==NULL){
        cout<<"Empty Tree!!"<<endl;
        return;
    }
    if(root->right==NULL){
        cout<<"Max= "<<root->data<<endl;
        return;
    }
    findmax(root->right);
}
//iterative implementation
/*void findmin(node* root){
    if(root==NULL)
        cout<<"Empty Tree!!"<<endl;
    node* temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    cout<<"Min= "<<temp->data<<endl;
}*/
node* findmin(node* root){
    if(root==NULL)
        cout<<"Empty Tree!!"<<endl;
    node* temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
int findheight(node* root){
    if(root==NULL)
        return -1;
    else
        return max(findheight(root->left),findheight(root->right))+1;
}
void print_level_order_traversal(node* root){
    if(root==NULL){
        cout<<"Empty Tree!!"<<endl;
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    cout<<"\n";
}
void print_preorder(node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(node* root){
    if(root==NULL)
        return;
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
void print_postorder(node* root){
    if(root==NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}
node* deletenode(node* root,int data){
    if(root==NULL) return root;
    else if(data<root->data) root->left=deletenode(root->left,data);
    else if(data>root->data) root->right=deletenode(root->right,data);
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL){
            node* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else{
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
            return root;
        }
    }    
}
int main(){
    node *root=NULL;
    root=insert(root,12);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,13);
    root=insert(root,17);
    root=insert(root,1);
    root=insert(root,9);
    if(search(root,1))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    findmax(root);
    node* i1=findmin(root);
    cout<<"Min= "<<i1->data<<endl;
    int h=findheight(root);
    cout<<"Height= "<<h<<endl;
    cout<<"level_order_traversal:\n";
    print_level_order_traversal(root);
    cout<<"preorde traversal:\n";
    print_preorder(root);
    cout<<"\n";
    cout<<"inorder traversal:\n";
    print_inorder(root);
    cout<<"\n";
    cout<<"postorder traversal:\n";
    print_postorder(root);
    cout<<"\n";
    root=deletenode(root,15);
    cout<<"After delete:\n";
    cout<<"postorder traversal:\n";
    print_postorder(root);
    cout<<"\n";
}