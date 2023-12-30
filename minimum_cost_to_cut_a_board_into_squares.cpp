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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		/*int rows, cols;
		cin >> rows  >> cols;


		int horizontal[rows - 1];
		for (int i = 0; i < rows - 1; i++)
		{
			cin >> horizontal[i];
		}
		int vertical[cols - 1];
		for (int i = 0; i < cols - 1; i++)
		{
			cin >> vertical[i];
		}

		sort(horizontal , horizontal + (rows - 1));
		sort(vertical, vertical + (cols - 1));

		for (auto x : horizontal) cout << x << " "; cout << endl;
		for (auto x : vertical) cout << x << " ";

		int ans = 0;

		int vert_pieces = 1;
		int hori_pieces = 1;

		int i = rows - 2;
		int j = cols - 2;

		 6 4
		2 1 3 1 4
		4 1 2


		*/

		int horizontal[3] = {4, 1, 2};
		int vertical[5] = {2, 1, 3, 1, 4};

		sort(horizontal , horizontal + 3);
		sort(vertical, vertical + 5);

		int ans = 0;

		int vert_pieces = 1;
		int hori_pieces = 1;

		int i = 2;
		int j = 4;

		while (i >= 0 && j >= 0)
		{

			if (horizontal[i] >= vertical[j])
			{
				ans = ans + (horizontal[i] * vert_pieces);
				i--;
				hori_pieces++;
			}
			else
			{
				ans = ans + (vertical[j] * hori_pieces);
				j--;
				vert_pieces++;
			}

		}

		while (i >= 0)
		{
			ans = ans + (horizontal[i] * vert_pieces);
			i--;
			hori_pieces++;

			//wer(ans);


		}


		while (j >= 0)
		{

			ans = ans + (vertical[j] * hori_pieces);
			j--;
			vert_pieces++;

			//wer(ans);

		}

		cout << ans << endl;
	}
	return 0;
}
