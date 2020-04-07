#include<bits/stdc++.h>
#include<fstream>
#include<set>
#include<vector>
#include<map>
using namespace std;
int main()
{
	ifstream file1("prog1.txt");
	ofstream file2("prog2.txt");
	char ch, ptr='*';
	if(!file1)
	{
		cout<<"can't open file"<<endl;
		return 0;
	}
	if(!file2)
	{
		cout<<"can't open file"<<endl;
		return 0;
	}
	while(file1)
	{
		file1.get(ch);
		if(ch == '/' && ptr == '/')
		{
			while(ch!='\n' && !file1.eof())
				file1.get(ch);
			file2.put('\n');
		}
		else if(ch == '*' && ptr == '/')
		{
			while(ch!='/' && !file1.eof())
				file1.get(ch);
			file1.get(ch);
			file2.put(ch);
		}
		else if(ch != '/')
		{
			file2.put(ch);
		}
		ptr = ch;
	}
	file1.close();
	file2.close();
	return 0;
}