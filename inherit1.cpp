#include  <iostream> 
using  namespace  std; 
const  float  pi=3.14159; 
class  Shape
{
	private:
		int m_ID;
	public:
		int getArea() { return  0; }
		Shape(int i) 
		{ 
		    m_ID=i;
			cout<<"Shape constructor called:"<<m_ID<<endl; }
		~Shape() { cout<<"Shape destructor called:"<<m_ID<<endl; }
};
class  Circle : public Shape
{
	private:
		int r;
	public:
		int I;
		float getArea() { return pi*r*r; }
		Circle(int n,int i):Shape(i)
		{ 
		    I=i;
		    r=n;
		    cout<<"Circle constructor called:"<<I<<endl; 
		}
		~Circle() { cout<<"Circle destructor called:"<<I<<endl; }
};
class  Rectangle : public Shape
{
	private:
		int h ,w ;
	public:
		int J;
		int getArea() { return h*w ; } 
		Rectangle(int H,int W ,int j):Shape(j)
		{ 
		    J=j;
		    h=H ; w=W ;
			cout<<"Rectangle constructor called:"<<J<<endl;
		}
		~Rectangle() {cout<<"Rectangle destructor called:"<<J<<endl; }
};
int  main() 
{ 
    Shape  s(1);//1��ʾID 
    Circle  c(4,2);//4��ʾ�뾶��2��ʾID 
    Rectangle  r(4,  5,3);//4��5��ʾ���Ϳ�3��ʾID 
    cout<<"Shape�����"<<s.getArea()<<endl; 
    cout<<"Circle�����"<<c.getArea()<<endl; 
    cout<<"Rectangle�����"<<r.getArea()<<endl; 
}

