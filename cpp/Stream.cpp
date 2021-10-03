#include <fstream>
using namespace std;
int main()
{
	ofstream outf("student");
	int no;
	char name[30];
	cout<<"Enter Roll Number:-\n";
	cin>>no;
	cout<<"Enter Name:-\n";
	cin>>name;
	outf<<no<<endl;
	outf<<name<<endl;
	outf.close();
	ifstream inf("student");
	inf>>no;
	inf>>name;
	cout<<"\n Roll Number is "<<no<<endl;
	cout<<"\n Name is "<<name<<endl;
	inf.close();
	return 0;
}
