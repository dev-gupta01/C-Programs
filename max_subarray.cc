#include<iostream>
using namespace std;
void findmaxsub(int a[],int n){
  int end=0,ans=0;
  for(int i=0;i<n;i++){
    end+=a[i];
    if(end<0)
      end=0;
    if(end>ans)
      ans=end;
  }
  cout<<ans<<"\n";
}
int main(){
  int n;
  cout<<"Enter number of elements:";
  cin>>n;
  int a[n];
  cout<<"Enter array elments:";
  for(int i=0;i<n;i++)
    cin>>a[i];
  findmaxsub(a,n);
}
