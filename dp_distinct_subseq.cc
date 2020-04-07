//number of distinct subsequences of a given string
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string s;
void findans(int n){
    ll dp[n+1];
    ll MOD=1000000007;
    dp[0]=1;
    vector<int> last(256,-1);
    /*for(int i=0;i<=56;i++)
        cout<<last[i]<<" ";
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        dp[i]=(2*dp[i-1])%MOD;
        if(last[s[i-1]]!=-1){
            dp[i]=(dp[i]-dp[last[s[i-1]]]+MOD)%MOD;
        }
        last[s[i-1]]=(i-1);
    }
    cout<<dp[n]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c;
    cin>>c;
    while(c--){
        cin>>s;
        findans(s.length());
    }
}