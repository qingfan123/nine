#include<iostream>
using namespace std;
#include<cstring>
int main(){
	int a[8][8];
	char str[10];
	int i,j,len,tmp,sum=0,row,col;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			a[i][j]=0;
		}
	}
	cin>>str;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]!='*')
		{
			tmp=str[i]-'1';
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				a[j][tmp]=1;
			}
			row=i-1;
			col=tmp-1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row--][col--]=1;
			}
			row=i+1;
			col=tmp+1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row++][col++]=1;
			}
		}
	}
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(a[i][j]==0)
			{
				tmp=j+1;
				sum++;
			}
		}
	}
	if(sum==1){
		cout<<tmp<<endl;
	}
	else{
		cout<<"no answer"<<endl;
	}
	return 0;
}
