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
	#define s                            second

	//Prints
	template <class T>
	void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

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

	class node{
	public:
		int val;
		node* next;

		node(int n){
			val = n;
			next = NULL;
		}
	};

	// In insert_at_head, we change the address stored by head, to a new address which is of n,
	// Now if we don't send head by reference, how will this new head address be reflected back 
	// in main.

	// We are not sending head by reference in insert_at_tail because there is no need.
	// we are not changing the head value address. We are just adding a new address at the end.
	// Run examples to understand better.
	// But the base condition would fail if not sent by reference, because now in insert_at_head, 
	// the variable which is being changed, it the copy variable which was sent in insert_at_tail

	void insert_at_head(node *& head, int value){
		wer(head);
		node * n = new node(value);
		wer(n);
		n->next = head;
		head = n;
		wer(head);
	}

	void insert_at_tail(node *head, int value){
		if(head == NULL) {
			// This function will not work if you do not send head by reference
			insert_at_head(head,value);
			return;
		}
		node * n = new node(value);
		node * temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		wer(head);
		wer(n);
		wer(temp);
		temp->next = n;

		cout << "\n Head does not get changed here, so no need to send by reference\n"; 
		wer(head);
		wer(n);
		wer(temp);
	}

	void display_linked_list(node * head){
		while(head!=NULL){
			cout << head->val <<"->";
			head= head->next;
		}
		cout << endl;
	}



	int32_t main()
	{
		init();
		int t = 1;
		//cin >> t;
		while (t--)
		{
			node * head = NULL;
			cout << "In main: ";wer(head);
			insert_at_head(head,2);
			cout << "In main: "; wer(head);
			insert_at_head(head,3);
			cout << "In main: ";wer(head);
			cout << endl;
			cout << endl;
			insert_at_tail(head,4);
			display_linked_list(head);

		}
		return 0;
	}
