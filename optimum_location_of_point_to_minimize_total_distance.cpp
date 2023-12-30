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
#define se                            second

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

class point
{
public:
	double x_coord;
	double y_coord;
};

class line
{
public:
	double a;
	double b;
	double c;
};

double distance_between_two_points(double x1, double y1, double x2, double y2)
{
	double p1 = pow( (x1 - x2) , 2);
	double p2 = pow( (y1 - y2) , 2);

	double p = p1 + p2;

	return sqrt(p);
}

double find_distance(line l, point p[], int num_of_points , double x)
{

	//distance between two point (x1,y1) and (x2,y2) is given by :
	// sqrt( ( x1 - x2)^2 + (y1 - y2)^2 );


	double y = (l.c + (l.a * x));
	y = y / l.b;
	y = -y;

	double res = 0;
	for (int i = 0; i < num_of_points; i++)
	{
		res += distance_between_two_points(x, y, p[i].x_coord, p[i].y_coord);
	}


	return res;
}

double solve(line l, point p[], int num_of_points)
{
	//Going to use ternary serach
	double low = -1e6;
	double high = 1e6;

	while (high - low > (1e-6))
	{
		double mid1 = low + ((high - low) / 3);
		double mid2 = high - ((high - low) / 3);

		// here mid1 and mid2 are the two x - coordinates of the points I have chosen
		// to be my suitable answer , I would find y - coordinates by putting them
		// in the equation.

		double dist1 = find_distance(l, p, num_of_points, mid1);
		double dist2 = find_distance(l, p, num_of_points, mid2);

		if (dist1 < dist2)
		{
			high = mid2;
		}
		else low = mid1;
	}

	double w = (high + low) / 2;

	cout << "x_coord of ans :  " << w << endl;
	double y = (l.c + (l.a * w));
	y = y / l.b;
	y = -y;
	cout << "y_coord of ans :  " << y << endl;
	cout << endl;
	cout << "The minimum distance of all the points from the line is : ";


	return find_distance(l, p, num_of_points, w);


}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		line l;

		cin >> l.a;
		cout << "Enter x coeff of the line : " << l.a << endl;
		cin >> l.b;
		cout << "Enter y coeff of the line : " << l.b << endl;
		cin >> l.c;
		cout << "Enter the c variable : " << l.c << endl;

		//There would be a list of points

		int num_of_points;
		cin >> num_of_points;

		point p[num_of_points];

		for (int i = 0; i < num_of_points; i++)
		{
			double u, r;
			cin >> u >> r;
			p[i].x_coord = u;
			p[i].y_coord = r;
		}


		cout << endl << endl;

		cout << solve(l, p, num_of_points);

	}
	return 0;
}
