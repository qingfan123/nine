#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using namespace std; 
const double PI=3.1415926;
class cylinder
{
	private:
		double r,h;
	public:
		double volumn,area;
		cylinder (double hi,double ri);
		~cylinder();
		double getvolumn();
		double getarea();
}; 
 cylinder::cylinder (double hi,double ri)
{
	h=hi;
	r=ri;
	cout<<"构造函数被调用"<<endl; 
}
 cylinder::~cylinder ()
 {
 	cout<<"析构函数被调用"<<endl; 
  } 
double cylinder::getvolumn()
{
    
	volumn= PI*r*r*h;
	return volumn;
	cout<<volumn<<endl;
	
}
double cylinder::getarea()
{
	area=2*PI*r*r+2*PI*r*h;
    return area;
}
int main() 
{ 
        double  d,h; 
        cin>>d>>h; 
        cylinder can(h,d/2); 
        cout<<fixed<<setprecision(6); 
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl; 
        cout<<"铁皮的面积是"<<can.getarea()<<endl; 
		system("pause");
}