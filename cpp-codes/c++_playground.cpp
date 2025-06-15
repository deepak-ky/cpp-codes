#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		/*int a = 23;
		int *a1 = &a;

		cout << "a : " << a << endl;
		cout << "a1 : " << a1 << endl;

		cout << "&a : " << &a << endl;

		cout << "*a1 : " << *a1 << endl;
		cout << "&a1 : " << &a1 << endl;*/

		/*int newArr[2] = {10,20};

		cout << "newArr : " << newArr << endl;
		cout << "*newArr : " << *newArr << endl;
		cout << "*(newArr + 4) : " << *(newArr + 4) << endl;
		cout << "newArr[0] : " << newArr[0] << ", newArr[1] : " << newArr[1] << endl;*/


		int arr[2] = {10,15};

		cout << "arr[0] : " << arr[0] << endl;
 		cout << "arr[1] : " << arr[1] << endl;

 		cout << endl;

 		cout << "&arr[0] : " << &arr[0] << endl;
 		cout << "&arr[1] : " << &arr[1] << endl;

 		cout << endl;

 		cout << "arr : " << arr << endl;
 		cout << "&arr : " << &arr << endl;

 		cout << endl;

 		int *arrPointer;

 		cout << "arrPointer : " << arrPointer << endl;
 		cout << "&arrPointer : " << &arrPointer << endl;

 		cout << endl;
 		arrPointer = arr;
 		cout << "After (arrPointer = arr) => " << endl;

 		cout << "arrPointer : " << arrPointer << endl;
 		cout << "&arrPointer : " << &arrPointer << endl;

 		cout << endl;

 		cout << "arrPointer[0] : " << arrPointer[0] << endl;
 		cout << "arrPointer[1] : " << arrPointer[1] << endl;

 		cout << endl;

 		cout << "*arrPointer : " << *arrPointer << endl;
 		cout << "*(arrPointer+1) : " << *(arrPointer + 1) << endl;
 		arrPointer++;
 		cout << "*arrPointer : " << *arrPointer << endl;


		
		



	}
	return 0;
}
