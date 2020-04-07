#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>>v1,v2;
vector<set<int>> frst,lst;
vector<bool> visited;

bool isnon(char ch){ 
	if(ch>='A' &&ch<='Z') 
		return true; 
	else 
		return false;
}

void dfs1(int root,intopr)
{
	vis[root]=true;
	for(int i=0;i<g1[root].size();i++){
        int v=g1[root][i];
        if(!vis[v]){
            first[v].insert(opr);
            dfs1(v,opr);
        }
    }
}

void dfs2(int root,intopr){
	vis[root]=true;
	for(int i=0;i<g2[root].size();i++){
        int v=g2[root][i];
        if(!vis[v]){
            last[v].insert(opr);
            dfs2(v,opr);
        }
    }
}

int fnd(vector<char>&arr,char ch){
	for(int i=0;i<arr.size();i++) 
	if(arr[i]==ch) 
	return i;
	return -1;
}

int main(){

	int c1,c2,i,j,k,idx;
	char ch;
	cin>>c1>>c2;
	g1.resize(c1+c2);
	g2.resize(c1+c2);
	vector<char>op(c1+c2);
	for(i=0;i<c1+c2;i++)  
		cin>>op[i];
		first.resize(c1),last.resize(c1);
		int rules_c;
		cin>>rules_c;
	vector<pair<char,string>>rules(rules_c);
	string rhs;
	for(int a=0;a<rules_c;a++){
	cin>>rules[a].first>>rules[a].second;
    char &ch=rules[a].first;
    string &rhs=rules[a].second;
    int idx=a;
    bool st=true;
    
for(i=0;i<rhs.length();i++){
	idx=fnd(op,rhs[i]);
       if(st){
          if(!isnon(rhs[i])){
              g1[idx].push_back(a);
          }
          else{
            g1[idx].push_back(a);
		if(i+1<rhs.length() &&rhs[i+1]!='|'){
			idx=fnd(op,rhs[i+1]);
                g1[idx].push_back(a);
            }
          }
	st=false;
       }
       else if(rhs[i]=='|') st=true;
     }
     reverse(rhs.begin(),rhs.end());
	st=true;
    for(i=0;i<rhs.length();i++){
	idx=fnd(op,rhs[i]);
       if(st)
       {
          if(!isnon(rhs[i])) g2[idx].push_back(a);
          else
          {
            g2[idx].push_back(a);
	if(i+1<rhs.length() &&rhs[i+1]!='|')
            {
	idx=fnd(op,rhs[i+1]);
                g2[idx].push_back(a);
            }
          }
	st=false;
       }
       else if(rhs[i]=='|') st=true;
     }
  }

  for(i=c1;i<c1+c2;i++)
  {
	vis.resize(c1+c2);
      dfs1(i,i);
	vis.clear();
	vis.resize(c1+c2);
      dfs2(i,i);
	vis.clear();
  }
  vector<vector<char>>tab(c2,vector<char>(c2,'.'));

  for(i=0;i<rules_c;i++){
      string &rhs=rules[i].second;
      char ch=rules[i].first;
      reverse(rhs.begin(),rhs.end());
      int len=rhs.length();
      for(j=0;j<len;j++)
      {
	if(j+1<len&& !isnon(rhs[j]) &&isnon(rhs[j+1]) &&rhs[j]!='|' &&rhs[j+1]!='|'){
             set<int>&s=first[fnd(op,rhs[j+1])];
             set<int>::iterator it=s.begin();
             int idx=fnd(op,rhs[j]);
             for(;it!=s.end();it++)
             {
                 k=*it;
                 tab[idx-c1][k-c1]='<';
             }
          }

	if(j+1<len&&isnon(rhs[j]) && !isnon(rhs[j+1]) &&rhs[j]!='|' &&rhs[j+1]!='|'){
              set<int>&s=last[fnd(op,rhs[j])];
             set<int>::iterator it=s.begin();
             int idx=fnd(op,rhs[j+1]);
             for(;it!=s.end();it++)
             {
                 k=*it;
                 tab[k-c1][idx-c1]='>';
             }
          }
          if(j+2<len&& !isnon(rhs[j]) &&isnon(rhs[j+1]) && !isnon(rhs[j+2]) &&rhs[j]!='|' &&rhs[j+1]!='|' &&rhs[j+2]!='|'){
              int idx1=fnd(op,rhs[j]);
              int idx2=fnd(op,rhs[j+2]);
              tab[idx1-c1][idx2-c1]='=';
          }
      }
  }
cout<<"  ";
  for(j=0;j<c2;j++)
  {
      tab[0][j]='<',tab[j][0]='>';
      if(op[c1+j]==')' || op[c1+j]=='$') tab[0][j]='.';
      if(op[c1+j]=='(') tab[j][0]='.';
  }
  for(i=c1;i<c1+c2;i++) 
	cout<<op[i]<<" ";
  cout<<endl;
  for(i=0;i<tab.size();i++){
	cout<<op[c1+i]<<" ";
      for(j=0;j<tab[i].size();j++) 
		cout<<tab[i][j]<<" ";
	cout<<endl;
  }
}