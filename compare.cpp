#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int main()
{
	int i,j;
	char a[10],b[10];
	cin>>a>>b;
	int x,y;
	x=strlen(a);
	y=strlen(b);
    for(i=0;i<x;i++)
    {
	   if(a[i]>='A'&&a[i]<='Z')
       a[i]=a[i]+32;
	}
    for(j=0;j<y;j++)
    {
       if(b[j]>='A'&&b[j]<='Z')
       b[j]=b[j]+32;
	}
    int min= 25;
	for(i=0;i<x;i++)
    {
    	for(j=0;j<y;j++)
    	{
		if(a[i]==b[j])
		{
		  cout<<0<<endl;
		  exit(0);
		}
		min = abs((int)a[i]-(int)b[j]) <min? abs((int)a[i]-(int)b[j]) :min;
        }
	}
	cout<<min<<endl;
	return 0; 	
}

