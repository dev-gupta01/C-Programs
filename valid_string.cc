#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[26]={0};
  string s;
  cin>>s;
  int sum;
  for(int i=0;i<s.length();i++){
    a[s[i]-97]++;
  }
  
}
