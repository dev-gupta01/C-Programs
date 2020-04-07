#include<bits/stdc++.h>
using namespace std;
struct point{
    double x;
    double y;
};

double cross_area(point a,point b){
    return (a.x*b.y-a.y*b.x);
}

double findarea(point a[],int n){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=cross_area(a[i],a[(i+1)%n]);
    }
    return abs(sum)/2.0;
}

int main(){
    int n;
    cin>>n;
    point a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    double area=findarea(a,n);
    cout<<area<<" ";
}