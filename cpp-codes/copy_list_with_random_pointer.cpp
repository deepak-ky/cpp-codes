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

class Node{
public:
	int val;
	Node *next;
	Node *random;

	Node(int val){
		this->val = val;
		next = NULL;
		random = NULL;
	}
};

Node* copyRandomList(Node *head){
	/*
	Approach - 1
	if(head == NULL) return NULL;

	unordered_map<Node*,Node*> mp;
	Node *temp = head;
	while(temp != NULL){
		Node *n = new Node(temp->val);
		mp[temp] = n;
		temp = temp->next;
	}

	temp = head;
	while(temp != NULL){
		Node *newTemp = mp[temp];
		newTemp->next = mp[temp->next];
		newTemp->random = mp[temp->random];
		temp = temp->next;
	}

	return mp[head];*/

	// Approach-2
	// How can make access in O(1) time
	// make the next pointer point to the clone of the node
	if(head == NULL) return NULL;
	Node *temp = head;
	while(temp != NULL){
		Node *cloneNode = new Node(temp->val);
		Node *originalNext = temp->next;
		temp->next = cloneNode;
		cloneNode->next = originalNext;
		temp = originalNext;
	}

	// Mapping Random Pointers
	temp = head;
	while(temp != NULL){
		Node *cloneNode = temp->next;
		Node *originalRandom = temp->random;
		if(originalRandom){
			cloneNode->random = originalRandom->next;
		}
		temp = temp->next->next;
	}

	Node *newHead = head->next;

	// Mapping Next Pointers
	temp = head;
	while(temp != NULL){
		Node *cloneNode = temp->next;
		Node *originalNext = cloneNode->next;
		temp->next = originalNext;
		if(originalNext)
		cloneNode->next = originalNext->next;

		temp = temp->next;
	}

	return newHead;
}

void displayLinkedList(Node *head){
	Node * temp = head;
	while(temp != NULL){
		cout << "Node : " << temp->val << endl;
		if(temp->next){
			cout << "Next : " << temp->next->val << endl;
		}else{
			cout << "Next : " << "Next does not exist " << endl;
		}

		if(temp->random){
			cout << "Random : " << temp->random->val << endl;
		}else{
			cout << "Random : " << "Random does not exist " << endl;
		}
		cout << "----------------------------" << endl;
		temp = temp->next;
	} 
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		Node *head = new Node(3);
		Node *node1 = new Node(4);
		Node *node2 = new Node(5);
		Node *node3 = new Node(6);
		head->next = node1;
		node1->next = node2;
		node2->next = node3;
		head->random = node2;
		node1->random = node3;
		node2->random = node1;

		displayLinkedList(head);

		Node * copyHead = copyRandomList(head);
		displayLinkedList(head);
	}
	return 0;
}
