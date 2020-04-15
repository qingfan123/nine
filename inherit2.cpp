#include  "iostream" 
using  namespace  std; 
class  vehicle
{
	private:
		int maxspeed,weight;
	public:
		void run() { cout<<"vehicle run"<<endl; }
		void stop() { cout<<"vehicle stop"<<endl;}
		vehicle(int m ,int w )
		{ 
		    maxspeed=m ; weight=w ;
		    cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
		}
		~vehicle() 
		{
			cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
		}
};
class  bicycle :virtual public  vehicle
{
	private:
		int height;
	public:
		bicycle(int m ,int w ,int h) :vehicle(m ,w ) 
		{
			height=h;
			cout<<"bicycle constructor called. height:"<<height<<endl;
		}
		~bicycle() 
		{
			cout<<"bicycle destructor called. height:"<<height<<endl;
		}
};
class  motorcar :virtual public  vehicle
{
	private:
		int seatnum ;
	public:
		motorcar(int m ,int w ,int s) :vehicle(m ,w ) 
		{
			seatnum =s;
			cout<<"motorcar constructor called. seatnum:"<<seatnum <<endl;
		}
		~motorcar() 
		{
			cout<<"motorcar destructor called. seatnum:"<<seatnum <<endl;
		}
};
class  motorcycle :public bicycle,public motorcar
{
	public:
		motorcycle(int h,int s,int m ,int w ):vehicle(m ,w ),bicycle(m ,w ,h),motorcar(m ,w ,s)
		{
			cout<<"motorcycle constructor called"<<endl;
		}
		~motorcycle()
		{
			cout<<"motorcycle destructor called"<<endl;
		}
};

int  main(int  argc,  char  *argv[]) 
{ 
    motorcycle m (1,2,3,4);//1��ʾheight��2��ʾsetnum��3��ʾmaxspeed��4��ʾweight 
    m .run(); 
    m .stop(); 
    return  0; 
}
