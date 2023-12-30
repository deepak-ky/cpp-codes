#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	float f = 0;
	float rating;
	cout << "Enter the rating of the 14 Factors : ";
	cout << "\nThe ratings are : ";
	cout << "\n0--> No Influence";
	cout << "\n1--> Incidental";
	cout << "\n2--> Moderate";
	cout << "\n3--> Average";
	cout << "\n4--> Significant";
	cout << "\n5--> Essential";
	for (int i = 0; i < 14; i++)
	{
		cin >> rating;
		f = f + rating;
	}
	cout << "\nF is : " << f;
	float CAF;
	CAF = 0.65 + (0.01 * f);
	cout << "\nCAF is : " << CAF;
	int weights[5][3] = {3, 4, 6, 4, 5, 7, 3, 4, 6, 7, 10, 15, 5, 7, 10};
	char func_units[][30] = {"External Inputs", "External Outputs", "External Enquiries", "Internal Logical Files", "External Interface Files"};
	cout << "\nEnter the rating of Function Units : ";
	cout << "\n0-->Low";
	cout << "\n1-->Average";
	cout << "\n2-->High";
	float UFP = 0;
	char complex[3][10] = {"Low", "Average", "High"};
	for (int i = 0; i < 5; i++)
	{
		float value;
		cout << "\nEnter the value of " << func_units[i] << " : ";
		cin >> value;
		int rate;
		cout << "\nEnter the rating of " << func_units[i] << " : ";
		cin >> rate;
		UFP = UFP + (value * (rate * weights[i][rate]));
	}
	cout << "\nUFP is : " << UFP;
	cout << "\nFunction Point Value is " << (CAF + UFP);
	return 0;
}
