#include<bits/stdc++.h>
#include<fstream>
#include<set>
#include<vector>
#include<map>
using namespace std;
set<char> integer;
set<string> keys;
set<string> oper;
void initial(){
    oper.insert("+");oper.insert("-");oper.insert("*");oper.insert("/");oper.insert("=");
    keys.insert("for");keys.insert("while");keys.insert("if");keys.insert("else");keys.insert("for");
    keys.insert("continue");keys.insert("break");keys.insert("do");keys.insert("return");
    keys.insert("main");
    keys.insert("int");keys.insert("char");keys.insert("string");keys.insert("case");keys.insert("typedef");
    integer.insert('0');integer.insert('1');integer.insert('2');integer.insert('3');integer.insert('4');integer.insert('5');
    integer.insert('6');integer.insert('7');integer.insert('8');integer.insert('9');
}
int main()
{
    initial();
    ifstream file;
    file.open("prog.txt");
    if(!file)
    {
        cout<<"can't open the file\n";
        return 0;
    }
    vector<pair<string,string> > store;
    map<string,string> mp;
    char ch;
    while(!file.eof())
    { 
        string str;
        while(!file.eof())
        {
            file.get(ch);
            if(ch != ' ' && ch!='\n')
                str+=ch;
            else
                break;
        }
        int n=str.length();
        if(oper.find(str)!=oper.end()){
            store.push_back(make_pair(str,"oper"));
            mp[str]="NULL";
        }
        else if(keys.find(str)!=keys.end()){
            store.push_back(make_pair(str,"keys"));
            mp[str]="NULL";
        }
        else if(integer.find(str[0])!=integer.end()){
            store.push_back(make_pair(str,"constant"));
            mp[str]="int";
        }
        else if(str[0]== '\"'){
            store.push_back(make_pair(str,"string"));
            mp[str]="string";
        }
        else if(str[0]==';' || str[0]=='#' || str[0]=='{' || str[0]=='}'){
            store.push_back(make_pair(str,"special_character"));
            mp[str]="NULL";
        }
        else if(str[n-1] ==')'){
            store.push_back(make_pair(str,"function"));
            mp[str]="NULL";
        }
        else {
            store.push_back(make_pair(str,"identifier")); 
            mp[str]="int";
        } 
    }
    cout<<store.size()<<"\n";
    for(int i=0;i<store.size()-1;i++)
        cout<<i+1<<setw(10)<<store[i].first<<setw(10)<<store[i].second<<setw(10)<<mp[store[i].first]<<"\n";
    return 0;
}





