#include <bits/stdc++.h> 
using namespace std; 
void findans(int low,int high,int k,int n,int m){
    int mid=(low+high)/2;
    if(low>=high){
        if(mid==0){
            cout<<"1"<<endl;
            return;
        }
        cout<<mid<<endl;
        return;
    }
    int lb=0;
    for(int i=1;i<=n;i++){
        int x=(mid)/i;
        if(x>m)
            x=m;
        lb+=x;
    }
    cout<<mid<<" lb "<<lb<<endl;
    if(k<=lb)
        findans(low,mid,k,n,m);
    else if(k>lb)
        findans(mid+1,high,k,n,m);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    findans(1,n*m,k,n,m);
}
