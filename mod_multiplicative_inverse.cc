#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define forall(i,a,b) for(ll i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define MOD 1000000007
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
ll power(int x,ll y,ll m);
ll modInverse(int a,int m){
    return power(a,m-2,m)%m;
}
ll power(int x,ll y,ll m){ 
    if (y==0) 
        return 1; 
    int p=power(x,y/2,m)%m; 
    p=((p%m)*(p%m)+m)%m;
    return (y%2==0)?p:((x%m)*(p%m)+m)%m; 
} 
int main(){
    cout<<5*modInverse(1,MOD)<<endl;
}