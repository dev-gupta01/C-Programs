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
typedef pair<ll,ll> llpair ;
int v,e;
vector<pair<ll,llpair> > vec;
vector<pair<ll,llpair> > Tree;
int *par;
int find_set(int i){
    if(i==par[i])
        return i;
    return find_set(par[i]);
}
void union_set(int u,int v){
    par[u]=par[v];
}
void kruskal(){
    int i,uRep,vRep;
    fori(i,0,e){
        uRep=find_set(vec[i].second.first);
        vRep=find_set(vec[i].second.second);
        if(uRep!=vRep){
            Tree.push_back(vec[i]);
            union_set(uRep,vRep);
        }
    }
}
int main(){
    IOS
    cin>>v>>e;
    int wt,p,q;
    fori(i,0,e){
        cin>>p>>q>>wt;
        vec.push_back(mp(wt,mp(p,q)));
    }
    sorti(vec);
    par=new int[v];
    fori(i,0,v)
        par[i]=i;
    kruskal();
    cout<<"Tree is:\n";
    fori(i,0,Tree.size())
        cout<<Tree[i].second.first<<" - "<<Tree[i].second.second<<"  "<<Tree[i].first<<endl;

}