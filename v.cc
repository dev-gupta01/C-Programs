#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(long long int n){
    string s=to_string(n);
    string a=s;
    reverse(s.begin(),s.end());
    if(a==s)
        return true;
    else
        return false;
}
void findans(long long int n){
    n++;
    while(!ispalindrome())
        n++;
    cout<<n<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        findans(n);
    }
    
}