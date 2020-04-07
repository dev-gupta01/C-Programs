#include<bits/stdc++.h>
using namespace std;
struct movie{
  int start,end;
};
int skip(int a,int b,int k){
  return (k*((a-b)/k))+b;
}
int main(){
  int n,k;
  cin>>n>>k;
  std::vector<movie> m(n);
  int currtime=1;
  int total=0;
  for(int i=0;i<n;i++){
    cin>>m[i].start>>m[i].end;
    int skipto=skip(m[i].start,currtime,k);

    total+=m[i].end-skipto+1;
    currtime=m[i].end+1;
    //cout<<skipto<<" "<<currtime<<" "<<total<<"\n";
  }
  cout<<total;
}
