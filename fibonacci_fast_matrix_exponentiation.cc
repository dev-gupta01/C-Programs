//sum of fibonacci numbers from n to m 0<=n<=m<=10^9
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m;
#define MOD 1000000007
void multi(ll F[2][2],ll M[2][2]){
    ll x = ((F[0][0])%MOD *(M[0][0])%MOD + (F[0][1])%MOD*(M[1][0])%MOD )%MOD;
    ll y = ((F[0][0])%MOD *(M[0][1])%MOD + (F[0][1])%MOD*(M[1][1])%MOD )%MOD;
    ll z = ((F[1][0])%MOD *(M[0][0])%MOD + (F[1][1])%MOD*(M[1][0])%MOD )%MOD;
    ll w = ((F[1][0])%MOD *(M[0][1])%MOD + (F[1][1])%MOD*(M[1][1])%MOD )%MOD;
     
    F[0][0] = (ll)(x%MOD);
    F[0][1] = (ll)(y%MOD);
    F[1][0] = (ll)(z%MOD);
    F[1][1] = (ll)(w%MOD);
}
void power(ll F[2][2],ll n){
    if(n==0||n==1)
        return;
    ll M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multi(F,F);
    if(n%2==1)
        multi(F,M);
}
ll fibo(ll n){
    ll F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n-1);
    return F[0][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        cin>>n>>m;
        ll f[2];
        ll ans=0,temp;
        ans=((fibo(m+2)%MOD)-(fibo(n+2)%MOD)+(fibo(n)%MOD)+MOD)%MOD;
        cout<<ans<<endl;
    }
}