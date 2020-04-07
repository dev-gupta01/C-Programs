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
int main(){
    IOS
    int t;cin>>t;
    while(t--){
        string n,s,ans;
        char d;
        cin>>n>>d;
        ans=n;
        forall(i,0,n.length()+10){
            int x=max_element(all(n))-n.begin();
            s=n;
            s.erase(s.begin()+x);
            s=s+d;
            //cout<<x<<" "<<s<<" "<<n<<endl;
            //cout<<s<<endl;
            ans=min(s,ans);
            n=s;
        }
        cout<<ans<<endl;
    }
}