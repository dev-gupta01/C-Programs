#include<bits/stdc++.h>
using namespace std;
void primefactorise(int n){
    vector<int> v;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                count++;
                n/=i;
            }
            cout<<i<<"^"<<count<<" * ";
        }
    }
    if(n!=1)
        cout<<n<<"^"<<'1'<<"\n";
}
int main(){
    int n;
    cin>>n;
    primefactorise(n);
}