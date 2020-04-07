#include<bits/stdc++.h>
using namespace std;
int v,e,p,q;
list<int> *a;
bool *visit;
int *dist;
void addedge(int x,int y){
    a[x].push_back(y);
    //a[y].push_back(x);
}
struct Edge{
    int x,y;
};
void dfs(int s,int *count){
    visit[s]=true;
    list<int>::iterator it;
    for(it=a[s].begin();it!=a[s].end();it++){
        if(visit[*it]==false){
            (*count)=(*count)+1;
            //cout<<"count in dfs= "<<*count<<endl;
            dfs(*it,count);
        }
    }
}
int main(){
    cin>>v>>e;
    a=new list<int>[v+1];
    dist=new int[v+1];
    dist[0]=0;
    visit=new bool[v+1];
    int x,y;
    Edge *edge=new Edge[v+1];
    edge[0].x=0;
    edge[0].y=0;
    for(int i=0;i<v-1;i++){
        cin>>x>>y;
        addedge(x,y);
        edge[i+1].x=x;
        edge[i+1].y=y;
    }
    int c;
    int count=1;
    for(int i=1;i<=v;i++){
        memset(visit,false,sizeof(visit));
        count=1;
        dfs(i,&count);
        dist[i]=count;
    }
    /*for(int i=1;i<=v;i++)
        cout<<dist[i]<<" ";
    cout<<endl;*/
    //vector<int> ans;
    while(e-->0){
        int count1;
        cin>>c;
        p=edge[c].x;
        q=edge[c].y;
        cout<<dist[p]<<" "<<dist[q]<<endl;
        count1=min(dist[p],dist[q]); 
        //cout<<"count= "<<count<<" (v-count)= "<<(v-count)<<endl;
        cout<<count1*(v-count1)<<endl;
    }

}