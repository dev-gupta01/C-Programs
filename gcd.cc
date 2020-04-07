#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b){
  return ((b==0)?a:gcd(b,a%b));
}
int main()
{
  long long int a,b;
  cin>>a>>b;
  int ans=gcd(a,b);
  cout<<"GCD: "<<ans<<"\n";
  a=(a/ans);
  cout<<"LCM: "<<a*b;
}
