#include<bits/stdc++.h>
using namespace std;
vector<int> *a;
int v,e;
bool *visit;
int flag;
void addedge(int x,int y){
    a[x].push_back(y);
    a[y].push_back(x);
}
void dfs1(int c,int d){
    visit[c]=true;
    vector<int>::iterator it;
    for(it=a[c].begin();it!=a[c].end();it++){
        if((*it)==d){
            flag=1;
        }
        if(visit[*it]==false)
            dfs1(*it,d);
    }
    
}
void dfs2Util(int start){
    visit[start]=true;
    vector<int>::iterator it;
    for(it=a[start].begin();it!=a[start].end();it++)
        if(visit[*it]==false)
            dfs2Util(*it);
}
void dfs2(){
    int count=0;
    for(int i=1;i<=v;i++){
        if(visit[i]==false){
            dfs2Util(i);
            count++;
        }
    }
    cout<<"No. of connected components= "<<count<<endl;
}
int main(){
    cin>>v>>e;
    visit=new bool[v+1];
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    a=new vector<int>[v+1];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    int c,d;
    cin>>c>>d;
    dfs1(c,d);
    if(flag==1)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    dfs2();
    memset(visit,false,sizeof(visit));
    visit[0]=true;
}