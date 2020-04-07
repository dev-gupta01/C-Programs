#include<bits/stdc++.h>
using namespace std;
bool **tc;
list<int> *a;
void addEdge(int v,int w){
    a[v].push_back(w); 
}
void dfsutil(int s,int v){
    tc[s][v]=true;
    list<int>::iterator it;
    for(it=a[v].begin();it!=a[v].end();it++){
        if(tc[s][*it]==false)
            dfsutil(s,*it);
    }
}
void transitiveClosure(int v){
    for(int i=0;i<v;i++){
        dfsutil(i,i);
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<tc[i][j]<<" ";
        cout<<"\n";
    }
}
int main(){
    int v,b,c;
    cin>>v;
    a=new list<int>[v];
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(2, 3); 
    addEdge(3, 3); 
  
    tc=new bool* [v]; 
    for(int i=0;i<v;i++){ 
        tc[i]=new bool[v]; 
        memset(tc[i],false,v*sizeof(bool)); 
    }
    transitiveClosure(v);
}