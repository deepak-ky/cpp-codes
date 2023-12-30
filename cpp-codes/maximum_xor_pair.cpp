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
class node
{
public:
	int data;
	node* left; //represents zero
	node* right; //represents zeo
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
class trie
{
public:
	node * root;
	trie()
	{
		root = new node('\0');
	}
	void insert(int w)
	{
		node * temp = root;
		for (int i = 31; i >= 0; i--)
		{
			int ch;
			int bit = (w >> i) & 1;
			if (bit == 1) ch = 1;
			else ch = 0;
			if (ch == 0)
			{
				if (temp -> left == NULL)
				{
					node * n = new node(0);
					temp->left = n;
					temp = n;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if (ch == 1)
			{
				if (temp -> right == NULL)
				{
					node * n = new node(1);
					temp->right = n;
					temp = n;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
	int max_xor_pair(int n)
	{
		node * temp = root;
		int curr_xor = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (n >> i) & 1;
			if (bit == 0)
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
					curr_xor += (pow(2, i));
				}
				else temp = temp->left;
			}
			else if (bit == 1)
			{
				if (temp->left != NULL)
				{
					temp = temp->left;
					curr_xor += (pow(2, i));

				}
				else temp = temp->right;
			}
		}
		return curr_xor;
	}

};
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	trie t;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	/*int w = 3 ^ 4;
	cout << endl << w << endl;*/

	t.insert(a[0]);
	int max_xor = INT_MIN;
	for (int i = 1; i < n; i++)
	{

		int w = t.max_xor_pair(a[i]);
		//cout << i << " : " << j << " : ";
		//wer(w) << endl;
		max_xor = max(max_xor, w);

		t.insert(a[i]);
	}
	cout << max_xor << endl;

	return 0;
}
