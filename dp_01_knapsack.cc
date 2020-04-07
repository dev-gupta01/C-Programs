#include<bits/stdc++.h>
using namespace std;
int max_val[2010][2010];
void knapsack(int total_wt,int items,int wt[],int val[]){
    //int max_val[items][total_wt+1];
    memset(max_val,0,sizeof(max_val));
    for(int i=0;i<items;i++)
        max_val[i][0]=0;
    for(int j=0;j<=total_wt;j++)
        if(j>=wt[0])
            max_val[0][j]=val[0];
    for(int i=1;i<items;i++){
        for(int j=1;j<=total_wt;j++){
            if(j-wt[i]>=0)
                max_val[i][j]=max(max_val[i-1][j],(max_val[i-1][j-wt[i]]+val[i]));
            else 
                max_val[i][j]=max_val[i-1][j];
        }
    }
    /*for(int i=0;i<items;i++){
        for(int j=0;j<=total_wt;j++)
            cout<<max_val[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<max_val[items-1][total_wt]<<endl;
    //cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int total_wt,items;
        cin>>total_wt>>items;
        int wt[items],val[items];
        for(int i=0;i<items;i++)
            cin>>wt[i]>>val[i];
    /*for(int i=0;i<items;i++)
        cin>>val[i];*/
        knapsack(total_wt,items,wt,val);
    }
}