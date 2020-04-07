#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l[],int nl,int m[],int nm){
  int i=0,j=0,k=0;
  while(i<nl&&j<nm){
    if(l[i]<m[j])
      a[k++]=l[i++];
    else
      a[k++]=m[j++];
  }
  while(i<nl)
    a[k++]=l[i++];
  while(j<nm)
    a[k++]=m[j++];
}
void mergeSort(int a[],int n){
  int mid;
  if(n<2)
    return;
  mid=n/2;
  int l[mid],m[n-mid];
  for(int i=0;i<mid;i++)
    l[i]=a[i];
  for(int i = mid;i<n;i++)
    m[i-mid] = a[i];
  mergeSort(l,mid);
  mergeSort(m,n-mid);
  merge(a,l,mid,m,n-mid);
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"\n";
  mergeSort(a,n);
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<"\n";
}
