#include<bits/stdc++.h>
using namespace std;
int *status;
list<int> *a;
void addEdge(int v,int w){
    a[v].push_back(w);
}
void printbfs(int s){
    queue<int> q;
    q.push(s);
    status[s]=2;
    while(!q.empty()){
        cout<<q.front()<<" ";
        status[q.front()]=3;
        list<int>::iterator it;
        for(it=a[q.front()].begin();it!=a[q.front()].end();it++){
            if(status[*it]==1){
                q.push(*it);
                status[*it]=2;
            }
        }
        q.pop();
    }
}
/*void printdfs(int v){
    cout<<"hi";
    stack<int> s;
    s.push(v);
    status[v]=2;
    while(!s.empty()){
        cout<<s.top()<<" "; 
        status[s.top()]=3;
        list<int>::iterator it;
        for(it=a[s.top()].begin();it!=a[s.top()].end();it++){
            if(status[*it]==1){
                s.push(*it);
                status[*it]=2;
            }
        }
        s.pop();
    }
    cout<<"\n";
}*/
int findpath(int n,int start,int end){
    vector<bool> visited(n,false);
    vector<int> dist(n,0);
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        list<int>::iterator it;
        for(it=a[x].begin();it!=a[x].end();it++){
            if(visited[*it]==true)
                continue;
            dist[*it]=dist[x]+1;
            q.push(*it);
            visited[*it]=true;
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<"\n";*/
    return dist[end];
}
void update_status(int s){
    status[s]=3;
    list<int>::iterator it;
    for(it=a[s].begin();it!=a[s].end();it++)
        if(status[*it]==1)
            update_status(*it);
}
int connected_component(int v,int s){
    int count=0;
    for(int i=0;i<v;i++){
        if(status[i]==1){
            update_status(i);
            count++;
        }
    }
    return count;
}
bool check_cycle(int v){
    bool visited[v]={false};
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it=a[x].begin();it!=a[x].end();it++){
            if(visited[*it]==true&&find(a[*it].begin(),a[*it].end(),*it)!=a[*it].end()){
                return true;
            }
            else if(visited[*it]==true)
                continue;
            q.push(*it);
            visited[*it]=true;
        }
    }
}
bool check_bipartite(int v){
    bool visited[v]={false};
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int x=q.front();
        
    }
}
int main(){
    int v;
    cin>>v;
    status=new int[v];
    for(int i=0;i<v;i++)
        status[i]=1;
    int e;
    cin>>e;
    a=new list<int>[v];
    addEdge(0,1); 
    addEdge(0,2); 
    //addEdge(1,2); 
    addEdge(2,0); 
    addEdge(2,3); 
    //addEdge(3,3);
    addEdge(3,4);
    addEdge(3,5);
    addEdge(4,6);
    addEdge(4,7);
    cout<<"bfs with start 0:\n";
    printbfs(0);
    for(int i=0;i<v;i++)
        status[i]=1;
    /*for(int i=0;i<v;i++)
        cout<<status[i]<<" ";*/
    cout<<"\n";
    //cout<<"dfs with start 0:\n";
    /*for(int i=0;i<v;i++)
        cout<<status[i]<<" ";*/
    //printdfs(0);
    cout<<"Path length: "<<findpath(e,0,7)<<endl;
    for(int i=0;i<v;i++)
        status[i]=1;
    cout<<"Number of connected components: "<<connected_component(v,0)<<endl;
    cout<<"Cycle present?: "<<check_cycle(v)<<endl;
    cout<<"IsBipartite?: "<<check_bipartite(v)<<endl;

}