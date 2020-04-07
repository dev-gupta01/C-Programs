#include<bits/stdc++.h>
/*#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;*/
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
int n,m;
int graph[100][100];
int path[100]={-1};
void print(){
    fori(i,0,n){
        cout<<path[i]<<"-->";
    }
    cout<<0<<endl;
}
bool isSafe(int v,int pos){
    if(graph[path[pos-1]][v]==0)
        return false;
    fori(i,0,pos)
        if(path[i]==v)
            return false;
    return true;
}
bool h_Util(int pos){
    if(pos==n){
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        return false;
    }
    fori(v,1,n){
        if(isSafe(v,pos)){
            path[pos]=v;
            if(h_Util(pos+1))
                return true;
            path[pos]=-1;
        }
    }
    return false;
}
void hamiltonian(){
    path[0]=0;
    if(h_Util(1)){
        print();
        return;
    }
    cout<<"No Solution\n";
    return;
}
int main(){
    IOS
    cin>>n;
    fori(i,0,n)
        fori(j,0,n)
            cin>>graph[i][j];
    hamiltonian();
}