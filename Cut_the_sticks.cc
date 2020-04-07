#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.rbegin(),v.rend());
    while(!v.empty()){
        cout<<v.size()<<"\n";
        for(int i=0;i<v.size();i++){
            v[i]-=v[v.size()-1];
        }
        v.erase(std::remove(v.begin(), v.end(), 0), v.end());
    }
}