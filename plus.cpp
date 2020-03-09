#include<iostream>
using namespace std;
#include<iomanip>
typedef struct
{
	float real;
	float imag;
}complex;
float a=0,b=0;
void complex_sup()
{
	complex z1,z2;
	cin>>z1.real>>z1.imag;
	cin>>z2.real>>z2.imag;
	a=z1.real-z2.real;
	b=z1.imag-z2.imag;
 } 
 int main()
 {
 	complex_sup();
 	cout<<endl;
 	cout<<fixed<<setprecision(2)<<a<<' '<<fixed<<setprecision(2)<<b;
 	return 0;
 }

