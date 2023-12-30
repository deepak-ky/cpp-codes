#include<iostream>
using namespace std;
class student
{
	char name;
	int roll;
	int perc;
public:
	void getdata(void)
	{
		cout << "Enter name : ";
		cin >> name;
		cout << "Enter roll : ";
		cin >> roll;
		cout << "Enter perc : ";
		cin >> perc;
	}
	void p(void)
	{
		cout << "Name : " << name << endl;
		cout << "Roll No. : " << roll << endl;
		cout << "perc : " << perc << endl;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	student s1;
	s1.getdata();
	s1.p();

	return 0;
}
