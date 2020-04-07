#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define MOD 10000007
#define forinc(i,a,b) for(ll i=a;i<b;i++)
#define fordec(i,a,b) for(ll i=a;i>b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
ll computeXOR(const ll n){ 
	switch(n&3){ 
	    case 0: return n;	 
	    case 1: return 1;	  
	    case 2: return n + 1;	 
	    case 3: return 0;	 
	} 
}
int main(){
    cout<<computeXOR(10)<<endl;
}