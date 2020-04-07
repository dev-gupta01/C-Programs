#include<bits/stdc++.h>
using namespace std;
struct segment{
  int start,end;
};
bool sortFunc(segment i,segment j){
  return (i.end<j.end);
}
vector<int> optimal_point(vector<segment> &s){
  sort(s.begin(),s.end(),sortFunc);
  vector<int> v;
  int point=s[0].end;
  v.push_back(point);
  for(int i=1;i<s.size();i++){
    if(point<s[i].start || point>s[i].end){
      point=s[i].end;
      v.push_back(point);
    }
  }
  return v;
}
int main(){
  int n;
  cin>>n;
  vector<segment> s(n);
  for(int i=0;i<n;i++)
    cin>>s[i].start>>s[i].end;
  vector<int> points = optimal_point(s);
  cout<<points.size()<<"\n";
  for(int i=0;i<points.size();i++)
    cout<<points[i]<<" ";
}
