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
int n;
int board[100][100];
void print(){
    fori(i,0,n){
        fori(j,0,n)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
bool isSafe(int row,int col){
    fori(i,0,col)
        if(board[row][i])
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return false;
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
        if(board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int row,int col){
    if(col>=n)
        return true;
    fori(i,0,n){
        if(isSafe(i,col)){  
            board[i][col]=1;
            if(solveNQUtil(row,col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}
void solveNQ(){
    if(solveNQUtil(0,0)){
        print();
        return;
    }
    cout<<"NO SOL";
    return;
}
int main(){
    IOS
    cin>>n;
    solveNQ();
}