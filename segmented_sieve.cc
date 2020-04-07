#include<bits/stdc++.h>
using namespace std;
void print(long long int b[],long long int n,long long int m){
    for(long long int j=0;j<n-m+1;j++){
        if(b[j]!=-1)
            cout<<b[j]<<"\n";
    }
}
void findans(long long int n,long long int m){
    long long int limit=floor(sqrt(n))+1;
    bool a[limit+1];
    memset(a,true,sizeof(a));
    long long int b[n-m+1];
    for(long long int i=0;i<n-m+1;i++)
        b[i]=m+i;
    for(long long int i=2;i*i<=limit;i++){
        if(a[i]==true){
            for(long long int j=i*2;j<limit;j+=i)
                a[j]=false;
        }
    }
    for(long long int p=2;p<limit;p++){ 
        if(a[p]==true){ 
            for(long long int j=0;j<n-m+1;j++){
                if(b[j]%p==0&&b[j]!=-1&&b[j]!=p||b[j]==1)
                    b[j]=-1;
            }
        } 
    }
    print(b,n,m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        long long int n,m;
        cin>>m>>n;
        if(m==1)
			m++;
        findans(n,m);
        if(t)
            cout<<"\n";
    }
} 