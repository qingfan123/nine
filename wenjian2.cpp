#include<iostream>
using namespace std;
#include<cmath>

int main()

{
  double P;
  double R=0.02708;
  double N;
  double sum ;

  cout<<"����������\n"<<endl;

  cin>>P;
  
  cout<<"�����뻹������\n"<<endl;
  cin>>N;
  
  sum=(P*R*pow((1+R),N))/(pow((1+R),N)-1);
  cout<<"���󻹿��ܶ�Ϊ��"<<sum <<endl;
  
  return 0;

}
