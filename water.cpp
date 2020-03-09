#include<iostream>
#include<cmath>
using namespace std;
int Recur(int drinks,int lids,int bottles)
{
	lids%=3;bottles%=2;
	lids+=drinks;bottles+=drinks;
	if(lids<3&&bottles<2){
		return drinks;
	}
	else{
		return Recur(lids/3+bottles/2,lids,bottles)+drinks;
	}
	
	
}
int main()
{
	int Recur(int drinks,int lids,int bottles);
	int drinks;
	int lids=0,bottles=0;
	cin>>drinks;
	drinks=Recur(drinks,lids,bottles);
	cout<<drinks;
 } 

  

