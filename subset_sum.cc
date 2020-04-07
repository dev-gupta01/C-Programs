#include<bits/stdc++.h> 
using namespace std;
#define ll long long int
#define MOD 10000007
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define ford(i,a,b) for(ll i=a;i>b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define sorti(v) sort(v.begin(),v.end())
#define sortd(v) sort(v.rbegin(),v.rend())
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int n,k,total=0;
vector<int> v;
void print(int t[],int n){
    fori(i,0,n)
        cout<<t[i]<<" ";
    cout<<endl;
    return;
}
void subset(int a[],int tupple[],int t_size,int sum,int ite){
    if(sum==k){
        total+=1;
        print(tupple,t_size);
        if(ite+1<n&&sum-a[ite]+a[ite+1]<=k)
            subset(a,tupple,t_size-1,sum-a[ite],ite+1);
        return;
    }
    else{
        if(ite<n&&sum+a[ite]<=k){
            fori(i,ite,n){
                tupple[t_size]=a[i];
                if(sum+a[i]<=k)
                    subset(a,tupple,t_size+1,sum+a[i],i+1);
            }
        }
    }
}
void sum_subset(int a[]){
    int *tupple=new int[n];
    int total=0;
    fori(i,0,n)
        total+=a[i];
    if(a[0]<=k&&total>=k)
        subset(a,tupple,0,0,0);
}
int main(){
    IOS
    cin>>n>>k;
    int a[n];
    fori(i,0,n)
        cin>>a[i];
    sort(a,a+n);
    sum_subset(a);
    cout<<"total= "<<total<<endl;
}