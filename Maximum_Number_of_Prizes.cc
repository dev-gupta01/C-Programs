#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> v;
  /*int sum=0;
  int x=0;
  for(int i=0;i<n;i++){
    x++;
    sum+=x;
    if(sum<=n){
      v.push_back(x);
    }
    if(sum==n){
      cout<<v.size()<<"\n";
      for(int j=0;j<v.size();j++)
        cout<<v[j]<<" ";
      return 0;
    }
    if(i>0){
      if(v[i]<=v[i-1]){
        sum-=x+v[i-1];
        v.pop_back();
        int y=n-sum;
        v.push_back(y);
        cout<<v.size()<<"\n";
        for(int j=0;j<v.size();j++)
          cout<<v[j]<<" ";
        return 0;
      }
    }
  }*/
  for (int i = 1; i <= n; i++) {
        n -= i;
        if (n <= i) {
            v.push_back(n + i);
            break;
        } else if (n == 0) {
            v.push_back(i);
            break;
        } else {
            v.push_back(i);
        }
    }
    cout<<v.size()<<"\n";
    for(int j=0;j<v.size();j++)
      cout<<v[j]<<" ";
}
