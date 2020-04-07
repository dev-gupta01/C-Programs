#include<bits/stdc++.h>
using namespace std;
int *a;
void find_a(int n,string s){
    int j=0,i=1;
    a[0]=0;
    while(i<n){
        if(s[i]==s[j]){
            a[i]=j+1;
            j++;
        }
        else{
            if(j!=0) 
                j=a[j-1]; 
            else{
                i=i+1;
            }
            continue;
        }
        i++;
    }
}
void find_occ(string s,string text){
    int i=0;  
    int j=0; 
    while(i<text.length()){ 
        if(s[j]==text[i]){ 
            j++; 
            i++; 
        }
        if(j==s.length()){ 
            printf("%d\n",i-j); 
            j=a[j-1]; 
        } 
        else if (i<text.length()&& s[j]!=text[i]){ 
            if(j!=0) 
                j=a[j-1]; 
            else
                i=i+1; 
        } 
    } 
}
int main(){
    int n;
    bool first = true;
    while(scanf("%d",&n)==1){
        if (!first) puts("");
            first = false;
        string s;
        getline(cin,s);
        a=new int[n];
        find_a(n,s);
        string text;
        getline(cin, text);
        find_occ(s,text);
        cout<<"\n";
    }
}