#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long int> v;
  int x;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    v.push_back(x);
  }
  sort(v.rbegin(),v.rend());
  long long int a=v[0]*v[1];
  cout<<a;
}
