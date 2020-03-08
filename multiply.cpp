#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],c[3][3];
	int i,j,k;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	cin>>a[i][j];
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	cin>>b[i][j];
	for(k=0;k<3;k++){
	   c[0][k]=a[0][0]*b[0][k]+a[0][1]*b[1][k]+a[0][2]*b[2][k];
	   cout<<c[0][k]<<' ';
	}
	cout<<endl;
	for(k=0;k<3;k++){
	   c[1][k]=a[1][0]*b[0][k]+a[1][1]*b[1][k]+a[1][2]*b[2][k];
	   cout<<c[1][k]<<' ';
	}
	cout<<endl;
	for(k=0;k<3;k++){
	   c[2][k]=a[2][0]*b[0][k]+a[2][1]*b[1][k]+a[2][2]*b[2][k];
	   cout<<c[2][k]<<' ';
	}
	return 0;
 } 
