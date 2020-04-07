#include<bits/stdc++.h>
#define ll long long int
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool visit[5][5];
int main(){
    IOS
    string s;
    cin>>s;
    int n=s.length();
    //vector<pair<int,int> > v(n);
    //cout<<"n= "<<n<<endl;
    for(int i=0;i<n;i++){
        int p,q;
        if(s[i]=='0'){
            //cout<<"i= "<<i<<endl;
            for(p=1;p<4;p++){
                for(q=1;q<5;q++){
                    if(visit[p][q]==false && visit[p+1][q]==false){
                        visit[p][q]=true;
                        visit[p+1][q]=true;
                        //cout<<"i= "<<i<<endl;
                        cout<<p<<" "<<q<<endl;
                        break;
                    }
                }
                if(q<5)
                    break;
            }
            
        }
        else{
            //cout<<"i= "<<i<<endl;
            for(p=1;p<5;p++){
                for(q=1;q<4;q++){
                    if(!visit[p][q] && !visit[p][q+1]){
                        visit[p][q]=true;
                        visit[p][q+1]=true;
                        //cout<<"i= "<<i<<endl;
                        cout<<p<<" "<<q<<endl;
                        break;
                    }
                }
                if(q<4)
                    break;
            }
        }
        for(p=1;p<5;p++){
            int count=0;
            for(int x=1;x<5;x++)
                if(visit[p][x]==true)
                    count++;
            if(count==4){
                for(int x=1;x<5;x++)
                    visit[p][x]=false;
            }
        }
        for(q=1;q<5;q++){
            int count=0;
            for(int x=1;x<5;x++)
                if(visit[x][q]==true)
                    count++;
            if(count==4){
                for(int x=1;x<5;x++)
                    visit[x][q]=false;
            }
        }
        
    }
}