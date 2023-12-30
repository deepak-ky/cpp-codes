#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                           long long
#define ab(a)                        (a<0)?(-1*a):a
#define faster                       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define present(container, x)        container.find(x) != container.end()
#define watch(x)                     cout << (#x) << " is " << (x) << endl
#define mod                          1000000007
#define inf                          1e18
class car
{

	int price;
public:
	int model;

	string name;
	const int tyres;
	car(): tyres(4)
	{

	}
	car(const int a, int b, string n, int t = 4): tyres(t) // b and n can also be made constants
	{
		price = a;
		model = b;
		name = n;
	}
	car(const car &x): tyres(x.tyres)
	{
		cout << "\nCreating a copy constructor once : ";
		price = x.price;
		model = x.model;
		name = x.name;
	}

	void showdetails()const
	{
		cout << "model : " << model << endl;
		cout << "price: " << price << endl;

		cout << "name : " << name << endl;

	}
	void setpriec(const int p)
	{
		if (p > 1000)
		{
			price = p;
		}
		else price = 1000;
	}
	void getprice()const
	{
		cout << price;
	}
	~car()
	{
		cout << "\ndeleting car : " << name;
	}



};
int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	car c;
	c.model = 1;

	c.name = "mycar";
	c.setpriec(500);
	c.getprice();
	car d(12, 120, "audi");
	d.showdetails();
	car e(d);
	e.showdetails();
	car f = d;
	f.setpriec(1900);
	f.showdetails();
	cout << endl << endl;
	car g(900, 78, "safari");
	car h(800, 79, "fortuner");

	//g = h;
	g.name[0] = 'h';
	g.showdetails();
	h.showdetails();
	cout << endl << h.tyres;
	cout << endl << e.tyres;


	car *dc = new car(900, 78, "tesla cars");
	delete dc;

	return 0;
}