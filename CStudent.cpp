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

//请在这里初始静态成员变量 
 int CStudent::count=0;
int CStudent::getcount()
 {
 	return count;
 }


int  main() 
{ 
    cout<<"现在有学生"<<CStudent::getcount()<<endl; 
    { 
        CStudent stuB[5]; 
        stuB[4].printname(); 
        cout << "现在有学生" << CStudent::getcount() << endl; 
    } 
        cout << "现在有学生" << CStudent::getcount() << endl; 
    { 
        CStudent stuA[2]= {CStudent("Tom",3),CStudent("Jerry",2)}; 
        for (int i=0; i<2; i++) 
        { 
            stuA[i].printname(); 
        } 
        cout << "现在有学生" << CStudent::getcount() << endl; 
    } 
    cout << "现在有学生" << CStudent::getcount() << endl; 

    return 0; 
}


