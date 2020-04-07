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
void build(int T[],int a[],int node,int l,int r,int &count,int k){
    if(l==r){
        T[node]=a[l];
        if(T[node]<k)
            count++;
        return;
    }
    int mid=(l+r)/2;
    build(T,a,2*node+1,l,mid,count,k);
    build(T,a,2*node+2,mid+1,r,count,k);
    T[node]=(T[2*node+1]^T[2*node+2]);
    if(T[node]<k)
        count++;
    return;
}
int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        int T[4*n+1];
        memset(T,0,sizeof(T));
        forall(i,0,n)
            cin>>a[i];
        int count=0;
        build(T,a,0,0,n-1,count,k);
        forall(i,0,4*n)
            cout<<T[i]<<" ";
        cout<<endl;
        cout<<count<<endl;
    }
	return 0;
}