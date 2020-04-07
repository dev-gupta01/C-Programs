#include<bits/stdc++.h> 
using namespace std;
#define ll long long int
#define MOD 1000000007
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define ford(i,a,b) for(ll i=a;i>b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.rbegin(),v.rend())
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
ll val[1000001]={-1};
ll idx[100001];
ll findans(int n){
    if(val[n]!=-1)
        return val[n];
    return val[n]=(findans(n-1)+n+n*findans(n-1)+MOD)%MOD;
}
int main(){
    IOS
    int t;
    cin>>t;
    val[1]=1;
    val[0]=0;
    fori(i,0,t){
        int n;cin>>n;
        cout<<findans(n)<<endl;
    }
}