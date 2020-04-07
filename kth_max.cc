#include<bits/stdc++.h> 
using namespace std;
#define ll long long int
#define MOD 10000007
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define ford(i,a,b) for(ll i=a;i>b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.rbegin(),v.rend())
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
void swap(int *a, int *b) { 
    int temp=*a; 
    *a=*b; 
    *b=temp; 
} 
int partition(int a[],int l,int r){
    int x=a[r],i=l;
    fori(j,l,r){
        if(a[j]>=x){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    swap(&a[i],&a[r]);
    return i;
}
int findans(int a[],int l,int r,int k){
    int pos=partition(a,l,r);
    if(pos-l+1==k)
        return a[pos];
    if(pos-l+1>k)
        return findans(a,l,pos-1,k);
    return findans(a,pos+1,r,k-pos+l-1);
}
int main(){
    IOS
    int k;
    int n;cin>>n>>k;
    int a[n];
    fori(i,0,n)
        cin>>a[i];
    cout<<findans(a,0,n-1,k)<<endl;    
}