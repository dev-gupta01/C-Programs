#include<bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
};
bool sortFunction1(point i,point j){
  if(i.y==j.y)
    return (i.x<j.x);
  return (i.y<j.y);
}
bool sortFunction2(point i,point j){
  if(i.x==j.x)
    return (i.y<j.y);
  return (i.x<j.x);
}
int main(){
  int n;
  cin>>n;
  std::vector<point> p(n);
  for(int i=0;i<n;i++)
    cin>>p[i].x>>p[i].y;
  sort(p.begin(),p.end(),sortFunction1);
  int count=0;
  for(int i=1;i<n-1;i++){
    if((p[i].y==p[i-1].y) && (p[i].y==p[i+1].y) &&(p[i].x>p[i-1].x) && (p[i].x<p[i+1].x)){
      int a=p[i].x; int b=p[i].y;
      sort(p.begin(),p.end(),sortFunction2);
      for(int j=1;j<n-1;j++){
        if((b==p[j].y)&&(a==p[j].x)) {
          if((p[j].x==p[j-1].x) && (p[j].x==p[j+1].x) &&(p[j].y>p[j-1].y) && (p[j].y<p[j+1].y)){
            count++;
          }
        }
      }
    }
    sort(p.begin(),p.end(),sortFunction1);
  }
  cout<<count;
}
