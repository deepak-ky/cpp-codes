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
	node * next;
	node(int d)
	{
		data = d;
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
	if (head == NULL)
	{
		insert_at_head(head, d);
	}
	else
	{
		node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		node * n = new node(d);
		n->next = NULL;
		temp->next = n;
	}
}
void print_list(node *head)
{
	node * temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
}
int length_of_link_list(node *head)
{
	if (head == NULL) return 0;
	node * temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}
int kth_node_from_end(node *head, int k)
{
	if (head == NULL /* || k > length_of_link_list(head)*/)
	{
		return NULL;
	}
	int jump = 1;
	node * fast = head;
	node * slow = head;
	while (jump < k)
	{
		fast = fast->next;
		jump++;
	}
	if (fast == NULL) return NULL;
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}
void rotate_link_list(node*& head, int k)
{
	int len = length_of_link_list(head);
	node * temp = head;
	node * n = head;
	node * last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	int jump = 1;
	while ( jump < (len - k))
	{
		temp = temp->next;
		jump++;
	}
	int jump1 = 0;
	while ( jump1 < (len - k))
	{
		n = n->next;
		jump1++;
	}

	temp->next = NULL;
	last->next = head;
	head = n;

}

// // bool is_palindrome(node * head)
// // {
// // 	int jump = 1;
// // 	node * temp = head;
// // 	while (temp->next != NULL)
// // 	{
// // 		node * w =  kth_node_from_end(head, jump);
// // 		if (temp->data != w->data)
// // 		{
// // 			return false;
// // 		}
// // 		temp = temp->next;
// // 		jump++;
// // 	}
// // 	return true;
// // }
// node * sort_link_list_0_1_2(node * head)
// {

// 	node * head_0 = new node(-1);
// 	node * head_1 = new node(-1);
// 	node * head_2 = new node(-1);
// 	node * temp1 = head_0;
// 	node * temp2 = head_1;
// 	node * temp3 = head_2;
// 	node * temp = head;
// 	while (temp != NULL)
// 	{
// 		if (temp->data == 0)
// 		{
// 			temp1->next = temp;
// 			temp1 = temp1->next;
// 		}
// 		else if (temp->data == 1)
// 		{
// 			temp2->next = temp;
// 			temp2 = temp2->next;
// 		}
// 		else if (temp->data == 2)
// 		{
// 			temp3->next = temp;
// 			temp3 = temp3->next;
// 		}
// 		temp = temp->next;
// 	}


// 	if (head_1->next != NULL)
// 	{
// 		temp1->next = head_1->next;
// 	}
// 	else temp1->next = head_2->next;

// 	temp2->next = head_2-> next;
// 	temp3->next = NULL;

// 	head = head_0->next;

// 	delete head_1;
// 	delete head_0;
// 	delete head_2;
// 	return head;
// }

// void pair_wise_swap_elements(node *& head)
// {
// 	if (head == NULL )
// 	{
// 		return;
// 	}
// 	node * curr = head->next->next;
// 	node * prev = head;
// 	head = head->next;
// 	node * n;

// 	head->next = prev;
// 	while ((curr != NULL) && (curr->next != NULL))
// 	{
// 		prev->next = curr->next;
// 		node * n = curr->next->next;
// 		curr->next->next = curr;
// 		prev = curr;
// 		curr = n;
// 	}
// 	prev->next = curr;
// }
// void delete_at_head(node *&head)
// {
// 	cout << head->data;
// 	head = head->next;
// }
// int intersection(int d, node * head1, node * head2)
// {
// 	node * temp1 = head1;
// 	node * temp2 = head2;
// 	int jump = 1;
// 	while (jump <= d)
// 	{
// 		temp1 = temp1->next;
// 		jump++;
// 	}
// 	while (temp1 != NULL && temp2 != NULL)
// 	{
// 		if (temp1->data == temp2->data)
// 		{
// 			return temp1->data;
// 		}
// 		temp1 = temp1->next;
// 		temp2 = temp2->next;
// 	}
// 	return -1;
// }
// int intersection_point(node * head1, node * head2)
// {
// 	int l1 = length_of_link_list(head1);
// 	int l2 = length_of_link_list(head2);

// 	int d = abs(l1 - l2);


// 	if (l1 >= l2)
// 		return	intersection(d, head1, head2);
// 	else return intersection(d, head2, head1);
// }
// node * remove_duplicates_from_sorted_link_list(node * head)
// {
// 	if (head == NULL || head->next == NULL)
// 	{
// 		return head;
// 	}
// 	node * prev = head;
// 	node * curr = head->next;
// 	while (curr != NULL)
// 	{
// 		if (curr->data != prev->data)
// 		{
// 			prev->next = curr;
// 			prev = curr;
// 		}
// 		curr = curr->next;
// 	}
// 	prev->next = curr;
// 	return head;
// }
// node * merge(node * a, node * b)
// {	if (a == NULL)
// 	{
// 		return b;
// 	}
// 	if (b == NULL)
// 	{
// 		return a;
// 	}
// 	node *c;
// 	if (a->data < b->data)
// 	{
// 		c = a;
// 		c->next = merge(a->next, b);
// 	}
// 	else {
// 		c = b;
// 		c->next = merge(a, b->next);
// 	}
// 	return c;
// }
// node * middle(node * a)
// {
// 	if (a == NULL || a->next == NULL)
// 	{
// 		return a;
// 	}
// 	node * slow = a;
// 	node * fast = a->next;
// 	while (fast != NULL && fast->next != NULL)
// 	{
// 		slow = slow->next;
// 		fast = fast->next->next;
// 	}
// 	return slow;
// }
// node * mergesort(node * a)
// {
// 	if (a == NULL || a->next == NULL)
// 	{
// 		return a;
// 	}
// 	node * a1 = a;
// 	node * mid = middle(a);
// 	node * b = mid->next;
// 	mid->next = NULL;
// 	a1 = mergesort(a1);
// 	b = mergesort(b);
// 	node * c = merge(a1, b);
// 	return c;

// }
// void reverse_link_list(node *& head)
// {
// 	node * prev = NULL;
// 	node * curr = head;
// 	node * n;
// 	while (curr != NULL)
// 	{
// 		n = curr->next;
// 		curr->next = prev;
// 		prev = curr;
// 		curr = n;
// 	}
// 	head = prev;
// }
// node * add_two_linked_list(node * a, node * b)
// {
// 	node * ans = NULL;
// 	reverse_link_list(a);
// 	reverse_link_list(b);
// 	print_list(a);
// 	cout << endl; print_list(b);
// 	cout << endl;
// 	node * temp = a;
// 	node * temp1 = b;
// 	int carry = 0;
// 	while (temp != NULL && temp1 != NULL)
// 	{
// 		int d = temp->data + temp1->data + carry;
// 		if (d < 10)
// 		{
// 			insert_at_head(ans, d);
// 			carry = 0;
// 		}
// 		else if (d >= 10)
// 		{
// 			d = d % 10;
// 			insert_at_head(ans, d);
// 			carry = 1;
// 		}
// 		temp = temp->next;
// 		temp1 = temp1->next;
// 	}
// 	if (temp != NULL && temp1 == NULL)
// 	{
// 		while (temp != NULL)
// 		{
// 			int d = temp->data + carry;
// 			if (d < 10)
// 			{
// 				insert_at_head(ans, d);
// 				carry = 0;
// 			}
// 			else if (d >= 10)
// 			{
// 				d = d % 10;
// 				insert_at_head(ans, d);
// 				carry = 1;
// 			}
// 			temp = temp->next;
// 		}

// 	}
// 	else if (temp == NULL && temp1 != NULL)
// 	{
// 		while (temp1 != NULL)
// 		{
// 			int d = temp1->data + carry;
// 			if (d < 10)
// 			{
// 				insert_at_head(ans, d);
// 				carry = 0;
// 			}
// 			else if (d >= 10)
// 			{
// 				d = d % 10;
// 				insert_at_head(ans, d);
// 				carry = 1;
// 			}
// 			temp1 = temp1->next;
// 		}

// 	}
// 	if (carry == 1)
// 	{
// 		insert_at_head(ans, 1);
// 	}
// 	return ans;

// }

void insert_at_pos(node *& head, int d, int pos)
{
	if (head == NULL) return;
	if (pos == 1) insert_at_head(head, d);
	else
	{
		node * temp = head;
		int jump = 0;
		while (jump < (pos - 2))
		{
			temp = temp->next;
			jump++;
		}
		node * n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

void insert_temp_in_sorted_list(node *& head, int d)
{
	int jump = 1;
	node * temp = head;
	while (temp->data <= d && temp != NULL)
	{
		jump++;
		temp = temp->next;
	}
	insert_at_pos(head, d, jump);
}
node * insertion_sort(node * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * sorted_list = new node(head->data);
	node *temp = head->next;
	while (temp != NULL)
	{
		insert_temp_in_sorted_list(sorted_list, temp->data);
		temp = temp->next;
	}
	cout << endl;
	print_list(sorted_list);
}
node * rec_reverse(node * & head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node * smallhead = rec_reverse(head->next);
	node * c = head;
	c->next->next = c;
	c->next = NULL;
	return smallhead;
}
node * reverse_k_elements_from_head(node * head, int k)
{
	node * curr = head;
	node * n;
	node * temp = head;
	int j = 0;
	while (j < k)
	{
		temp = temp->next;
		j++;
	}
	node * prev = temp;
	int jump = 0;
	while (jump < (k))
	{
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		jump++;
	}
	return prev;
}
node *  reverse_elements_of_given_size(node * head, int k)
{
	node * prev = NULL;
	node * curr = head;
	node * n = NULL;
	int jump = 0;
	while (jump < k && curr != NULL)
	{
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		jump++;
	}
	if (n != NULL)
	{
		head->next = reverse_elements_of_given_size(n, k);
	}
	return prev;

}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	node * head = NULL;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		insert_at_tail(head, w);
	}
	print_list(head);
	// int n1;
	// cin >> n1;
	// node * head1 = NULL;
	// for (int i = 0; i < n1; i++)
	// {
	// 	int w;
	// 	cin >> w;
	// 	insert_at_tail(head1, w);
	// }
	// //reverse_link_list(head);
	// cout << endl;
	// //print_list(head1);
	// node * ans = add_two_linked_list(head, head1);
	// cout << endl;
	// print_list(ans);
	// cout << endl;
	// cout << intersection_point(head, head1);
	//cout << endl << length_of_link_list(head);
	//node * w = kth_node_from_end(head, 2);
	//cout << w->data;
	//cout << endl;
	//rotate_link_list(head, 6);
	//reverse_first_k_elements(head, 1);
	//print_list(head);
	/*if (is_palindrome(head))
	{
		cout << "Yes";
	}
	else cout << "No";*/
	//cout << endl;
	//head = sort_link_list_0_1_2(head);
	//pair_wise_swap_elements(head);
	//print_list(head);
	//head = remove_duplicates_from_sorted_link_list(head);
	//cout << endl;
	//head = mergesort(head);
	//print_list(head);
	// head = merge(head, head1);
	// cout << endl; print_list(head);
	//cout << middle(head)->data;
	//head = reverse_elements_of_given_size(head, 3);
	//insert_at_pos(head, 6, 1);
	head = reverse_elements_of_given_size(head, 2);
	cout << endl;
	print_list(head);
	return 0;
}
