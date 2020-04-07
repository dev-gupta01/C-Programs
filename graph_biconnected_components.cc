#include<bits/stdc++.h>
using namespace std;
list<int> *a;
bool *visit;
int v,e;
int *disc;
int *low;
int *parent;
stack<pair<int,int> > st;
void addedge(int x,int y){
	a[x].push_back(y);
	a[y].push_back(x);
}
void biconnected_component(int s){
	static int time=0;
	int children=0;
	visit[s]=true;
	disc[s]=low[s]=++time;
	list<int>::iterator it;
	for(it=a[s].begin();it!=a[s].end();it++){
		if(visit[*it]==false){
			children++;
			parent[*it]=s;
			st.push(make_pair(s,*it));
			biconnected_component(*it);
			low[s]=min(low[s],low[*it]);
			if(parent[s]==-1 && children>1){
				while(st.top()!=make_pair(s,*it)){
					cout<<st.top().first<<"--"<<st.top().second<<" ";
					st.pop();
				}
				cout<<st.top().first<<"--"<<st.top().second<<endl;
				st.pop();
			}
			if(parent[s]!=-1 && low[*it]>=disc[s]){
				while(st.top()!=make_pair(s,*it)){
					cout<<st.top().first<<"--"<<st.top().second<<" ";
					st.pop();
				}
				cout<<st.top().first<<"--"<<st.top().second<<endl;
				st.pop();
			}
		}
		else if(*it!=parent[s]){
			low[s]=min(low[s],disc[*it]);
			if(disc[*it]<disc[s])
				st.push(make_pair(s,*it));
		}
	}
}
int main(){
	cin>>v>>e;
	a=new list<int>[v];
	visit=new bool[v];
	disc=new int[v];
	low=new int[v];
	parent=new int[v];
	int x,y;
	for(int i=0;i<e;i++){
		cin>>x>>y;
		addedge(x,y);
	}
	memset(visit,false,sizeof(visit));
	for(int i=0;i<v;i++)
		parent[i]=-1;
	cout<<"Biconnected Components:\n";
	for(int i=0;i<v;i++){
		if(visit[i]==false){
			biconnected_component(i);
			while(!st.empty()){
				cout<<st.top().first<<"--"<<st.top().second<<" ";
				st.pop();
			}
			cout<<endl;
		}
	}
}