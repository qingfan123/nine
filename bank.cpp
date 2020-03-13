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
	 cout<<"您输入的金额不合法"<<endl;
	 money=m ;
      }
 }
 void Account::printmoney()
 {
 	cout<<fixed<<setprecision(2);
	cout<<name<<"的存款为"<<money<<endl; 
 }
 void Account::deposit(double cash2)
 {
 	if((100*cash2)!=(int)(100*cash2))
 	cout<<"您输入的金额不合法"<<endl;
 	else money+=cash2;
 }
 void Account::withdraw(double cash3)
 {
 	if((100*cash3)!=(int)(100*cash3))
 	cout<<"您输入的金额不合法"<<endl;
 	else if(cash3>money)
 	cout<<"您的存款金额不足"<<endl;
	 else money-=cash3; 
 }
 
int  main() 
{ 
        Account tom ; 
        tom .init("32020320011001876X", "Tom  Black","男",19, 2000.89); 
        tom .printmoney();//输出：Tom  Black的存款为2000.89 
        tom .deposit(89.471);//输出：您输入的金额不合法 
        tom .printmoney();//输出：Tom  Black的存款为2000.89 
        tom .deposit(10000); 
        tom .printmoney();//输出：Tom  Black的存款为12000.89 
        tom .withdraw(10001); 
        tom .printmoney();//输出：Tom  Black的存款为1999.89 
        tom .withdraw(10000.123);//输出：您输入的金额不合法 
        tom .printmoney();//输出：Tom  Black的存款为1999.89 
        tom .withdraw(10000.9);//输出：您的存款金额不足 
        tom .printmoney();//输出：Tom  Black的存款为1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black","女", 11, 100.956);//输出：您输入的金额不合法 
        jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}
