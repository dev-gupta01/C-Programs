#include<bits/stdc++.h>
using namespace std;
list<int> *a;
bool *visit;
int v,e;
int *disc;
int *low;
int *parent;
vector<int> ap;
vector<pair<int,int> > bridge;
void addedge(int x,int y){
	a[x].push_back(y);
	a[y].push_back(x);
}
void articulate_point(int s){
	static int time=0;
	int children=0;
	visit[s]=true;
	disc[s]=low[s]=++time;
	list<int>::iterator it;
	for(it=a[s].begin();it!=a[s].end();it++){
		if(visit[*it]==false){
			children++;
			parent[*it]=s;
			articulate_point(*it);
			low[s]=min(low[s],low[*it]);
			if(parent[s]==0 && children>1)
				ap.push_back(s);
			if(parent[s]!=0 && low[*it]>=disc[s])
				ap.push_back(s);
			if(low[*it]>disc[s])
				bridge.push_back(make_pair(*it,s));
		}
		else if(*it!=parent[s])
			low[s]=min(low[s],disc[*it]);
	}
}
int main(){
	cin>>v>>e;
	a=new list<int>[v+1];
	visit=new bool[v+1];
	disc=new int[v+1];
	low=new int[v+1];
	parent=new int[v+1];
	int x,y;
	for(int i=0;i<e;i++){
		cin>>x>>y;
		addedge(x,y);
	}
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=v;i++)
		parent[i]=0;
	for(int i=1;i<=v;i++)
		if(visit[i]==false)
			articulate_point(i);
	cout<<"Articulate Points\n";
	sort(ap.begin(),ap.end());
	cout<<"Articulate Points\n";
	for(int i=0;i<ap.size();i++)
		cout<<ap[i]<<" ";
	cout<<endl;
	cout<<"Bridges\n";
	for(int i=0;i<bridge.size();i++)
		cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
}