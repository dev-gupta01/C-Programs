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
void update(ll l,ll r,ll val,ll diff[]){
    diff[l]+=val;
    diff[r+1]-=val;
}
int main(){
    IOS
    ll t; cin>>t;
    while(t--){
        ll n,u;
        cin>>n>>u;
        ll a[n]={0};
        ll diff[n+1]={0};
        ll l,r,val;
        for(ll i=0;i<u;i++){
            cin>>l>>r>>val;
            update(l,r,val,diff);
        }
        /*for(ll i=0;i<n;i++)
            cout<<diff[i]<<" ";
        cout<<endl;*/
        a[0]=diff[0];
        for(ll i=1;i<n;i++){
            a[i]=diff[i]+a[i-1];
        }
        ll q; cin>>q;
        ll x;
        while(q--){
            cin>>x;
            cout<<a[x]<<endl;
        }
    }
}