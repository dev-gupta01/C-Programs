#include <bits/stdc++.h>  
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int c;
        cin>>c;
        for(int y=0;y<6;y++){
            int x;
            cin>>x;
            if(x==0){
                int p,q;
                long long int v;
                cin>>p>>q>>v;
                for(int i=p-1;i<=q-1;i++)
                        a[i]+=v;
            }
            if(x==1){
                int p,q;
                cin>>p>>q;
                long long int sum=0;
                for(int i=p-1;i<=q-1;i++)
                        sum+=a[i];
                cout<<sum<<endl;
            }
        }
    }
}