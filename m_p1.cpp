#include <iostream>
using  namespace  std;
class  Book
{
public:
    void SetID(int n);
    void SetName(string n);
    void SetAuthor(string n);
    void SetIntroduction(string n);          //请在此处补充Book类的定义
    void SetDate(string n);
    void SetPage(int n);
    Book(const Book& b);
    int GetID();
    string GetAuthor();
    string GetName();
    string GetDate();
    Book();
    ~Book();
private:
    unsigned int m_ID;//编号
    string m_Name;//书名
    string m_Introductio;//简介
    string m_Author;//作者
    string m_Date;//日期
     int m_Page;//页数

};
//请在此处补充Book类的成员函数实现
void Book::SetPage(int n)
{
    m_Page = n;
}
void Book::SetID(int n)
{
    m_ID = n;
}
void Book::SetName(string n)
{
    m_Name = n;
}                                     
void Book::SetAuthor(string n)
{
    m_Author = n;
}
void Book::SetIntroduction(string n)
{
    m_Introductio = n;
}
void Book::SetDate(string n)
{
    m_Date = n;
}                            //set-6
int Book::GetID()
{
    return m_ID;
}
string Book::GetName()
{
    return m_Name;
}
string Book::GetAuthor()
{
    return m_Author;
}
string Book::GetDate()
{
    return m_Date;
}                            //get-4
Book::Book()
{
    m_ID = 0;
    m_Page = 0;
}
Book::Book(const Book& b)
{
    m_ID = b.m_ID;//编号 
    m_Name = b.m_Name;//书名
    m_Introductio = b.m_Introductio;//简介
    m_Author = b.m_Author;//作者
    m_Date = b.m_Date;//日期
    m_Page = b.m_Page;//页数 
}
Book::~Book()
{

}
class  Store
{
   public:
   	Store();//构造函数 1
    Store(int n);//构造函数2 
    virtual ~Store();//析构函数 
    Store(const Store& other);//拷贝构造函数（深拷贝） 
    void in(Book& b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void GetID();
    int  GetCount();
    void printList();
private:
    Book* m_pBook;
    int m_Count;
    Book* book1;                               
 
};
//请在此处补充Store类的定义
Store::Store()
{
    m_Count = 0;
    m_pBook = 0;
    book1 = 0;
    cout << "Store default constructor called!" << endl;
}
Store::Store(int n)
{
    m_Count = n;
    m_pBook = new Book[n];
    book1 = 0;
    cout << "Store constructor with (int n) called!" << endl;
}
Store::~Store()
{
    m_Count = 0;
    book1 = 0;
    cout << "Store destructor called!" << endl;
    if (m_pBook != NULL)
        { delete[] m_pBook; }
}
Store::Store(const Store& p)
{
    m_pBook = p.m_pBook;
    m_Count = p.m_Count;
    book1 = p.book1;
}
int Store::GetCount()
{
    return m_Count;
}
void Store::in(Book& b)
{
    int i=0;
    book1 = new Book[m_Count + 1];
    for ( i = 0; i < m_Count; i++)
    {
        book1[i] = m_pBook[i];
    }
    book1[i] = b;
    m_pBook = book1;
    m_Count = m_Count + 1;
} 
void Store::out(string name)
{
    int i = 0;
    book1 = new Book[m_Count - 1];
    for ( i = 0; i < m_Count - 1; i++)
    {
        if (m_pBook[i].GetName() == name)
        {
            book1[i] = m_pBook[i +1];
        }
        else
        {
            book1[i] = m_pBook[i];
        }
    }
    m_pBook = book1;
    m_Count = m_Count - 1;


}
Book Store::findbyID(int ID)
{
    Book book2;
    for (int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetID() == ID)
        {
            return m_pBook[i];
            break;
        }

    }
    return book2;
}                                                    
Book Store::findbyName(string name)
{
    
    Book book1;
    for (int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetName() == name)
        {
            return m_pBook[i];
            break;
        }
    }
    return book1;
}
void Store::printList()
{
	int i;
    cout<<"There are totally "<< m_Count <<" Books:"<<endl;
    for(int i = 0; i < m_Count; i++)
    {
        if (m_pBook[i].GetID() != 0)
            cout << "ID=" << m_pBook[i].GetID() << ";  " << "Name:" << m_pBook[i].GetName() << ";  " << "Author:" << m_pBook[i].GetAuthor() << ";  " << "Date:" << m_pBook[i].GetDate() << ";  " << endl;
    }
}
int  main()
{
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "第一本书入库" << endl;
    s.in(b1);
    cout << "第二本书入库" << endl;
    s.in(b2);
    cout << "第三本书入库" << endl;
    s.in(b3);
    cout << "现有库存书籍数量：" << s.GetCount() << endl;
    cout << "查找并出库图书：离散数学" << endl;
    Book  tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
    {
        s.out("离散数学");
        cout << "离散数学  已成功出库" << endl;
    }
    else
        cout << "没有找到name为离散数学的书" << endl;
    cout << "现有库存书籍数量：" << s.GetCount() << endl;

    cout << "查找图书  ID：3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
    else
        cout << "没有找到ID为" << 3 << "的书" << endl;

    cout << "查找图书  name：离散数学" << endl;
    tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
        cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
    else
        cout << "没有找到name为离散数学的书" << endl;

    cout << "输出所有库存图书的信息" << endl;
    s.printList();
    cout << "程序运行结束" << endl;
    return  0;
}

