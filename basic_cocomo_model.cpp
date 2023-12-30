#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int fround(float x)
{
	return int(x + 0.5);
}
int main()
{

	float e, t, s, p;
	float values[3][4] = {2.4, 1.05, 2.5, 0.38, 3.0, 1.12, 2.5, 0.35, 3.6, 1.20, 2.5, 0.32};
	int KLOC, model_no;
	char model_type[][100] = {"Organic", "Semi-Detached", "Embedded"};
	cout << "Enter size of project  : ";
	cin >> KLOC;
	if (KLOC >= 2 && KLOC <= 50)
		model_no = 0;
	else if (KLOC > 50 && KLOC <= 300)
		model_no = 1;
	else if (KLOC > 300)
		model_no = 2;
	cout << "\nThe mode is " << model_type[model_no];
	e = values[model_no][0] * pow(KLOC, values[model_no][1]);
	t = values[model_no][2] * pow(e, values[model_no][3]);
	s = e / t;
	cout << "\nEffort = " << e << " Person-Month";
	cout << "\nDevelopment Time = " << t << " Months";
	cout << "\nAverage Staff Required = " << fround(s) << " Persons";
	return 0;
}
