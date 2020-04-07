#include<bits/stdc++.h>
using namespace std;
void findans(int a,int b){
    cout<<(floor(sqrt(b))-ceil(sqrt(a))+1);
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        findans(a,b);
    }
}