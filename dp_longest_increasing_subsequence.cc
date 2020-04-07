#include<bits/stdc++.h>
using namespace std;
void longest_inc_subseq(int a[],int n){
    vector<int> len(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])
                len[i]=len[j]+1;
        }
    }
    for(auto i:len)
        cout<<i<<" ";
    cout<<endl;
    auto it=max_element(len.begin(),len.end());
    cout<<"length of longest increasing subsequence: "<<*it<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    longest_inc_subseq(a,n);
}