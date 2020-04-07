#include<bits/stdc++.h> 
using namespace std; 
int tno , lno ; int e ; 
map<string,int> mp; vector<string> ctable , type ; vector<int> lnum;   map<string, int > id; 
map<string,int> op; 
bool isKeyword(string s)
{
 if(mp.find(s)!=mp.end())
return(true); 
else
return(false);
}

bool isIdentifier(string s)
{
  int n = s.size(); 
string g =""; 
for(int i = 0 ; i<min(n,35); i++)
g+=s[i]; 

if(id.find(g)!=id.end())
{
 int num = ctable.size(); 
if(num>0&&(ctable[num-1]=="int"||ctable[num-1]=="float"||ctable[num-1]=="long"||ctable[num-1]=="double"||ctable[num-1]=="string"||ctable[num-1]=="char"))
return(false); 
}
 

if(!((g[0]>='a'&&g[0]<='z')||(g[0]>='A'&&g[0]<='Z')||g[0]=='_'))
return(false); 

if(mp.find(g)!=mp.end())
return(false); 

id[g]=1; return(true); 
}


bool isConstant(string s)
{int c =0 , f = -1; 
for(int i = 0 ; i<s.size();i++)
{  
 if(s[i]<'0'||s[i]>'9')
{
c++; f=i ; 
}

}
if(c==0)return(true); 

if(c==1&f!=0&&f!=s.size()-1&&s[f]=='.')
return(true); 
return(false); 
}


bool isOperator(string s)
{
 if(op.find(s)!=op.end())
return(true); 
return(false); 
}

bool isString(string s)
{
if(s[0]=='"'&&s[s.size()-1]=='"')
return(true); 
return(false); 
}

bool isSpecialSymbol(string s)
{
if(s.size()>1)
return(false); 

if(!((s[0]<='z'&&s[0]>='a')||(s[0]<='Z'&&s[0]>='A')||(s[0]<='9'&&s[0]>='0')))
return(true); 
return(false); 
}

void filltable(string s)
{ 
  if(isKeyword(s))
type.push_back("Keyword");
else if(isIdentifier(s))
type.push_back("Identifier"); 
else if(isConstant(s))
type.push_back("Constant"); 
else if(isOperator(s))
type.push_back("Operator"); 
else if(isString(s))
type.push_back("String"); 
else if(isSpecialSymbol(s))
type.push_back("SpecialSymbol"); 
else 
e=1 ; 

if(e)
cout<<"Error at line = "<<lno<<" token no = "<<tno<<endl; 
else
{
ctable.push_back(s); 
lnum.push_back(lno); 
}
 
}
int main()
{
ifstream f1 ; ofstream f2 ;
f1.open("prog.txt"); f2.open("prog2.txt"); 
tno = 0 ; 
lno = 0; mp["int"]= 1; mp["for"] = 1; mp["main"]= 1; mp["if"]=1; mp["else"]=1; mp["long"]=1; mp["return"]=1; mp["char"]=1; mp["string"]=1; mp["while"]=1; mp["float"]=1; mp["double"]=1; mp["sizeof"]=1; mp["continue"]=1; 
op["+"]=1; op["-"]= 1 ; op["*"]=1; op["="]=1; op["/"]=1 ; op["<"]=1; op["%"]=1; op[">"]; op["<="]=1; op[">="]=1;
op["=="]=1; 

string s ; 
while(getline(f1,s))
{ lno++; tno = 0 ; if(lno<=2)continue; 
int n = s.size(); 
string cur = ""; 
for(int i =0 ; i<n ; i++)
{
if(s[i]==' ')
{ if(!cur.empty())
{tno++;e =0 ;  filltable(cur);
if(e==0)
{
int num = ctable.size(); 
if(type[num-1]=="Operator")
f2<<"("<<ctable[num-1]<<")";
else
f2<<"("<<type[num-1]<<","<<ctable[num-1]<<")" ; 
}
} 
cur = "";
}
else
cur+=s[i];
}
e = 0 ; 
filltable(cur); 
if(e==0)
{
int num = ctable.size(); 
if(type[num-1]=="Operator")
f2<<"("<<ctable[num-1]<<")";
else
f2<<"("<<type[num-1]<<","<<ctable[num-1]<<")" ; 
}
f2<<endl; 
}
cout<<"sno    line number  type  value "<<endl; 

for(int i =0 ; i<ctable.size(); i++)
{
cout<<i+1<<"     "<<lnum[i]<<"      "<<type[i]<<"     "<<ctable[i]<<endl; 
}
f1.close(); 
return(0); 
}

