#include<bits/stdc++.h>
using namespace std; 
list<int> *a;
int v,e;
int *dist;
queue<int> q;
void addedge(int x,int y){
    a[x].push_back(y);
    a[y].push_back(x);
}
void bfs(int start){
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        list<int>::iterator it;
        for(it=a[x].begin();it!=a[x].end();it++){
            if(dist[*it]==-1){
                q.push(*it);
                dist[*it]=dist[x]+1;
            }       
        }
    }
    for(int i=1;i<=v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}
int main(){
    cin>>v>>e;
    a=new list<int>[v+1];
    int x,y;
    dist=new int[v+1];
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    for(int i=0;i<=v;i++)
        dist[i]=-1;
    bfs(3);
}