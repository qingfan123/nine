#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using  namespace  std; 
const  double  PI=3.1415926;
class cylinder
{
	private:
		double r,h;
	public:
		double volumn,area,PI=3.1415926;
		void init(double hi,double ri);
		double getvolumn();
		double getarea();
}; 
 void cylinder::init(double hi,double ri)
{
	h=hi;
	r=ri;
	
}
double cylinder:: getvolumn()
{
	volumn=PI*r*r*h;
	return volumn;
	
}
double cylinder:: getarea()
{
	area=2*PI*r*r+2*PI*r*h;
	return area;
    
}
int  main() 
{ 
        double  d,h; 
        cin>>d>>h; 
        cylinder can;
        can.init(h,d/2); 
        cout<<can.getvolumn()<<endl;
        cout<<fixed<<setprecision(6); 
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl; 
        cout<<"铁皮的面积是"<<can.getarea()<<endl; 
} 
