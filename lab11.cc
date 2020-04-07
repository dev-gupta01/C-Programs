#include<bits/stdc++.h>
#include<fstream>
#include<set>
#include<vector>
#include<map>
using namespace std;
map<string,string> mp;
int main()
{
    fstream file;
    file.open("prog1.txt");
    string str="";
    string res="";
    char ch;
    int i,j,len;
    while(file>>noskipws>>ch)
        str+=ch;
    len=str.length();
    for(i=0;i<(len-7);i++)
    {
        if(str.substr(i,7)=="#define")
        {
                cout<<"fds"<<endl;
                string str1="",str2="";
                j=i+8;
                while(j<len&&str[j]!=' ')
                {
                        str1+=str[j];
                        j++;
                }
                j++;
                while(j<len&&str[j]!='\n')
                {
                        str2+=str[j];
                        j++;
                }
                mp[str1]=str2;
        }
    }
    map<string,string>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();itr++)
        cout<<itr->first<<" "<<itr->second<<endl;
    for(i=0;i<len;i++)
    {
        j=i;
        string tmp="";
        while(str[j]!='\n')
        {
                tmp+=str[j];
                j++;
        }
        if(tmp.substr(0,7)=="#define")
        {
                i=j;
                tmp+='\n';
                continue;
        }
        string str2="";
        j=i;
        while(str[j]!=' '&&str[j]!='\n')
        {
                str2+=str[j];
                j++;
        }
        if(mp.find(str2)!=mp.end())
                res+=mp[str2];
        else
                res+=str2;
        res+=str[j];
        i=j;
    }
    //cout<<res<<endl;
    file.close();
    file.open("prog2.txt");
    file<<res;
    file.close();
    return 0;
}