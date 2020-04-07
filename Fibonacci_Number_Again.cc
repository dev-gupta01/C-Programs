#include<bits/stdc++.h>
using namespace std;
int get_pisano_period_length(long long m) {
  long long F1 = 0, F2 = 1, F = F1 + F2;
  for (int i = 0; i < m * m; i++) {
      F = (F1 + F2) % m;
      F1 = F2;
      F2 = F;
      if (F1 == 0 && F2 == 1) return i + 1;
  }
}
long long int fibo(int n,int b){
  int f[n+1];
  f[0]=0;
  f[1]=1;
  for(int i=2;i<n+1;i++)
  f[i]=(f[i-1]%b+f[i-2]%b)%b;
  return f[n];
}
int modul(long long int a,long long int b){
  int period=get_pisano_period_length(b);
  int x=a%period;
  int num=fibo(x,b);
  return (num);
}
int main(){
  long long int a,b;
  cin>>a>>b;
  int ans=modul(a,b);
  cout<<ans;
}
