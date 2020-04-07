#include<bits/stdc++.h>
using namespace std;
int operation(int op2,int op1,int s){
  switch(s){
    case '+':return((op2)+(op1));
    case '-':return((op2)-(op1));
    case '*':return((op2)*(op1));
    case '/':return((op2)/(op1));
  }
}
void evaluate(char s[],int n){
  stack <int> s1;
  for(int i=0;i<n;i++){
    if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
      s1.push(s[i]-'0');
    else{
      int op1,op2;
      op1=s1.top();
      s1.pop();
      op2=s1.top();
      s1.pop();
      int ans=operation(op2,op1,s[i]);
      s1.push(ans);
    }
  }
  cout<<"\n"<<s1.top()<<"\n";
}
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;

	return weight;
  }
}
void convert(string s)
{
  char s1[s.length()];
  int k=0;
  stack <char> s2;
  for(int i=0;i<s.length();i++){
    if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){
      s1[k]=s[i];
      k++;
    }
    else
    {
      while(!s2.empty()&&(GetOperatorWeight(s2.top())>=GetOperatorWeight(s[i]))){
        s1[k]=s2.top();
        k++;
        s2.pop();
      }
      s2.push(s[i]);
    }
  }
  while(!s2.empty()){
    s1[k]=s2.top();
    s2.pop();
    k++;
  }
  for(int i=0;i<s.length();i++){
    cout<<s1[i];
  }
  evaluate(s1,s.length());
}
int main(){
  string s;
  cin>>s;
  convert(s);
}
