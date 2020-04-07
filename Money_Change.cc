#include<bits/stdc++.h>
using namespace std;
int change(int n,int count){
  if(n==0)
    return count;
  else if(n>=10){
    count++;
    return change(n-10,count);
  }
  else if(n>=5){
    count++;
    return change(n-5,count);
  }
  else if(n>0){
    count++;
    return change(n-1,count);
  }
}
int main(){
  int n;
  cin>>n;
  int count=0;
  int ans=change(n,count);
  cout<<ans;
}
