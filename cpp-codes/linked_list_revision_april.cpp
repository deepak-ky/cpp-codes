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
	node* next;

	node(int n)
	{
		data = n;
		next = NULL;
	}
};

void insert_at_head(node *&head, int d)
{
	node * n = new node(d);
	n->next = head;
	head = n;
}
void insert_at_tail(node *&head, int d)
{
	node * n = new node(d);
	node * temp = head;
	if (head == NULL)
	{
		insert_at_head(head, d);
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;
	return;
}

void insert_at_position(node *&head, int d, int pos)
{
	if (pos == 0)
	{
		insert_at_head(head, d);
	}
	node * prev = head;
	int jump = 0;
	while (jump < (pos - 1))
	{
		prev = prev->next;
		jump++;
	}
	node * n = new node(d);
	node * temp = prev->next;
	prev->next = n;
	n->next = temp;
}


void delete_a_head(node *&head)
{
	if (head == NULL) return;
	node * n = head;
	head = head->next;
	delete n;
}
void delete_a_tail(node *&head)
{
	if (head == NULL) return;
	node * prev = NULL;
	node * temp = head;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev != NULL)
	{
		prev->next = NULL;
		delete temp;

	}
	else
	{
		node * n = head;
		head = head->next;
		delete n;
	}

}

void delete_a_pos(node *&head , int pos)
{
	if (head == NULL)
	{
		return;
	}
	if (pos == 0)
	{
		delete_a_head(head);
		return;
	}
	node * prev = NULL;
	node * temp = head;
	int jump = 0;
	while (jump <  pos)
	{
		prev = temp;
		temp = temp->next;
		jump++;
	}
	prev->next = temp->next;
	delete temp;
}

bool find_in_string(node *head, int d)
{
	if (head == NULL)
	{
		return false;
	}

	if (head->data == d)
	{
		return true;
	}
	else return find_in_string(head->next, d);
}

void build_list(node *& head)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		insert_at_tail(head, data);
		cin >> data;
	}
}

void reverse_linked_list(node *& head)
{
	node * p = NULL;
	node * c = head;
	node * n = head->next;
	while (n != NULL)
	{
		c->next = p;
		p = c;
		c = n;
		n = n->next;

	}
	c->next = p;
	head = c;
	return;
}


node *  recursive_reverse_linked_list(node *& curr_head)
{
	if (curr_head == NULL)
	{
		return NULL;
	}
	if (curr_head->next == NULL)
	{
		return curr_head;
	}

	node * new_head = recursive_reverse_linked_list(curr_head->next);
	//Attaching the current head at the last of the linked list
	curr_head->next->next = curr_head;
	curr_head->next = NULL;
	return new_head;
}

node * midpoint(node * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * slow = head;
	node * fast = head->next;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node * kth_node_from_end(node * head, int k)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * fast = head;
	int jump = 0;
	while (jump < (k - 1))
	{
		fast = fast->next;
		jump++;
	}
	node * slow = head;
	while (fast->next != NULL)
	{
		fast =  fast->next;
		slow = slow->next;
	}
	return slow;
}


node * merge(node * head1, node * head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}

	node * head3 = NULL;
	if (head1->data <= head2->data)
	{
		node * n = new node(head1->data);
		head3 = n;
		head3->next = merge(head1->next, head2);
	}
	else
	{
		node * n = new node(head2->data);
		head3 = n;
		head3->next = merge(head1, head2->next);
	}

	return head3;
}


node * merge_sort(node * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}


	node * mid = midpoint(head);
	node * b = mid->next;
	mid->next = NULL;

	head = merge_sort(head);
	b = merge_sort(b);

	head = merge(head, b);

	return head;
}

void print_list(node * head)
{
	node * temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void last_element_to_the_front(node *&head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	node * prev = NULL;
	node * temp = head;
	while (temp->next  != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	temp->next = head;
	prev->next = NULL;
	head = temp;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		/*node * head = NULL;
		insert_at_head(head, 3);
		insert_at_head(head, 5);
		insert_at_head(head, 7);
		insert_at_head(head, 9);
		insert_at_tail(head, 89);

		//O based indexing
		insert_at_position(head, 55, 5);
		print_list(head);
		delete_a_head(head);
		delete_a_tail(head);
		//0 based indexing
		delete_a_pos(head, 3);

		print_list(head);



		if (find_in_string(head, 8))
		{
			yes;
		}
		else no;

		node * head1 = NULL;
		build_list(head1);
		print_list(head1);

		reverse_linked_list(head1);
		print_list(head1);

		//HEAD CHANGED HERE
		head = recursive_reverse_linked_list(head1);
		insert_at_tail(head, 9);
		insert_at_tail(head, 10);
		print_list(head);


		node * mid = midpoint(head);
		cout << mid->data;
		cout << endl;

		//find out the third node from the end
		node * n = kth_node_from_end(head, 3);
		cout << n->data;
		cout << endl;
		*/

		node * head1  = NULL;
		node * head2 = NULL;
		insert_at_tail(head1, 1);
		insert_at_tail(head1, 3);
		insert_at_tail(head1, 5);
		insert_at_tail(head1, 7);

		insert_at_tail(head2, 2);
		insert_at_tail(head2, 4);
		insert_at_tail(head2, 6);
		insert_at_tail(head2, 8);

		head1 = merge(head1, head2);


		reverse_linked_list(head1);
		print_list(head1);


		head1 = merge_sort(head1);

		print_list(head1);

		last_element_to_the_front(head1);

		print_list(head1);








	}
	return 0;
}
