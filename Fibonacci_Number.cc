#include<bits/stdc++.h>
using namespace std;
long long int fibo(int n){
  int f[n+1];
  f[0]=0;
  f[1]=1;
  for(int i=2;i<n+1;i++)
  f[i]=(f[i-1]%10+f[i-2]%10)%10;
  return f[n];
}

int main()
{
  int n;
  cin>>n;
  long long int ans=fibo(n);
  cout<<ans;
}
