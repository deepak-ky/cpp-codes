// CPP program to illustrate
// usage of global variables
#include<iostream>
using namespace std;

// global variable
int global = 5;

// global variable accessed from
// within a function
void subsequences(char *a, char *b, int i, int j)
{
	//Rec Case
	if (a[i] == '\0')
	{
		b[j] = '\0';
		cout << b << endl;
		++global;
		return;
	}
	b[j] = a[i];
	subsequences(a, b, i + 1, j + 1);
	subsequences(a, b, i + 1, j);
}
void display()
{
	cout<<global<<endl;
}

// main function
int main()
{
	display();

	// changing value of global
	// variable from main function
	global = 10;
	display();
	cout<<"\nThe value of global here is : "<<global;
}

