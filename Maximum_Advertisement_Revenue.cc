#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<long long int> v1;
  vector<long long int> v2;
  int n;
  cin>>n;
  long long int x;
  for(int i=0;i<2*n;i++){
    if(i>=n){
      cin>>x;
      v2.push_back(x);
    }
    else{
      cin>>x;
      v1.push_back(x);
    }
  }
  sort(v1.rbegin(),v1.rend());
  sort(v2.rbegin(),v2.rend());
  long long int sum=0;
  for(int i=0;i<n;i++)
  sum+=v1[i]*v2[i];
  cout<<sum<<"\n";
}
