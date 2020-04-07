#include<bits/stdc++.h> 
using namespace std;
#define ll long long int
#define MOD 10000007
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
ll power(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y&1) 
            res=(res*x+MOD)%MOD; 
        y=y>>1;
        x=(x*x+MOD)%MOD;
    }
    return (res+MOD)%MOD;
}
int main(){
    IOS
    ll n,k;
    cin>>n>>k;
    cout<<power(n,k)<<endl;
}