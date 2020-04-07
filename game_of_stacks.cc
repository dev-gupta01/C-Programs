#include<bits/stdc++.h>
using namespace std;

void findans(vector<int> a,vector<int> b,int n,int m,int x){
  int i=0,j=0,sum=0;
  int count=0;
  while(i<n&&sum+a[i]<=x){
    sum+=a[i];
    i++;
  }
  count=i;
  while(j<m&&i>=0){
    sum+=b[j];
    j++;
    while(sum>x&&i>0){
      i--;
      sum-=a[i];
    }
    if(sum<=x && i+j>count)
      count=i+j;
  }
  cout<<count<<"\n";
}
int main(){
  int g;
  cin>>g;
  for(int i=0;i<g;i++){
    int n,m,x;
    cin>>n>>m>>x;
    int y;
    vector<int> a(n);
    for(int j=0;j<n;j++){
      cin>>a[j];
    }
    vector<int> b(m);
    for(int j=0;j<m;j++){
      cin>>b[j];
    }
    findans(a,b,n,m,x);
  }
}
