#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int m;
    cin>>m;
    vector<int> v1(m);
    for(int i=0;i<m;i++){
        cin>>v1[i];
        v.push_back(v1[i]);
    }
    vector<int> v2;
    sort(v.rbegin(),v.rend());
    sort(v1.rbegin(),v1.rend());
    int j=0,rank=1;
    for(int i=0;i<v.size();i++){
        if(v[i]==v1[j]){
            v2.push_back(rank);
            j++;
        }
        else if(v[i]>v[i+1])
            rank++;
    }
    for(int i=v2.size()-1;i>=0;i--)
        cout<<v2[i]<<"\n";
}