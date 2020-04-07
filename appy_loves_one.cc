#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,k;
    cin>>n>>q>>k;
    char c;
    string str;
    for(int i=0;i<n;i++){
        cin>>c;
        str+=c;
    }
    string s;
    cin>>s;
    for(int i=0;i<q;i++){
        if(s[i]=='!'){
            char cc=str[n-1];
            string s1=str.substr(0,n-1);
            str.clear();
            str+=cc;
            str+=s1;
        }
        else{
            int count=0; 
            int result=0;
            for (int i=0;i<n;i++){
                if(str[i]=='0')
                    count=0; 
                else{ 
                    count++;
                    result=max(result,count); 
                } 
            }
            cout<<min(result,k)<<endl;
        }
    }
}