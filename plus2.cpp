#include<iostream>
#include<iomanip>
using namespace std;

struct complex
{
	double r;
	double i;
 };
 complex add(complex a,complex b);
 complex add(complex a,double num);
 complex add(double num,complex b);
 complex add(complex a,complex b)
 {
 	complex d;
 	d.r=a.r+b.r;
 	d.i=a.i+b.i;
 	return d;
 }
 complex add(complex a,double num)
 {
 	complex d;
 	d.r=a.r+num;
 	d.i=a.i;
 	return d;
 }
 complex add(double num,complex b)
 {
 	complex d;
 	d.r=b.r+num;
 	d.i=b.i;
 	return d;
 }
 int main()
 {
 	double num ;
 	complex a,b,c;
 	cin>>a.r>>a.i;
 	cin>>b.r>>b.i;
 	cin>>num ;
 	c =add(a,b);
 	cout<<c.r<<"+"<<c.i<<"i"<<endl;
 	c =add(a,num);
 	cout<<c.r<<"+"<<c.i<<"i"<<endl;
 	c =add(num,b);
 	cout<<c.r<<"+"<<c.i<<"i"<<endl;
  } 
 
