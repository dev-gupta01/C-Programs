#include<bits/stdc++.h>
using namespace std;
list<int> *a;
bool *visit;
int v,e;
int *color;
queue<int> q;
int flag;
void addedge(int x,int y){
    a[x].push_back(y);
    a[y].push_back(x);
}
void bfs(int start){
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        visit[x]=true;
        list<int>::iterator it;
        for(it=a[x].begin();it!=a[x].end();it++){
            if(visit[*it]==false){
                color[*it]=1-color[x];
                q.push(*it);
            }
            else{
                list<int>::iterator it1;
                for(it1=a[*it].begin();it1!=a[*it].end();it1++){
                    if(color[*it]==color[*it1]){
                        flag=1;
                        return;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>v>>e;
    a=new list<int>[v+1];
    visit=new bool[v+1];
    color=new int[v+1];
    for(int i=1;i<=v;i++){
        color[v]=-1;
    }
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    for(int i=1;i<=v;i++){
        if(visit[i]==false)
            bfs(i);
    }
    for(int i=1;i<=v;i++){
        cout<<color[v]<<" ";
    }
    cout<<endl;
    if(flag==0)
        cout<<"Bipartite\n";
    else
        cout<<"Not Bipartite\n";
}