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

class node
{
public:
	char ch;
	int freq;
	node * left;
	node * right;

	node(char c , int f)
	{
		ch = c;
		freq = f;
		left = NULL;
		right = NULL;
	}

};


class compare
{
public:
	bool operator()(node* const& n1 , node* const& n2)
	{
		if (n1->freq > n2->freq)
		{
			return true;
		}
		else return false;
	}
};


void print_strings(node * n , string curr)
{
	if (n->left == NULL && n->right == NULL)
	{
		cout << n->ch << " : " << curr << endl;
		return;
		//this is an end
	}

	print_strings(n->left, curr + "0");
	print_strings(n->right, curr + "1");
	return;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string s = "abcdef";
		int fre[6] = {5, 9, 12, 13, 16, 45};

		priority_queue<node*, vector<node*>, compare> pq;


		for (int i = 0; i < s.length(); i++)
		{

			node * n = new node(s[i], fre[i]);
			pq.push(n);

		}


		while (pq.size() != 1)
		{

			node * tp1 = pq.top();
			pq.pop();
			node * tp2 = pq.top();
			pq.pop();

			/*if (tp1->ch != '\0')
			{
				cout << tp1->ch << " ";
			}
			else cout << "\0 ";
			cout << tp1->freq << endl;


			if (tp2->ch != '\0')
			{
				cout << tp2->ch << " ";
			}
			else cout << "\0 ";
			cout << tp2->freq << endl;

			cout << endl;*/


			int new_freq = tp1->freq + tp2->freq;

			node * n = new node('\0', new_freq);

			n->left = tp1;
			n->right = tp2;

			pq.push(n);

		}


		print_strings(pq.top(), "");





	}
	return 0;
}
