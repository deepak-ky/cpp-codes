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

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{

		// Normal Understanding Terms , Declerations without pointer
		// node head(10);

		// // cout << head << endl;
		// cout << head.val << endl;
		// if(head.next == NULL){
		// 	cout << "here";
		// }

		// cout << endl;

		// node head1(20);
		// cout << head1.val << endl;
		// if(head1.next == NULL){
		// 	cout << "here1";
		// }

		// // head's next pointer will have the location of head1
		// head.next = &head1;

		// cout << endl;

		// // cout << (head.next).val << endl; // Error
		// // Two ways of accessing value
		// cout <<( *(head.next)).val << endl;
		// cout << (head.next)->val;

		// node head2(30);
		// head1.next = &head2;

		// cout << endl;
		// cout << (head1.next)->val << endl;

		// node temp = head;
		// cout << endl << temp.val << endl;
		// cout <<( *(temp.next)).val << endl;

		// while(temp.next != NULL){
		// 	cout << temp.val << " , ";
		// 	temp = *(temp.next);
		// }

		// cout << endl;

		// node *temp1 = &head;
		// cout << endl << temp1->val << endl;

		// Decleration with pointer
		node * n = new node(10);
		cout << n << endl;
		cout << (*n).val << endl;
		cout << n->val << endl;

		node *n1 = new node(22);
		cout << n1 << endl;

		// (*n).next = n1;
		n->next = n1; // above line works also

		cout << n->next->val << endl;

		// Important Points 
		// Pointers store address
		// defrencing a pointer, gives the value of what is stored in that address
		// can you arrow pointer, if you do not want to defreence

		// n = abc // n stores the address abc
		// at abc address // 10 and NULL is present as of now

		// n1 = xyz // n1 stores the address xyz
		// at xyz address // 22 and NULL is present as of now

		// n->next = n1 // at abc address now 10 and xyz is present
	}
	return 0;
}
