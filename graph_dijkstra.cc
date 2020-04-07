#include<bits/stdc++.h>
using namespace std;
list<pair<int,int> > *a;
int v,e,w;
int *dist;
set<pair<int,int> > s;
void addedge(int x,int y,int w){
    a[x].push_back(make_pair(w,y));
}
void shortest_path(int start){
    dist=new int[v+1];
    for(int i=0;i<=v;i++)
        dist[i]=1e7;
    dist[0]=0;
    s.insert(make_pair(0,start));
    dist[start]=0;
    while(!s.empty()){
        pair<int,int> temp= *(s.begin());
        s.erase(s.begin());
        int u=temp.second;
        list<pair<int,int> >::iterator it;
        for(it=a[u].begin();it!=a[u].end();it++){
            int v=(*it).second;
            int wt=(*it).first;
            if(dist[v]>dist[u]+wt){
                if(dist[v]!=1e7)
                    s.erase(s.find(make_pair(dist[v],v)));
                dist[v]=dist[u]+wt;
                s.insert(make_pair(dist[v],v));
            }
        }
    }
    for(int i=1;i<=v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}
int main(){
    cin>>v>>e;
    a=new list<pair<int,int> >[v+1];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y>>w;
        addedge(x,y,w);
    }
    shortest_path(1);
}