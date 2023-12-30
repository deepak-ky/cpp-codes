#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include "hashtable2.h"
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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	Hashtable<int> menu_price;
	menu_price.insert("Burger", 120);
	menu_price.insert("Pepsi", 20);
	menu_price.insert("BurgerPizza", 150);
	menu_price.insert("Noodles", 25);
	menu_price.insert("Coke", 40);
	menu_price.print();

	int *price = menu_price.search("Noodls");
	if (price == NULL)
	{
		cout << "NOT FOUND";
	}
	else
	{
		cout << "Price is " << *price << endl;
	}
	//menu_price.erase("BurgerPizza");
	cout << endl;
	menu_price.print();
	return 0;
}
