#include<bits/stdc++.h>
using namespace std;
int num_digits(int n){
  int count=0;
  while(n){
    int a=n%10;
    n/=10;
    if(a==4||a==7)
      count++;
  }
  return count;
}
int main(){
  int n,k;
  cin>>n>>k;
  std::vector<int> v(n);
  int count=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    int digits=num_digits(v[i]);
    if(digits<=k)
    count++;
  }
  cout<<count;
}
