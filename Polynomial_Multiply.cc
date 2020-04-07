#include<bits/stdc++.h>
using namespace std;
int multiply(int a[],int b[],int n,int al,int bl){
  int c[2*n-1];
  if(n==1){
    c[0]=al*bl;
  }
  for(int i=0;i<n-1;i++)
    c[i]=multiply(a,b,n/2,al,bl);
  for(int i=n;i<2*n-1;i++)
    c[i]=multiply(a,b,n/2,al+n/2,bl+n/2);
  for(int i=n/2;i<n+1;i++){
    int d0e1=multiply(a,b,n/2,al,bl+n/2);
    int d1e0=multiply(a,b,n/2,al+n/2,bl);
    c[i+(n/2)-2]=d0e1+d1e0;
  }
  for(int i=0;i<2*n-1;i++){
    cout<<c[i]<<" ";
  }
  cout<<"\n";
}
int main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cin>>b[i];
  multiply(a,b,n,a[n-1],b[n-1]);

}
