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
int n,m;
int graph[100][100];
int color[100];
void print(){
    fori(i,0,n){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
bool isSafe(int c,int v){
    fori(i,0,n)
        if(graph[v][i]&&c==color[i])
            return false;
    return true;
}
bool g_colorUtil(int v){
    if(v==n)   
        return true;
    fori(c,1,m+1){
        if(isSafe(c,v)){
            color[v]=c;
            if(g_colorUtil(v+1))
                return true;
            color[v]=0;
        }
    }
    return false;
}
void g_color(int v){
    if(g_colorUtil(v)){
        print();
        return;
    }
    cout<<"No Solution\n";
    return;
}
int main(){
    IOS
    cin>>n>>m;
    fori(i,0,n)
        fori(j,0,n)
            cin>>graph[i][j];
    g_color(0);
}