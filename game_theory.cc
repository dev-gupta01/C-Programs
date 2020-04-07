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
#define vp_ll(v) vector<pair<ll,ll> > v;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
int calculateMex(unordered_set<int> Set){
    int Mex=0;
    while(Set.find(Mex)!=Set.end())
        Mex++;
    return Mex;
}

//1. game starts with a pile of n stones
//player to move may take any positive 
//number of stones.

// int calculateGrundy(int n,int Grundy[]){
//     if(n==0)
//         return 0;
//     if(Grundy[n]!=-1)
//         return Grundy[n];
//     unordered_set<int> Set;
//     forinc(i,1,n+1)
//         Set.insert(calculateGrundy(n-i,Grundy));
//     Grundy[n]=calculateMex(Set);
//     return Grundy[n];
// }


//2. game starts with a pile of n stones
//player to move may take any positive number
//of stones upto 3 only

// int calculateGrundy(int n,int Grundy[]){
//     if(n==0)
//         return 0;
//     if(n==1)
//         return 1;
//     if(n==2)
//         return 2;
//     if(n==3)
//         return 3;
//     if(Grundy[n]!=-1)
//         return Grundy[n];
//     unordered_set<int> Set;
//     forinc(i,1,4)
//         Set.insert(calculateGrundy(n-i,Grundy));
//     Grundy[n]=calculateMex(Set);
//     return Grundy[n];
// }


//3. game starts with a number- ‘n’
//the player to move divides the number- ‘n’ 
//with 2, 3 or 6 and then takes the floor
//If the integer becomes 0, it is removed.

int calculateGrundy(int n,int Grundy[]){
    if(n==0)
        return 0;
    if(Grundy[n]!=-1)
        return Grundy[n];
    unordered_set<int> Set;
    Set.insert(calculateGrundy(n/2,Grundy));
    Set.insert(calculateGrundy(n/3,Grundy));
    Set.insert(calculateGrundy(n/6,Grundy));
    Grundy[n]=calculateMex(Set);
    return Grundy[n];
}

int main(){
    IOS
    int n=11;
    int Grundy[n+1];
    memset(Grundy,-1,sizeof(Grundy));
    int x=calculateGrundy(n,Grundy);
    cout<<x<<endl;
}

//Sprague-Grundy Theorem says that if both A and B play 
//optimally (i.e., they don’t make any mistakes), then 
//the player starting first is guaranteed to win if the 
//XOR of the grundy numbers of position in each sub-games
//at the beginning of the game is non-zero. Otherwise, 
//if the XOR evaluates to zero, then player A will lose 
//definitely, no matter what.