#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct segment{
    int x,y;
};
int main(){
    int t;
    cin>>t;
    while(t--){
        pair<int,int> g1,g2;
        g2.second=-1; g2.first=1e7;
        int n; cin>>n;
        segment s[n];
        int a[n];
        for(int i=0;i<n;i++)
            cin>>s[i].x>>s[i].y;
        g1.first=s[0].x;
        g1.second=s[0].y;
        a[0]=1;
        int count=1;
        for(int i=1;i<n;i++){
            if((s[i].x>=g1.first&&s[i].x<=g1.second) || (g1.first>=s[i].x&&g1.first<=s[i].y) || (g1.first<=s[i].x&&g1.second>=s[i].y)){
                g1.first=min(g1.first,s[i].x);
                g1.second=max(g1.second,s[i].y);
                count++;
                a[i]=1;
            }
            else{
                g2.first=min(g2.first,s[i].x);
                g2.second=max(g2.second,s[i].y);
                count++;
                a[i]=2;
            }
        }
        if(count!=n || (g2.first>=g1.first&&g2.first<=g1.second) || (g1.first>=g2.first&&g1.first<=g2.second) || (g2.first>=g1.first&&g2.second<=g1.second) || (g1.first>=g2.first&&g1.first<=g2.second) || (g2.first>=g1.first&&g2.first<=g1.second) || (g1.first>=g2.first&&g1.second<=g2.second))
            cout<<"-1"<<endl;
        else{
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
}