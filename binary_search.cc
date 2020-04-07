#include<bits/stdc++.h>
using namespace std;
int bsearch(vector<int> v,int num,int low,int high)
{
  int mid;
  mid=(high+low)/2;
  if(low>high)
  return -1;
  else if(v[mid]==num)
  return mid;
  else if(v[mid]>num)
  return bsearch(v,num,low,mid-1);
  else
  return bsearch(v,num,mid+1,high);
}
int main()
{
  int n;
  cin>>n;
  vector<int> num(n);
  for(int i=0;i<n;i++)
    cin>>num[i];
  int k;
  cin>>k;
  vector<int> search(k);
  for(int i=0;i<k;i++){
    cin>>search[i];
  }
  for(int i=0;i<k;i++){
    int ans=bsearch(num,search[i],0,num.size());
    cout<<ans<<" ";
  }
}
