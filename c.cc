#include<bits/stdc++.h>
using namespace std;
void sweetness(vector<int> v,int k){
    sort(v.begin(),v.end());
    int count=0;
    while(v[0]<k){
        if(v.size()==1){
            cout<<"-1";
            return;
        }
        int x=(v[0]+(2*v[1]));
        v.erase(v.begin());
        v.erase(v.begin());
        v.push_back(x);
        count++;
        sort(v.begin(),v.end());
    }
    cout<<count;
    return;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sweetness(v,k);
}