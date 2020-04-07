#include<bits/stdc++.h>
using namespace std; 
list<int> *a;
list<int> *aTranspose;
bool *visit;
int v,e;
stack<int> s;
void addedge(int x,int y){
    a[x].push_back(y);
    aTranspose[y].push_back(x);
}
void dfs_aUtil(int start){
    visit[start]=true;
    list<int>::iterator it;
    for(it=a[start].begin();it!=a[start].end();it++)
        if(visit[*it]==false)
            dfs_aUtil(*it);
    s.push(start);
}
void dfs_aTransposeUtil(int start){
    visit[start]=true;
    cout<<start<<" ";
    list<int>::iterator it;
    for(it=aTranspose[start].begin();it!=aTranspose[start].end();it++)
        if(visit[*it]==false)
            dfs_aTransposeUtil(*it);
}
void dfs_a(){
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    for(int i=1;i<=v;i++){
        if(visit[i]==false)
            dfs_aUtil(i);
    }
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    int count=0;
    while(!s.empty()){
        if(visit[s.top()]==false){
            count++;
            cout<<"SCC "<<count<<endl;
            dfs_aTransposeUtil(s.top());
            cout<<"\n";
        }
        s.pop();
    }
    cout<<"No. of SCC= "<<count<<endl;
}
int main(){
    cin>>v>>e;
    a=new list<int>[v+1];
    aTranspose=new list<int>[v+1];
    visit=new bool[v+1];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    dfs_a();
}