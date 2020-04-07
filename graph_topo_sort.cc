#include<bits/stdc++.h>
using namespace std;
int v,e;
bool *visit;
list<int> *a;
stack<int> s;
int flag;
void addedge(int x,int y){
    a[x].push_back(y);
}
void dfsUtil(int start){
    visit[start]=true;
    list<int>::iterator it;
    for(it=a[start].begin();it!=a[start].end();it++){
        if(visit[*it]==true)
            flag=1;
        if(visit[*it]==false)
            dfsUtil(*it);
    }
    s.push(start);
}
void dfs(){
    flag=0;
    for(int i=1;i<=v;i++){
        if(visit[i]==false)
            dfsUtil(i);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}
int main(){
    cin>>v>>e;
    visit=new bool[v+1];
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    a=new list<int>[v+1];
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    dfs();
    if(flag==1)
        cout<<"cycle present\n";
    else
        cout<<"no cycle\n";
}