#include<bits/stdc++.h>
using namespace std;
void dfsutil(int u,vector<int> a[],vector<bool> &visited){
    visited[u]=true;
    cout<<u<<" ";
    for(int i=0;i<a[u].size();i++){
        if(visited[a[u][i]]==false){
            dfsutil(a[u][i],a,visited);
        }
    }
}
void dfs(int v,int vert,vector<int> a[]){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false)
            dfsutil(i,a,visited);
    }
}
int main(){
    int t,v,e;
    cin>>t>>v>>e;
    vector<int> a[e];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(2,v,a);
    cout<<"\n";
}