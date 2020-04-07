#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    while(s!="\n"){
        int x=stoi(s);
        int ans=0;
        while(x>0){
            ans+=x;
            x-=2;
        }
        cout<<ans<<endl;
        cin>>s;
    }
}