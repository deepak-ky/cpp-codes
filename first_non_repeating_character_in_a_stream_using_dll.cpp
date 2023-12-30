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
	char data;
	node * next;
	node * prev;

	node(char d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insert_at_head(node *& head, char d)
{
	node * n = new node(d);
	n->next = head;
	if (head != NULL)
		head->prev = n;
	n->prev = NULL;
	head = n;
}

void insert_at_tail(node *& head, char d)
{
	if (head == NULL)
	{
		insert_at_head(head, d);
		return;
	}

	node * last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	node * n = new node(d);

	last->next = n;
	n->next = NULL;
	n->prev = last;
	return;

}

void print_list(node * head)
{
	if (head == NULL)
	{
		return;
	}

	cout << "Forward  : ";

	node * temp = head;
	while (temp->next != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";

	cout << endl;
	cout << "Backward : ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}

	cout << endl;
}

void non_repeating_char(node * head)
{
	unordered_map<char, node*> crps_node;
	unordered_map<char, bool>  is_repeated;

	node * ans = NULL;

	node * temp = head;
	node * last = head;
	while (temp != NULL)
	{
		char ch = temp->data;

		cout << "Character here is : " << ch << endl;




		if (is_repeated[ch] == false)
		{

			if (crps_node[ch] == NULL)
			{
				//This character has been seen the first time
				if (ans == NULL)
				{
					node * n = new node(ch);
					n->next = ans;
					n->prev = NULL;
					ans = n;
					last = n;
				}
				else
				{
					node * n = new node(ch);
					last->next = n;
					n->next = NULL;
					n->prev = last;
					last = n;
				}

				crps_node[ch] = last;

			}
			else
			{
				//The character has already been present once


				node * to_delete = crps_node[ch];
				is_repeated[ch] = true;
				crps_node[ch] = NULL;


				if (to_delete->next == NULL && to_delete->prev == NULL)
				{
					cout << "Case 1" << endl;

					ans = ans->next;
					//ans->prev = NULL;
					delete to_delete;
					last = ans;
				}
				else if (to_delete->next == NULL)
				{
					cout << "Case 2" << endl;

					last = to_delete->prev;
					to_delete->prev->next = NULL;
					delete to_delete;
				}
				else if (to_delete->prev == NULL)
				{
					cout << "Case 3" << endl;

					ans = to_delete->next;
					//last = ans;
					to_delete->next->prev = NULL;
					delete to_delete;
				}
				else
				{
					cout << "Case 4" << endl;

					to_delete->prev->next = to_delete->next;
					to_delete->next->prev = to_delete->prev;
					delete to_delete;
				}


			}

		}

		temp = temp->next;


		print_list(ans);
		//wer(last->data);



		if (ans == NULL)
		{
			cout << "-1 ";
		}
		else cout << ans->data << " ";

		cout << endl;

	}
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a = "jsrjwititawljlkds";

		node * head = NULL;

		for (int i = 0; i < a.length(); i++)
		{
			insert_at_tail(head, a[i]);
		}





		non_repeating_char(head);

	}
	return 0;
}
