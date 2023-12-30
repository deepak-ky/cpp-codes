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
	int key;
	int value;
	node * next;
	node * prev;

	node(int k, int val)
	{
		key  = k;
		value = val;
		next = NULL;
		prev = NULL;
	}
};


class lru_cache
{
	node * head;
	unordered_map<int, node* > mp;
	int max_size;
	int curr_size;

public:

	lru_cache(int s)
	{
		head = NULL;
		curr_size = 0;
		max_size = s;
	}


	void display_doubly_linked_list()
	{
		node * temp = head;
		while (temp != NULL)
		{
			cout << "{" << temp->key << "," << temp->value << "}" << "->";
			temp = temp->next;
		}
		cout << endl;
	}

	int get(int x)
	{
		if (mp.find(x) == mp.end())
		{
			return -1;
		}
		else
		{
			node * temp = mp[x];
			int ans = temp->value;
			if (temp != head)
			{
				if (temp->prev != NULL)
					temp->prev->next = temp->next;

				if (temp->next != NULL)
					temp->next->prev = temp->prev;

				//Inserting at the head

				temp->next = head;
				temp->prev = NULL;
				if (head != NULL)  head->prev = temp;

				head = temp;
			}

			return ans;
		}
	}

	void remove_lru()
	{
		if (head  == NULL)
		{
			return;
		}

		if (head -> next == NULL)
		{
			node * temp = head;
			head = head->next;
			int k = temp->key;
			mp.erase(k);
			delete temp;
			curr_size--;

			return;

		}
		node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		int k = temp->key;
		mp.erase(k);
		temp->prev->next = NULL;
		delete temp;
		curr_size--;
	}

	void put(int k, int val)
	{


		if (mp.find(k) != mp.end())
		{
			//The key is already present then
			get(k);
			mp[k]->value = val;
			return;
		}
		else
		{
			if (curr_size == max_size)
			{
				remove_lru();
			}
			//If the key is not already present
			node * n = new node(k, val);
			mp[k] = n;
			n->next = head;
			if (head != NULL) head->prev = n;
			head = n;
			curr_size++;
		}
	}


};



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		lru_cache ds(5);
		ds.put(1, 11);
		ds.put(2, 20);
		ds.put(3, 30);
		ds.put(4, 40);
		ds.put(5, 50);
		ds.put(6, 60);
		ds.display_doubly_linked_list();
		cout  << ds.get(4) << endl;
		ds.display_doubly_linked_list();
		ds.put(5, 55);
		ds.display_doubly_linked_list();
		cout  << ds.get(2) << endl;
		ds.display_doubly_linked_list();

		cout  << ds.get(11) << endl;
		ds.display_doubly_linked_list();


		ds.put(11, 45);
		ds.display_doubly_linked_list();
		ds.put(7, 9);
		ds.display_doubly_linked_list();

	}
	return 0;
}
