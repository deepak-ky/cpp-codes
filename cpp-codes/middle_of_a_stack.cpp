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

	int data;
	node * prev;
	node * next;

	node(int n)
	{
		data = n;
		prev = NULL;
		next = NULL;
	}
};


class Stack
{
	int size;
	node * head;
	node * mid;
public:
	Stack()
	{
		size = 0;
		head = NULL;
		mid = NULL;
	}

	void push(int x)
	{
		node * n = new node(x);
		if (head == NULL)
		{
			n->next = head;
			n->prev = NULL;
			head = n;


			mid = head;
			size += 1;
		}
		else
		{
			n->next = head;
			head->prev = n;
			n->prev = NULL;
			head = n;

			size += 1;
			if (size & 1)
			{
				mid = mid->prev;
			}
		}
	}

	int pop()
	{
		if (head == NULL)
		{
			cout << "Stack is empty \n";
			return -1;
		}
		else if (head->next == NULL)
		{
			int d = head->data;
			node * temp = head;
			head = head->next;
			delete temp;

			mid = NULL;
			size = 0;

			return d;
		}
		else
		{
			int d = head->data;
			node * temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;

			size -= 1;
			if (size % 2 == 0)
			{
				mid = mid->next;
			}

			return d;


		}
	}


	int mid_element()
	{
		if (mid == NULL)
		{
			return -1;
		}
		else return mid->data;
	}

	void delete_at_mid()
	{
		if (mid == NULL)
		{
			return;
		}
		else if (size == 1)
		{
			int w = pop();
			return;
		}
		else if (size == 2)
		{
			node * temp = mid;
			mid = mid->prev;
			mid->next = temp->next;
			delete temp;
			size -= 1;
		}
		else if (size >= 3)
		{
			if (size & 1)
			{
				node * temp = mid;
				mid = mid->next;
				temp->prev->next = mid;
				mid->prev = temp->prev;
				delete temp;
			}
			else
			{
				node * temp = mid;
				mid = mid->prev;
				mid->next = temp->next;
				temp->next->prev = mid;
				delete temp;
			}

			size -= 1;
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
		Stack s;
		s.push(11);
		s.push(22);
		s.push(33);
		s.push(44);
		s.push(55);
		s.push(66);
		s.push(77);

		cout << "Item popped is : " << s.pop() << endl;
		cout << "Item popped is : " << s.pop() << endl;
		cout << "mid_element is : " << s.mid_element() << endl;
		/*s.push(1);
		cout << s.mid_element() << endl;
		s.push(2);
		cout << s.mid_element() << endl;
		s.push(3);
		cout << s.mid_element() << endl;
		s.push(4);
		cout << s.mid_element() << endl;
		cout << endl;
		cout << s.pop() << endl;
		cout << s.mid_element() << endl;

		cout << endl << endl;
		s.delete_at_mid();
		cout << s.mid_element() << endl << endl;

		s.push(99);
		cout << s.mid_element() << endl << endl;

		s.push(98);
		cout << s.mid_element() << endl << endl;

		s.push(98);
		cout << s.mid_element() << endl << endl;

		*/
		/*s.delete_at_mid();
		cout << s.mid_element() << endl << endl;

		s.delete_at_mid();
		cout << s.mid_element() << endl << endl;
		*/




	}
	return 0;
}
