#include<bits/stdc++.h>
using namespace std;
void dfsutil(int v,bool* visited,vector<int> a[]){
    visited[v] = true; 
    cout<<v<<" ";
    vector<int>::iterator i; 
    for (i=a[v].begin();i!=a[v].end();i++) 
        if (!visited[*i])
            dfsutil(*i,visited,a);
}
void dfs(int v,int vert,vector<int> a[]){
    bool* vertex=new bool[vert];
    for(int i=0;i<vert;i++)
        vertex[i]=false;
    dfsutil(v,vertex,a);
}
int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<int> a[v];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(2,v,a);
}