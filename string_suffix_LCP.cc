#include<bits/stdc++.h>
#define ll long long int
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<pair<string,int> > st;
void const_suffix_array(string s,int n){
    st.clear();
    for(int i=0;i<n;i++){
        string str=s.substr(i,n-i);
        st.push_back(make_pair(str,i));
    }
    sort(st.begin(),st.end());
    cout<<"Suffix:\n";
    for(auto i:st)
        cout<<i.first<<" "<<i.second<<endl;
}
int LCP[100000];
void const_LCP(string s,int n){
    const_suffix_array(s,n);
    int k=1,ans=0;
    for(int i=0;i<n-1;i++){
        int count=0;
        for(int j=0;j<st[i].first.length();j++){
            if(st[i].first[j]==st[i+1].first[j])
                count++;
            else
                break;
        }
        ans+=count;
        LCP[k]=count; 
        k++;
    }
    //cout<<((n*(n+1))/2)-ans<<endl;
    cout<<"LCP:\n";
    for(int i=0;i<n;i++)
        cout<<LCP[i]<<" ";
    cout<<endl;
}
int main(){
    IOS
    int n; cin>>n;
    while(n--){
        string s;
        cin>>s;
        const_LCP(s,s.length());
    }
}