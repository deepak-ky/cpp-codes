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

void insert_at_head(node *&head, int value){
	node * n = new node(value);
	n->next = head;
	head = n;
}

void insert_at_tail(node *&head, int val){
	if(head == NULL){
		insert_at_head(head,val);
		return;
	}
	node * temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	node * n = new node(val);
	temp->next = n;
}

void insert_at_position(node *&head, int val, int pos){
	if(pos == 0){
		insert_at_head(head,val);
		return;
	}

	int jump = 0;
	node * temp = head;
	while(temp->next != NULL && jump!=(pos-1)){
		temp = temp->next;
		jump++;
	}

	node * n = new node(val);
	node * temp1 = temp->next;
	temp->next = n;
	n->next = temp1;
}

void delete_at_head(node *&head){
	if(head == NULL){
		cout << "Cannot delete at head as head = NULL";
		return;
	}
	node * n = head;
	head = head->next;
	delete n;
}

void delete_at_tail(node *&head){
	if(head == NULL){
		cout << "Cannot delete";
		return;
	}
	if(head->next == NULL){
		delete_at_head(head);
		return;
	}
	node * temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}

	node * n = temp->next;
	temp->next = n->next;
	delete n;
}

void delete_at_pos(node *& head,int pos){
	if(pos == 0){
		delete_at_head(head);
		return;
	}

	node * temp = head;
	int jump = 0;
	while(temp->next->next != NULL && jump != (pos-1)){
		temp=temp->next;
		jump++;
	}

	node * n = temp->next;
	temp->next = n->next;
	delete n;
}
void display_linked_list(node * head){
	node * temp = head;
	cout << endl;
	while(temp != NULL){
		cout << temp->val <<"->";
		temp = temp->next;
	}
}

node* recursive_reverse_linked_list(node * head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	node * new_head = recursive_reverse_linked_list(head->next);
	head->next->next = head;
	head->next = NULL;
	return new_head;

}

node* reverse_linked_list(node * head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	node * prev = NULL;
	node * c = head;
	while(c != NULL){
		node * n = c->next;
		c->next = prev;
		prev = c;
		c = n;
	}

	return prev;
}

node* midpoint(node * head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	node * slow = head;
	node * fast = head->next;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node* kth_node_from_end(node * head,int k){
	//k is being used in 0 based indexing here

	if(head == NULL || head->next == NULL){
		return head;
	}

	node * earlier = head;
	node * current = head;
	int jump = 0;
	while(jump != k && earlier != NULL){
		jump++;
		earlier = earlier->next;
	}

	if(earlier == NULL){
		cout << "\nOUT OF BOUNDS";
		node * n = new node(-1);
		return n;
	}

	while(earlier->next != NULL){
		current = current->next;
		earlier = earlier->next;
	}

	//wer(current->val);

	return current;
}

node* merge_two_sorted_linked_list_using_recursion_method_1(node * a, node * b){
	if(a == NULL) {return b;}
	if(b == NULL) {return a;}

	if(a->val <= b->val){
		node * n = new node(a->val);
		n->next = merge_two_sorted_linked_list_using_recursion_method_1(a->next,b);
		return n;
	}else{
		node * n = new node(b->val);
		n->next = merge_two_sorted_linked_list_using_recursion_method_1(a,b->next);
		return n;
	}

	return NULL;
}

node* merge_two_sorted_linked_list_method_2(node *a , node * b){
	node * c = new node(0);
	node * temp1 = a;
	node * temp2 = b;
	node * temp3 = c;
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->val <= temp2->val){
			node * n = new node(temp1->val);
			temp3->next = n;
			temp3 = temp3->next;
			temp1 = temp1->next;
		}else{
			node * n = new node(temp2->val);
			temp3->next = n;
			temp3 = temp3->next;
			temp2 = temp2->next;
		}
	}

	while(temp1 != NULL){
		node * n = new node(temp1->val);
		temp3->next = n;
		temp3 = temp3->next;
		temp1 = temp1->next;
	}

	while(temp2 != NULL){
		node * n = new node(temp2->val);
		temp3->next = n;
		temp3 = temp3->next;
		temp2 = temp2->next;
	}

	return c->next;
}

node* merge_two_sorted_linked_list_in_place_using_recursion_method_3(node * a, node * b){
	if(a == NULL) {return b;}
	if(b == NULL) {return a;}

	if(a->val <= b->val){
		node * temp = a;
		temp = temp->next;
		a->next = merge_two_sorted_linked_list_in_place_using_recursion_method_3(temp,b);
		return a;
	}else{
		node * temp = b;
		temp = temp->next;
		node * n = new node(b->val);
		b->next = merge_two_sorted_linked_list_in_place_using_recursion_method_3(a,temp);
		return b;
	}

	return NULL;
}

	node* merge_two_sorted_linked_list_in_place_method_4_helper(node * a, node * b){
		// a head value will be less than b head value
		node * temp3 = a;
		node * temp1 = a->next;
		node * temp2 = b;

		while(temp1 != NULL && temp2 != NULL){
			if(temp1->val <= temp2->val){
				temp3->next=temp1;
				temp3=temp3->next;
				temp1=temp1->next;
			}else{
				temp3->next = temp2;
				temp3=temp3->next;
				temp2=temp2->next;
			}
		}

		if(temp1==NULL){
			temp3->next = temp2;
		}else{
			temp3->next = temp1;
		}

		return a;
	}


node* merge_two_sorted_linked_list_in_place_method_4(node * a, node * b){
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->val <= b->val){
		return merge_two_sorted_linked_list_in_place_method_4_helper(a,b);
	}else{
		return merge_two_sorted_linked_list_in_place_method_4_helper(b,a);
	}
	return NULL;
}

node* merge_sort(node * a){
	if(a == NULL || a->next == NULL){
		return a;
	}

	node * mp = midpoint(a);
	node * m = mp->next;
	mp->next = NULL;
	a = merge_sort(a);
	m = merge_sort(m);
	return merge_two_sorted_linked_list_in_place_using_recursion_method_3(a,m);
}

node* remove_nth_node_from_the_end_of_the_list(node * head , int n){
	//If 0 based indexing do this 👇
	n++;

	node * fast = head;
	node * slow = head;

	int jump = 0;
	while(jump != n && fast != NULL){
		fast = fast->next;
		jump++;
	}

	if(fast == NULL) return head->next;

	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;
	return head;
}

node* add_two_linked_list(node * head1 , node * head2){
	node * ans = new node(-1);
	node * ans_temp = ans;
	node * temp1 = head1;
	node * temp2 = head2;
	int carry = 0;
	while(true){
		if(temp1 == NULL && temp2 == NULL){
			break;
		}
		int w = 0;
		if(temp1 != NULL) w = temp1->val;

		int w1 = 0;
		if(temp2 != NULL) w1 = temp2->val;

		int w2 = w + w1 + carry;
		carry = w2 / 10;
		w2 = w2%10;

		node * n = new node(w2);
		ans_temp->next = n;
		ans_temp = ans_temp->next;

		if(temp1 != NULL) temp1 = temp1->next;
		if(temp2 != NULL) temp2 = temp2->next;
	}

	if(carry != 0){
		node * n = new node(carry);
		ans_temp->next = n;
		ans_temp = ans_temp->next;
	}

	return ans->next;
}

// Y intersection in linked list : find both length, traverse the bigger ll in diff amount,
// start traversing from there, return first node where they meet

pair<bool,node*> detect_cycle(node * head){
	if(head == NULL || head->next == NULL){
		return {false,NULL};
	}
		node * slow = head;
		node * fast = head;

		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast){
				break;
			}
		}

		if(slow != fast){
			 return {false,NULL};
		}else{
			node * temp = head;
			while(fast != temp){
				fast = fast->next;
				temp = temp->next;
			}
			return {true,fast};
		}
}

node* reverse_linked_list_in_groups_of_size_k(node * head,int k){

	if(head == NULL || head->next == NULL){
		return head;
	}

	//wer(head->val);

   	node * kth = head;
   	int jump = 0;
   	while(kth != NULL && jump < k){
   		jump++;
   		kth = kth->next;
   	}

   	//if(kth) wer(kth->val);

   	if(jump != k) return head;

   	jump = 0;

   	node * current = head;
   	node * prev = kth;
   	while(jump < k){
   		node * n = current->next;
   		current->next = prev;
   		prev = current;
   		current = n;
   		jump++;
   	}


   	head->next = reverse_linked_list_in_groups_of_size_k(kth,k);
   	return prev;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		node * head = NULL;
		insert_at_tail(head,1);
		insert_at_tail(head,3);
		insert_at_tail(head,5);
		insert_at_tail(head,7);
		//insert_at_tail(head,7);
		display_linked_list(head);

		// insert_at_position(head,4,3);
		// display_linked_list(head);

		// delete_at_head(head);
		// display_linked_list(head);

		// delete_at_tail(head);
		// display_linked_list(head);
		// delete_at_tail(head);
		// display_linked_list(head);
		// delete_at_tail(head);
		// display_linked_list(head);

		// delete_at_pos(head,2); // works also in the case when the pos is bigger than length 
		// in that case it will alwasys delete the last node
		//  display_linked_list(head);

		// head = recursive_reverse_linked_list(head);
		// display_linked_list(head);
		// head = reverse_linked_list(head);
		// display_linked_list(head);

		// node * middle = midpoint(head);
		// display_linked_list(middle);

		// node * kthnode = kth_node_from_end(head,2);
		// display_linked_list(kthnode);

		node * head1 = NULL;
		insert_at_tail(head1,2);
		insert_at_tail(head1,4);
		insert_at_tail(head1,6);

		display_linked_list(head1);

		// node * sorted = merge_two_sorted_linked_list_using_recursion_method_1(head,head1);
		// display_linked_list(sorted);

		// node * sorted = merge_two_sorted_linked_list_method_2(head,head1);
		// display_linked_list(sorted);

		// node * sorted = merge_two_sorted_linked_list_in_place_using_recursion_method_3(head,head1);
		// display_linked_list(sorted);

		// node * sorted = merge_two_sorted_linked_list_in_place_method_4(head,head1);
		// display_linked_list(sorted);


		// insert_at_tail(head1,3);
		// insert_at_tail(head1,5);
		// insert_at_tail(head1,2);
		// insert_at_tail(head1,4);
		// insert_at_tail(head1,1);
		// display_linked_list(head1);
		// node * sorted = merge_sort(head1);
		// display_linked_list(sorted);

		// node * kthnode = kth_node_from_end(head,1);
		// display_linked_list(kthnode);
		// head = remove_nth_node_from_the_end_of_the_list(head,2);
		// display_linked_list(head);

		// node * sum = add_two_linked_list(head,head1);
		// display_linked_list(sum);

		// cout << endl;
		// cout << endl;

		// node * n1 = new node(1);
		// node * n2 = new node(2); n1->next = n2;
		// node * n3 = new node(3); n2->next = n3;
		// node * n4 = new node(4); n3->next = n4;

		// n4->next = n2; // Change this value to check

		// pair<bool,node*> p = detect_cycle(n1);

		// if(p.first){
		// 	cout << p.second->val << endl;
		// }else{
		// 	cout << "No Cycle exists" << endl;
		// }

		cout << endl;
		cout << endl;

		head = reverse_linked_list_in_groups_of_size_k(head,2);
		display_linked_list(head);

	}
	return 0;
}
