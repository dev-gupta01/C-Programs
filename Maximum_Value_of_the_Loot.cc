#include<bits/stdc++.h>
using namespace std;
int max_unit_index(vector<double> unit){
  int n=0;
  double max=unit[0];
  for(int i=0;i<unit.size();i++){
    if(unit[i]>max){
        n=i;
        max=unit[i];
    }
  }
  return n;
}
int main(){
  double n,capacity;
  cin>>n>>capacity;
  vector<double> value(n);
  vector<double> weight(n);
  vector<double> unit(n);
  for(int i=0;i<n;i++){
    cin>>value[i]>>weight[i];
    double x=value[i]/weight[i];
    unit[i]=x;
  }
  double loot=0;
  for(int i=0;i<(int)n;i++){
    if(capacity==0){
      cout<<loot;
      return 0;
    }
    else{
      int index=max_unit_index(unit);
      double x=unit[index];
      double y=value[index];
      double z=weight[index];
      unit.erase(unit.begin()+index);
      int a = min(capacity, z);
      loot+=a*x;
      capacity-=a;
    }
  }
  cout<<loot<<"\n";
}
