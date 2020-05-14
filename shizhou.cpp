#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ifstream is("a.txt");
	ofstream os("b.txt");
	vector<float> data;
	float t;
	if(!is)
	       cout<<"cannot open file a.txt"<<endl;
	else
	{
		while(is.good())
		{
			is>>t;
			data.push_back(t);
		}
		sort(data.begin(),data.end());
		if(!os)
		{
			cout<<"cannot open file b.txt"<<endl;
		}
		else
		{
			for(unsigned int i=0;i<data.size()&&os.good();i++)
			{
				os<<data[i]<<" ";
			}
			os.close();
		}
		is.close();
	}
	system("pause");
}
