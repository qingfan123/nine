#include  <iostream> 
#include  <string> 
using  namespace  std; 

class  CStudent
{
	private:
		const char *name;
		int age;
	public:
		static int count;
		static int getcount();
		CStudent()
		{
			name="noname";
			cout<<"noname is contructing"<<endl;
			count++;
			
		}
		CStudent(const char*n,int Age)
		{
			name=n;
			cout<<name<<' '<<"is contructing"<<endl;
			count++;
		}
		char printname()
		{
			cout<<"name:"<<name<<endl;
		}
		~CStudent()
		{
			cout<<name<<' '<<"is destructing"<<endl;
			count--;
		 } 
		
};

//���������ʼ��̬��Ա���� 
 int CStudent::count=0;
int CStudent::getcount()
 {
 	return count;
 }


int  main() 
{ 
    cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
    { 
        CStudent stuB[5]; 
        stuB[4].printname(); 
        cout << "������ѧ��" << CStudent::getcount() << endl; 
    } 
        cout << "������ѧ��" << CStudent::getcount() << endl; 
    { 
        CStudent stuA[2]= {CStudent("Tom",3),CStudent("Jerry",2)}; 
        for (int i=0; i<2; i++) 
        { 
            stuA[i].printname(); 
        } 
        cout << "������ѧ��" << CStudent::getcount() << endl; 
    } 
    cout << "������ѧ��" << CStudent::getcount() << endl; 

    return 0; 
}


