#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n;
int A[100001];
int T[400001];
int S[400001];
int E[400001];
int lazy[400001];
void build(int node,int l,int r){
    S[node]=l; E[node]=r;
    if(l==r){
        T[node]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    T[node]=T[2*node]+T[2*node+1];
    return;
}
int calculate(int node){
    return T[node]+(lazy[node]*(E[node]-S[node]+1));
}
void lazyPropagation(int node){
    lazy[2*node]+=lazy[node];
    lazy[2*node+1]+=lazy[node];
    lazy[node]=0;
}
void update(int node,int l,int r,int x){
    if(S[node]>r || E[node]<l)
        return;
    if(l<=S[node]&&r>=E[node]){
        lazy[node]+=x;
        return;
    }
    lazyPropagation(node);
    update(2*node,l,r,x);
    update(2*node+1,l,r,x);
    T[node]=calculate(2*node)+calculate(2*node+1);
    return;
}
int query(int node,int l,int r){
    if(l>E[node] || r<S[node])
        return 0;
    if(l<=S[node]&&r>=E[node])
        return calculate(node);
    lazyPropagation(node);
    int left=query(2*node,l,r);
    int right=query(2*node+1,l,r);
    T[node]=calculate(2*node)+calculate(2*node+1);
    return (left+right);
}
int main(){
    IOS
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    T[0]=0;
    build(1,0,n-1);
    update(1,2,3,10);
    int ans=query(1,2,6);
    /*for(int i=0;i<4*n;i++)
        cout<<T[i]<<" ";
    cout<<endl;
    for(int i=0;i<4*n;i++)
        cout<<lazy[i]<<" ";
    cout<<endl;*/
    cout<<ans<<endl;
}