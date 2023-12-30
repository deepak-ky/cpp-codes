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
	node * left;
	node * right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
node * insert_in_bst(node * root, int d)
{
	if (root == NULL)
	{
		node * n = new node(d);
		return n;
	}

	if (d > root->data)
	{
		root->right = insert_in_bst(root->right, d);
	}
	else if (d < root->data)
	{
		root->left = insert_in_bst(root->left, d);
	}
	//when the changes are done in the root

	return root;
}
node * build_bst()
{
	int d;
	cin >> d;
	node * root1 = NULL;
	while (d != -1)
	{
		root1 = insert_in_bst(root1, d);
		cin >> d;
	}
	return root1;
}
void print_level_by_level(node * root)
{
	queue<node*> bfs;
	bfs.push(root);
	bfs.push(NULL);
	while (!bfs.empty())
	{
		node * f = bfs.front();
		bfs.pop();
		if (f)
		{
			cout << f->data << " ";
			if (f->left) bfs.push(f->left);
			if (f->right) bfs.push(f->right);
		}
		else
		{
			cout << endl;
			if (!bfs.empty())
			{
				bfs.push(NULL);
			}
		}
	}
}
bool search_in_bst(node * root, int d)
{
	if (root == NULL)
	{
		return false;
	}
	else if (d == root->data)
	{
		return true;
	}
	else if (d > root->data)
	{
		return search_in_bst(root->right, d);
	}
	else
	{
		return search_in_bst(root->left, d);
	}

}
node * delete_in_bst(node * root, int d)
{
	// if (root == NULL)
	// {	//element is not present in the tree this should not be the case.
	// 	return NULL;
	// }
	if (d  >  root->data )
	{
		root->right = delete_in_bst(root->right, d);
	}
	else if (d < root->data ) //should not be equal to here
	{
		root->left = delete_in_bst(root->left, d);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			node * temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL && root->right != NULL)
		{
			node * temp = root->right;
			delete root;
			return temp;
		}
		else
		{
			//imediate successor
			node * temp = root->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			int w = root->data;
			swap(root->data, temp->data);
			root->right = delete_in_bst(root->right, w);
		}

	}
	return root;
}
bool is_bst_lies_between(node * root, int low, int high)
{
	if (root == NULL)
	{
		return true;
	}
	bool check1;
	if (root->data > low && root->data < high)
	{
		check1 = true;
	}
	else check1 = false;
	bool check2 = is_bst_lies_between(root->left, low, root->data);
	bool check3 = is_bst_lies_between(root->right, root->data, high);

	if (check1 && check2 && check3)
	{
		return true;
	}
	else return false;
}
void convert_bst_to_list(node * root, list<int> &l)
{
	if (root == NULL)
	{
		return;
	}
	convert_bst_to_list(root->left, l);
	l.push_back(root->data);
	convert_bst_to_list(root->right, l);
}
class linked_list
{
public:
	node * head;
	node * tail;
};
linked_list flatten(node * root)
{
	linked_list l;
	if (root == NULL)
	{
		l.head = l.tail = NULL;
		return l;
	}
	if (root->left == NULL && root->right == NULL)
	{
		l.head = l.tail = root;
		return l;
	}
	if (root->left == NULL && root->right != NULL)
	{
		linked_list right = flatten(root->right);
		l.head = root;
		root->right = right.head;
		right.head->left = root;
		l.tail = right.tail;
		return l;
	}
	if (root->left != NULL && root->right == NULL)
	{
		linked_list left = flatten(root->left);
		l.head = left.head;
		root->left = left.head;
		left.tail->right = root;
		l.tail = root;
		return l;
	}
	else
	{
		linked_list right = flatten(root->right);
		linked_list left = flatten(root->left);
		l.head = left.head;
		left.tail->right = root;
		root->right = right.head;
		right.head->left = root;
		l.tail = right.tail;
		return l;
	}

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
	node * root;
	root = build_bst();
	print_level_by_level(root);
	// if (search_in_bst(root, 9))
	// {
	// 	cout << "Present";
	// }
	// else cout << "Not Present";
	/*root = delete_in_bst(root, 8);
	cout << endl;
	print_level_by_level(root);*/

	//root = delete_in_bst(root,)
	// if (is_bst_lies_between(root, INT_MIN, INT_MAX))
	// {
	// 	cout << "bst";
	// }
	// else cout << "is a bst";
	/*	list<int> l;
		convert_bst_to_list(root, l);
		cout << endl;
		for (auto x : l)
		{
			cout << x << "->";
		}*/
	linked_list l = flatten(root);
	node * temp = l.head;
	node * temp1 = l.tail;
	while (temp1 != NULL)
	{
		cout << temp1->data;
		cout << "->";
		temp1 = temp1->left;
	}
	return 0;
}
