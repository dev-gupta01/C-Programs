#include<bits/stdc++.h>
using namespace std;

char hFirst[10][100];
char hFollow[10][100];
char production[10][10], first_fn[10];
void follow_fn(char c)
{
	int i ,j;
	if(production[0][0]==c){
 		f[m++]='$';
 	}
 	for(i=0;i<10;i++)
 	{
  		for(j=2;j<10;j++)
  		{
   			if(production[i][j]==c)
   			{
    			if(production[i][j+1]!='\0'){
					flowfrst(production[i][j+1],i,(j+2));
 				}
    			if(production[i][j+1]=='\0'&&c!=production[i][0]){
     				follow_fn(production[i][0]);
				}
   			}   
  		}
 	}
}

void first_fn(char c ,int q1 , int q2)
{
	int j;
	if(!(isupper(c))){
		first_fn[n++]=c;
	}
	for(j=0;j<cnt;j++)
	{
		if(production[j][0]==c)
		{
			if(production[j][2]=='#'){
				if(production[q1][q2] == '\0')
					first_fn[n++]='#';
				else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
				{
					first_fn(production[q1][q2], q1, (q2+1));
				}
				else
					first_fn[n++]='#';
			}
			else if(!isupper(production[j][2])){
				first_fn[n++]=production[j][2];
			}
			else {
				first_fn(production[j][2], j, 3);
			}
		}
	}	
}

void flowfrst(char c, int c1 , int c2)
{
    int k;
    if(!(isupper(c)))
		f[m++]=c;
	else{
		int i=0,j=1;
		for(i=0;i<cnt;i++)
		{
			if(hFirst[i][0] == c)
				break;
		}
		while(hFirst[i][j] != '!')
		{
			if(hFirst[i][j] != '#'){
				f[m++] = hFirst[i][j];
			}
			else{
				if(production[c1][c2] == '\0'){
					follow_fn(production[c1][0]);
				}
				else{
					flowfrst(production[c1][c2],c1,c2+1);
				}
			}
			j++;
		}
	}
}

int main()
{int j=0,k1=0;
	int i,choice;
	char c,ch;
	cout<<"Enter number of non-terminals and terminals::"<<endl;
	int x,y;
	cin>>x>>y;
	vector<vector<string> > test(x, vector<string> (y));
	cout<<"Enter parsing table::"<<endl;
	for(int i = 0; i<x;i ++)
	for(int j = 0; j<y; j++)
	cin>>test[i][j];
	cout<<"Enter input string::"<<endl;
	char input[100];
	scanf("%s%c",input,&ch);
	for(i=0;i<cnt;i++)
	{	
		scanf("%s%c",production[i],&ch);
	}
	int f1;
	char done[cnt];
	int ptr1 = -1;
	for(k=0;k<cnt;k++){
		for(f1=0;f1<100;f1++){
			hFirst[k][f1] = '!';
		}
	}
	int ptuno = 0,point2,temp0;
	for(k=0;k<cnt;k++)
	{
		c=production[k][0];
		point2 = 0;
		temp0 = 0;
		for(f1 = 0; f1 <= ptr1; f1++)
			if(c == done[f1])
				temp0 = 1;
		if (temp0 == 1)
			continue;
		first_fn(c,0,0);
		ptr1+=1;
		done[ptr1] = c;
		printf("\n first_fn(%c)= { ",c);
		hFirst[ptuno][point2++] = c;
		for(i=0+j;i<n;i++){
			int ptdos = 0,chk = 0;
		for(ptdos=0;ptdos<point2;ptdos++)
		{
		if (first_fn[i] == hFirst[ptuno][ptdos]){
			chk = 1;
			break;
		}
		}
		if(chk == 0){
 		printf("%c, ",first_fn[i]);
		hFirst[ptuno][point2++] = first_fn[i];
	}
		}
		printf("}\n");
		j=n;
		ptuno++;
	}
	printf("\n");
	char comp[cnt];
	ptr1 = -1;
	for(k=0;k<cnt;k++){
		for(f1=0;f1<100;f1++){
			hFollow[k][f1] = '!';
		}
	}
	ptuno = 0;
	int land = 0;
	for(e=0;e<cnt;e++)
  	{
		ck=production[e][0];
		point2 = 0;
		temp0 = 0;
		for(f1 = 0; f1 <= ptr1; f1++)
			if(ck == comp[f1])
				temp0 = 1;
		if (temp0 == 1)
			continue;
  		land += 1;
		follow_fn(ck);
  		ptr1+=1;
		comp[ptr1] = ck;
  		printf(" follow_fn(%c) = { ",ck);
  		hFollow[ptuno][point2++] = ck;
  		for(i=0+k1;i<m;i++){
  			int ptdos = 0,chk = 0;
  			for(ptdos=0;ptdos<point2;ptdos++){
  				if (f[i] == hFollow[ptuno][ptdos]){
  					chk = 1;
  					break;
				}
			}
			if(chk == 0){
  		 		printf("%c, ",f[i]);
  				hFollow[ptuno][point2++] = f[i];
  			}
  		}
  		printf(" }\n\n");
		k1=m;
		ptuno++; 
	}
	char ter[10];
	for(k=0;k<10;k++){
		ter[k] = '!';
	}
	int h,vp,sid = 0;
	for(k=0;k<cnt;k++){
		for(f1=0;f1<cnt;f1++){
		if(!isupper(production[k][f1]) && production[k][f1]!= '#' && production[k][f1] != '=' && production[k][f1] != '\0'){
		vp = 0;
		for(h = 0;h < sid; h++){
		if(production[k][f1] == ter[h]){
			vp = 1;
			break;
		}
		}
		if(vp == 0)
		{
		ter[sid] = production[k][f1];
		sid ++;
		}
	}
		}
	}
	ter[sid] = '$';
	sid++;
	printf("\n\t\t\t\n");
	printf("\t\t\t\t|\t");
	for(h = 0;h < sid; h++){
		printf("%c\t\t",ter[h]);
	}
	printf("\n\t\t\t\n");
	char first_prod[cnt][sid];
	for(h=0;h<cnt;h++){
		int d1 = 0;
		k = 2;
		int ct = 0;
		char tem[100];
	while(production[h][k] != '\0')
	{
		if(!isupper(production[h][k])){
			tem[ct++] = production[h][k];
			tem[ct++] = '_';
			tem[ct++] = '\0';
			k++;
			break;
		}
		else{
			int zap=0;
			int buffer = 0;
			for(zap=0;zap<cnt;zap++){
			if(hFirst[zap][0] == production[h][k]){
			for(buffer=1;buffer<100;buffer++){
			if(hFirst[zap][buffer] != '!'){
				tem[ct++] = hFirst[zap][buffer];
			}
			else
				break;
			}
			break;
			}
			}
			tem[ct++] = '_';
		}
		k++;
		}
		int zap = 0,buffer;		
		for(buffer = 0;buffer<ct;buffer++){
			if(tem[buffer] == '#'){
				zap = 1;
			}
			else if(tem[buffer] == '_'){
			if(zap == 1){
				zap = 0;
			}
			else
				break;
		}
		else{
			first_prod[h][d1++] = tem[buffer];
		}
		}
	}
	char parseTab[land][sid+1];
	ptr1 = -1;
	for(h = 0; h < land ; h++){
		for(f1 = 0; f1 < (sid + 1) ; f1++){
			parseTab[h][f1] = '!';
		}
	}

	
	printf("\n\n");
	printf("\t\t\t\t\t\tStack\t\t\tInput\t\t\tAction");
	int i_ptr = 0,s_ptr = 1;
	char stack[100];
	stack[0] = '$';
	stack[1] = table[0][0];
	while(s_ptr != -1){
		printf("\t\t\t\t\t\t");
		int vamp = 0;
		for(vamp=0;vamp<=s_ptr;vamp++){
			printf("%c",stack[vamp]);
		}
		printf("\t\t\t");
		vamp = i_ptr;
		while(input[vamp] != '\0'){
			printf("%c",input[vamp]);
			vamp++;
		}
		printf("\t\t\t");
		char her = input[i_ptr];
		char him = stack[s_ptr];
		s_ptr--;
		if(!isupper(him)){
			if(her == him){
				i_ptr++;
				printf("POP ACTION\n");
			}
			else{
				printf("\nString Not Accepted by LL(1) Parser !!\n");
				exit(0);
			}
		}
		else{
			for(i=0;i<sid;i++){
				if(ter[i] == her)
					break;
			}
			char produ[100];
			for(j=0;j<land;j++){
				if(him == table[j][0]){
					if (table[j][i+1] == '#'){
						printf("%c=#\n",table[j][0]);
						produ[0] = '#';
						produ[1] = '\0';
					}
					else if(table[j][i+1] != '!'){
						int mum = (int)(table[j][i+1]);
						mum -= 65;
						strcpy(produ,production[mum]);
						printf("%s\n",produ);
					}
					else{
						printf("\nString Not Accepted by LL(1) Parser !!\n");
						exit(0);
					}
				}
			}
			int le = strlen(produ);
			le = le - 1;
			if(le == 0){
				continue;
			}
			for(j=le;j>=2;j--){
				s_ptr++;
				stack[s_ptr] = produ[j];
			}
		}
	}if (input[i_ptr] == '\0'){
		printf("\t\t\t\t\t\t\t\tYOUR STRING HAS BEEN ACCEPTED !!\n");
	}
	else
		printf("\n\t\t\t\t\t\t\t\tYOUR STRING HAS BEEN REJECTED !!\n");
	}