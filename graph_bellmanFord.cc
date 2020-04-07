#include<bits/stdc++.h>
using namespace std;
int v,e,w;
list<pair<int,int> > *a;
bool *visit;
int *dist;
struct Edge{
    int src;
    int dest;
    int weight;
};
void addedge(int x,int y,int w){
    a[x].push_back(make_pair(y,w));
}
void bellman_ford(int start,Edge *edge){
    dist=new int[v+1];
    for(int i=0;i<=v;i++)   
        dist[i]=1e7;
    dist[0]=0;
    dist[start]=0;
    for(int i=1;i<v;i++){
        for(int j=0;j<e;j++){
            int p=edge[j].src;
            int q=edge[j].dest;
            int wt=edge[j].weight;
            if(dist[p]!=1e7&&(dist[q]>(dist[p]+wt)))
                dist[q]=dist[p]+wt;
        }
    }
    for(int j=0;j<e;j++){
        int p=edge[j].src;
        int q=edge[j].dest;
        int wt=edge[j].weight;
        if(dist[p]!=1e7&&dist[p]+wt<dist[q]){
            cout<<"Negative Cycle Present\n";
            return;
        }
    }
}
int main(){
    cin>>v>>e;
    a=new list<pair<int,int> >[v+1];
    visit=new bool[v+1];
    memset(visit,false,sizeof(visit));
    Edge *edge=new Edge[v+1];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y>>w;
        addedge(x,y,w);
        edge[i].src=x;
        edge[i].dest=y;
        edge[i].weight=w;
    }
    bellman_ford(1,edge);
    for(int i=1;i<=v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}