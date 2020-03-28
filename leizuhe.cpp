#include <iostream >
#include <cmath> 
using namespace std; 
class CPoint
{
	private:
		int x,y;
	public:
		CPoint(int x1=0,int y1=0);
		CPoint(CPoint &c);
		int GetX(){return x;}
		int GetY(){return y;}
}; 
CPoint::CPoint(int x1,int y1)
{
	x=x1;
	y=y1;
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &c)
{
	x=c.x;
	y=c.y;
	cout<<"CPoint copy contstructor is called."<<endl;
}
class CRectangle
{
	private:
		CPoint one;CPoint another;
		int m ,n;
	public:
		CRectangle(CPoint p11,CPoint p22);
		CRectangle(int a1=0,int b1=0,int c1=0,int d1=0);
		CRectangle(CRectangle &r);
		int GetArea();
};
CRectangle::CRectangle(CPoint p11,CPoint p22):one(p11),another(p22)
{
	m =one.GetX()-another.GetX();
	n =one.GetY()-another.GetY();
	
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int a1,int b1,int c1,int d1):one(a1,b1),another(c1,d1)
{
	
	m =one.GetX()-another.GetX();
	n =one.GetY()-another.GetY();
	if(m ==0&n==0)
	cout<<"CRectangle default contstructor is called."<<endl;
	else
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &r):one(r.one),another(r.another)
{
	
	m =one.GetX()-another.GetX();
	n =one.GetY()-another.GetY(); 
	cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle:: GetArea()
{
	return fabs(m *n);	
}

int main() 
{ 
        int a=1, b=1, c=6, d=11; 
        cout<<"# Define p1 ######"<<endl; 
        CPoint p1; 
        cout<<"# Define p2 ######"<<endl; 
        CPoint p2(10,20); 
        cout<<"# Define rect1 ######"<<endl; 
        CRectangle rect1; 
        cout<<"# Define rect2 ######"<<endl; 
        CRectangle rect2(p1,p2); 
        cout<<"# Define rect3 ######"<<endl; 
        CRectangle rect3(a, b, c, d); 
        cout<<"# Define rect4 ######"<<endl; 
        CRectangle rect4(rect2); 
        cout<<"# Calculate area ######"<<endl; 
        cout<< "rect1面积为" << rect1.GetArea() << endl; 
        cout<< "rect2面积为" << rect2.GetArea() << endl; 
        cout<< "rect3面积为" << rect3.GetArea() << endl; 
        cout<< "rect4面积为" << rect4.GetArea() << endl; 
        system ("pause"); 
        return  0; 
} 


