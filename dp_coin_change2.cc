//minimum number of coins required to change an amount
#include<bits/stdc++.h>
using namespace std;
void coin_change(long long int cost,long long int n,long long int coin_val[]){
    vector<long long int> ways(cost+1,1e7);
    ways[0]=1;
    for(int i=0;i<n;i++)
        ways[coin_val[i]]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<cost+1;j++){
            if(coin_val[i]<=j)
                ways[j]=min(ways[j],1+ways[j-coin_val[i]]);
        }
    }
    /*for(auto i:ways)
        cout<<i<<" ";
    cout<<endl;*/
    cout<<ways[cost]<<endl;
}
int main(){
    long long int cost,n;
    cin>>cost>>n;
    long long int coin_val[n];
    for(long long int i=0;i<n;i++)
        cin>>coin_val[i];
    coin_change(cost,n,coin_val);
}