#include<iostream>
using namespace std;

void towerofhanoi(int n, char src, char dest, char helper)
{
	if (n == 0)
	{return;}
	towerofhanoi(n - 1, src, helper, dest);
	cout << "Move " << n << " disk from " << src << " to " << dest << endl;
	towerofhanoi(n - 1, helper, dest, src);
}
int main()
{
//#ifndef ONLINE_JUDGE
//	// for getting input from input.txt
//	freopen("input.txt", "r", stdin);
//	// for writing output to output.txt
//	freopen("output.txt", "w", stdout);
//#endif


	int n;
	cin >> n;
	towerofhanoi(n, 'A', 'B', 'C');
	return 0;
}
