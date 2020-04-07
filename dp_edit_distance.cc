#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[2001][2001];
void edit(string s1,string s2,int n,int m){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		edit(s1,s2,s1.length(),s2.length());
	}
}