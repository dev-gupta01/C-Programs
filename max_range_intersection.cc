#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define forall(i,a,b) for(ll i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    IOS
    ll t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<int,char> > v;
        ll l,r,max_r=0;
        for(ll i=0;i<n;i++){
            cin>>l>>r;
            v.push_back(mp(l,'e'));
            v.push_back(mp(r,'l'));
        }
        sort(all(v));
        int count=0,ans=-1;
        for(int i=0;i<v.size();i++){
            if(v[i].second=='e')
                count++;
            else
                count--;
            ans=max(ans,count);
        }
        cout<<ans<<endl;
    }
}