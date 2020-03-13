#include  <iostream> 
#include  <iomanip> 
using  namespace  std;
class Account
{
	public:
		double m =0.00;
		void init (string ID,const char *n,string sex,int age,double cash1);
		void printmoney();
		void deposit(double cash2);
		void withdraw(double cash3);	
	private:
		string ID;
		const char *name;
		string sex;
		int age;
		double money;
 }; 
 void Account::init(string ID,const char *n,string sex,int age,double cash1)
 {
	name=n;
	money=cash1;
 	if((100*money)!=(int)(100*money))
 	{
	 cout<<"������Ľ��Ϸ�"<<endl;
	 money=m ;
      }
 }
 void Account::printmoney()
 {
 	cout<<fixed<<setprecision(2);
	cout<<name<<"�Ĵ��Ϊ"<<money<<endl; 
 }
 void Account::deposit(double cash2)
 {
 	if((100*cash2)!=(int)(100*cash2))
 	cout<<"������Ľ��Ϸ�"<<endl;
 	else money+=cash2;
 }
 void Account::withdraw(double cash3)
 {
 	if((100*cash3)!=(int)(100*cash3))
 	cout<<"������Ľ��Ϸ�"<<endl;
 	else if(cash3>money)
 	cout<<"���Ĵ�����"<<endl;
	 else money-=cash3; 
 }
 
int  main() 
{ 
        Account tom ; 
        tom .init("32020320011001876X", "Tom  Black","��",19, 2000.89); 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom .deposit(89.471);//�����������Ľ��Ϸ� 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom .deposit(10000); 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
        tom .withdraw(10001); 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom .withdraw(10000.123);//�����������Ľ��Ϸ� 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom .withdraw(10000.9);//��������Ĵ����� 
        tom .printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black","Ů", 11, 100.956);//�����������Ľ��Ϸ� 
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
}
