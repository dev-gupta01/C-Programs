#include<iostream>
using namespace std;
int max(int a,int b){return(a>b)?a:b;}
int max(int a,int b,int c){return max(max(a,b),c);}
int findmaxsub_mid(int a[],int l,int m,int r){
  int sum=0,left_sum=0;
  for(int i=m;i>=l;i--){
    sum+=a[i];
    if(sum>left_sum)
      left_sum=sum;
  }
  sum=0;int right_sum=0;
  for(int i=m+1;i<=r;i++){
    sum+=a[i];
    if(sum>right_sum)
      right_sum=sum;
  }
  return (left_sum+right_sum);
}
int findmaxsub(int a[],int l,int r){
  if(l==r)
    return a[l];
  int m=(l+r)/2;
  return max(findmaxsub(a,l,m),findmaxsub(a,m+1,r),findmaxsub_mid(a,l,m,r));
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=findmaxsub(a,0,n-1);
  cout<<ans;
}
