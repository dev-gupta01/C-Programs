#include<bits/stdc++.h>
using namespace std;
int max_commom[2010][2010];
void longest_common_subsequence(int n,string s,int m,string t){
    memset(max_commom,0,sizeof(max_commom));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j])
                max_commom[i][j]=1+max_commom[i+1][j+1];
            else
                max_commom[i][j]=max(max_commom[i+1][j],max_commom[i][j+1]);
        }
    }
    cout<<max_commom[0][0]<<endl;
}
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    longest_common_subsequence(n,s,m,t);
}