#include<iostream>
#include<iomanip>
using namespace std; 
typedef int elementType;
typedef struct node{
	elementType data;
	node* next;
	node(node* ptr=NULL)
	{
		next=ptr;
	}
    node(const int x,node* ptr=NULL)
	{
		data=x;
		next=ptr;
	}
};
class List{
	public:
		List() {first=new node;}
		List(const int x) {first=new node(x);}
		~List() {MakeEmpty(); delete first;}
		void MakeEmpty();
		int Length()const;
		node* Locate(int i);
		bool remove(int i,int& x);
		void insert(int x);
		bool IsEmpty()const
		{
			return first->next==NULL?true:false;
		}
		void print();
		List& operator=(List& L);
	private:
		node* first;
};
void List::MakeEmpty()
{
	node* p;
	while(first->next!=NULL)
	{
		p=first->next;
		first->next=p->next;
		delete p;
	}
}
int List::Length()const
{
	node* p=first->next;
	int length=0;
	while(p!=NULL)
	{
		p=p->next;
		length++;
	}
	return length;
}
node* List::Locate(int i)
{
	if(i<0) return NULL;
	node* p=first->next;
	int k=1;
	while(p!=NULL&&k<i)
	{
		p=p->next;
		k++;
	}
	return p;
}
bool List::remove(int i,int& x)
{
	if(i>Length()) {cout<<"pos>len,failed"<<endl;return false;}
	else if(i<0||i==0) {cout<<"pos<=0,failed"<<endl;return false;}
	node* p=Locate(i-1);
	if(p==NULL||p->next==NULL) return false;
	node* del=p->next;
	p->next=del->next;
	x=del->data;
	delete del;
	return true;
}
void List::insert(int x)
{
	node* p=first;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	node* newNode=new node(x);
	if(newNode==NULL)
	{
		cerr<<"�洢�������!"<<endl;
		exit(1); 
	}
	p->next=newNode;
	newNode->next=NULL;
}
void List::print()
{
	if(IsEmpty())
	{
		cout<<"The list is empty!\n";
		return;
	}
	node* p=first;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->next!=NULL)
		cout<<p->data<<" ";
		else
		cout<<p->data<<"\n";
	}
}
int main(int argc,char *argv[])
{
	List L1;
	int n;
	int val;
	cin>>n;//�������������ݸ���
	for(int i=0;i<n;i++)//����n����������������
	{
		cin>>val ;
		L1.insert(val);
	}
	cout << "Origin Length��" << L1.Length() << endl;//���������
	cout << "data��";
	L1.print();
	cin>>n;//������Ҫɾ�������ݵ�λ��
	if (L1.remove(n,val))			
	{
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }
	return 0;
}
