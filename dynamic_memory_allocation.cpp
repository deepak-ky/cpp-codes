#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//static allocation - allocation + deallocation -> by compiler
	int a[100] = {0};//to set all elements = 0 , do a[100] = {0};
	cout << sizeof(a);
	cout << " : " << "starting address : " << a << " : "; //from symbol table read only cannot be
	//cannot be overwritten
	cout << endl;


	//dynamic allocation - allocation + deallocation ->by programmer
	//allocation
	int *b;
	b = new int[100];//to set all elements = 0 , do b = new int[100]{0};
	cout << sizeof(b);
	cout << " : " << "starting address : " << b << " : "; //address stored in
	// b pointer in static memory can be overwritten
	// b = new char[30] ->this operation can be performed
	delete [] b;






	return 0;
}
