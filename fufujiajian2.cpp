#include  <iostream> 
using  namespace  std; 
class Complex
{
	private:
		double real;
		double image;
	public:
		Complex() {real=0;image=0;}
		Complex(double r,double i) { real=r; image=i;}
		Complex (double r) { real=r, image=0; }
		Complex (int r) {real=r, image=0; }
		friend Complex operator+(Complex a, Complex b);
		friend Complex operator-(Complex a, Complex b);
		
		void print() { cout<<real<<"+"<<image<<"i"<<endl; }
}; 
Complex operator+(Complex a, Complex b)
{
	return Complex(a.real+b.real, a.image+b.image);
}
Complex operator-(Complex a, Complex b)
{
	return Complex(a.real-b.real, a.image-b.image);
}
int  main() 
{ 
        Complex  a(3,4),b(1,-1),c; 
        c=a+b; 
        cout<<"a+b="; 
        c.print(); 
        cout<<endl; 
        c=a-b; 
        cout<<"a-b="; 
        c.print(); 
        cout<<endl; 
        c=a+100; 
        cout<<"a+100="; 
        c.print(); 
        cout<<endl; 
        c=a-2.5; 
        cout<<"a-2.5="; 
        c.print(); 
        cout<<endl; 
        return  0; 
} 

