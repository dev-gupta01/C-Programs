#include<bits/stdc++.h>
using namespace std;
void findprime(int n){
    vector<int> v(n+1,1);
    v[0]=0;
    v[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(v[i]==1){
            for(int j=2;j*i<=n;j++){
                v[i*j]=0;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=0)
            cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    findprime(n);
}