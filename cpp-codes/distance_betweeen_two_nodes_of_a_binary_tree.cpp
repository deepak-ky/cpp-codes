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
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		right = NULL;
		left = NULL;
	}

};
node* buildtree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void preorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder_print(root->left);
	preorder_print(root->right);
}
void inorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_print(root->left);
	cout << root->data << " ";

	inorder_print(root->right);
}
void postorder_print(node * root)
{
	if (root == NULL)
	{
		return;
	}
	postorder_print(root->left);
	postorder_print(root->right);
	cout << root->data << " ";

}
void printkthlevel(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (k == 1)
	{
		cout << root->data << " ";
		return;
	}
	printkthlevel(root->left, k - 1);
	printkthlevel(root->right, k - 1);
}
int  height(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return ((max(ls, rs)) + 1);
}
void printalllevel(node * root )
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printkthlevel(root, i);
		cout << endl;
	}
}
void printbfs(node * root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node * f = q.front();
		cout << f->data << ",";
		q.pop();
		if (f->left) {q.push(f->left);}
		if (f->right) {q.push(f->right);}


	}
	return;
}
void linebyline_bfs(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		if (f == NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data << ",";
			q.pop();
			if (f->left) {q.push(f->left);}
			if (f->right) {q.push(f->right);}
		}
	}
}
int count(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + count(root->left) + count(root->right);

}
int sum_of_nodes(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	return (root->data) + sum_of_nodes(root->left) + sum_of_nodes(root->right);

}
int diameter_of_tree(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter_of_tree(root->left);
	int op3 = diameter_of_tree(root->right);
	return max(op1 , max(op3, op2));

}
class Pair
{
public:
	int h;
	int dia;
};
Pair fast_diameter(node * root)
{
	Pair p;
	if (root == NULL)
	{
		p.h = p.dia = 0;
		return p;
	}
	Pair left = fast_diameter(root->left);
	Pair right = fast_diameter(root->right);
	p.h = max((left.h) , (right.h)) + 1;
	p.dia = max((left.h + right.h), max(left.dia, right.dia));
	return p;
}
int replace_sum(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->left == NULL) && (root->right == NULL))
	{
		return root->data;
	}
	int leftsum = replace_sum(root->left);
	int rightsum = replace_sum(root -> right);
	int temp = root->data;
	root->data = leftsum + rightsum;
	return (temp + root->data);
}
class hbpair
{
public:
	int hgt;
	bool isbalanced;
};
hbpair ishieghtbalanced(node * root)
{
	hbpair p;
	if (root == NULL)
	{
		p.hgt = 0;
		p.isbalanced = true;
		return p;
	}
	hbpair left = ishieghtbalanced(root->left);
	hbpair right = ishieghtbalanced(root->right);
	p.hgt =  max(left.hgt, right.hgt) + 1;
	if ((abs(left.hgt - right.hgt) <= 1) && left.isbalanced && right.isbalanced)
	{
		p.isbalanced = true;
	}

	else
	{
		p.isbalanced = false;
	}
	return p;
}
node * buildtreefromarray(int a[], int s, int e)
{
	if (s > e)
	{
		return NULL;
	}
	int mid = (s + e) / 2;
	node * root = new node(a[mid]);
	root->left = buildtreefromarray(a, s, mid - 1);
	root->right = buildtreefromarray(a, mid + 1, e);
	return root;
}
node *createtreefromtravesal(int *in, int *pre, int s, int e)
{
	static int i = 0;
	if (s > e)
	{
		return NULL;
	}
	node * root = new node(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = createtreefromtravesal(in, pre, s, index - 1);
	root->right = createtreefromtravesal(in, pre, index + 1, e);
	return root;
}
vector<int> vec_of_right;
int max_level = -1;
void rightview(node * root, int level)
{
	if (root == NULL)
		return;
	if (level > max_level)
	{
		max_level = level;
		vec_of_right.push_back(root->data);

	}
	rightview(root->right, level + 1);
	rightview(root->left, level + 1);
}
vector<int> nodes_at_distance;
void print_node_down(node*root, int k)
{
	if (root == NULL || k < 0)
		return;
	if (k == 0)
	{
		nodes_at_distance.push_back(root->data);
		return;
	}
	print_node_down(root->left, k - 1);
	print_node_down(root->right, k - 1);
}
int print_node_at_distance(node*root, int k, int target)
{

	if (root == NULL)
	{

		return -1;
	}
	else if (root->data == target)
	{
		print_node_down(root, k);
		return 1;
	}

	int l = print_node_at_distance(root->left, k, target);

	if (l != -1)
	{
		if (l == k)
		{
			nodes_at_distance.push_back(root->data);
		}
		else
			print_node_down(root->right, k - l - 1);

		return l + 1;
	}
	int r = print_node_at_distance(root->right, k, target);

	if (r != -1)
	{
		if (r == k)
		{
			nodes_at_distance.push_back(root->data);
		}
		else
			print_node_down(root->left, k - r - 1);

		return r + 1;
	}

	return -1;


}
class custom
{
public:
	bool haskeyp;
	bool haskeyq;
	node* node;
};
custom* helper(node * root , int p, int q)
{
	//Base Case
	if (root == NULL ) return NULL;
	custom* leftans = helper(root->left, p, q);
	if (leftans != NULL && leftans->node != NULL)
	{
		return leftans;
	}
	custom* rightans = helper(root->right, p, q);
	if (rightans != NULL && rightans->node != NULL)
	{
		return rightans;
	}
	custom* result = new custom();
	if (leftans != NULL && rightans != NULL)
	{
		result->node = root;
		result->haskeyp = true;
		result->haskeyq = true;
		return result;
	} else if (root->data == p)
	{
		result->haskeyp = true;
		result->haskeyq = ((leftans) ? leftans->haskeyq : false)  || ((rightans) ? rightans->haskeyq : false);
		if (result->haskeyp && result->haskeyq) result->node = root;
		return result;
	}
	else if (root->data == q)
	{
		result->haskeyq = true;
		result->haskeyp = ((leftans) ? leftans->haskeyp : false)  || ((rightans) ? rightans->haskeyp : false);
		if (result->haskeyp && result->haskeyq) result->node = root;
		return result;
	} else if (leftans)
	{
		return leftans;
	}
	else if (rightans)
	{
		return rightans;
	}
	return NULL;
}
node* lca;
void leastcommonancestor(node* root, int p, int q)
{

	custom* res = helper(root, p, q);
	if (res == NULL) cout << "NULL";
	//else cout << res->node->data;
	int w  = res->node->data;
	lca = new node(w);
}
int find_distance_from_lca(node * root, int p1, int lev)
{
	if (root == NULL) return -1;
	if (root->data == p1)
	{
		return lev;
	}
	int left = find_distance_from_lca(root->left, p1, lev + 1);
	if (left == -1)
	{
		return find_distance_from_lca(root->right, p1, lev + 1);
	}
	return left;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	node * root = buildtree();

	int p1, q1;
	cin >> p1 >> q1;

	leastcommonancestor(root, p1, q1);
	cout << endl << "LCA is : " << lca->data;
	cout << endl << "The find_distance_from_lca is :" << (find_distance_from_lca(lca, p1, 0)
	        + find_distance_from_lca(lca, q1, 0));


	return 0;
}

