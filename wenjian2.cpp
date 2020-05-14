#include<iostream>
using namespace std;
#include<cmath>

int main()

{
  double P;
  double R=0.02708;
  double N;
  double sum ;

  cout<<"请输入贷款本金\n"<<endl;

  cin>>P;
  
  cout<<"请输入还款期数\n"<<endl;
  cin>>N;
  
  sum=(P*R*pow((1+R),N))/(pow((1+R),N)-1);
  cout<<"所求还款总额为："<<sum <<endl;
  
  return 0;

}
