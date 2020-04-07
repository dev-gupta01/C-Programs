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
int n,e;
int graph[100][100];
struct Edge{
    int src,dest,wt;
};
void bellman(int start,Edge edge[]){
    int dist[n+1];
    fori(i,0,n+1)
        dist[i]=1e7;
    dist[start]=0;
    int parent[n]={-1};
    parent[0]=0;
    /*fori(i,0,n){
        fori(j,0,n){
            fori(k,0,n){
                if(graph[j][k]!=1e6&&dist[j]!=1e7){
                    if(dist[k]>dist[j]+graph[j][k]){
                        dist[k]=dist[j]+graph[j][k];
                        parent[k]=j;
                        fori(i,0,n)
                            cout<<parent[i]<<" ";
                        cout<<endl;
                    }
                }
            }
        }
    }*/
    fori(i,0,n){
        fori(j,0,e){
            int s=edge[j].src;
            int d=edge[j].dest;
            int w=edge[j].wt;
            if(dist[s]!=1e7){
                if(dist[d]>dist[s]+w){
                    dist[d]=dist[s]+w;
                    parent[d]=s;
                }
            }
        }
    }
    fori(i,0,n)
        cout<<dist[i]<<" ";
    cout<<endl;
    fori(i,0,n)
        cout<<parent[i]<<" ";
    cout<<endl;
}
int main(){
    IOS
    cin>>n>>e;
    Edge *edge=new Edge[e];
    /*fori(i,0,n)
        fori(j,0,n)
            cin>>graph[i][j];*/
    fori(i,0,e){
        int s,d,w;
        cin>>s>>d>>w;
        edge[i].src=s;
        edge[i].dest=d;
        edge[i].wt=w;
    }
    bellman(0,edge);
}
/*5
1000000 -1 4 1000000 1000000
1000000 1000000 3 2 2 
1000000 1000000 1000000 1000000 1000000
1000000 1 5 1000000 1000000
1000000 1000000 1000000 -3 1000000*/