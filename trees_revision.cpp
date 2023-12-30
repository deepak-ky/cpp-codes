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
node * build_tree(node * root1)
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	root1 = new node(d);
	root1->left = build_tree(root1->left);
	root1->right = build_tree(root1->right);
	return root1;
}
void print_preorder(node * root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	print_preorder(root->left);
	print_preorder(root->right);
}
void print_inorder(node * root)
{
	if (root == NULL)
	{
		return;
	}
	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);
}
void print_postorder(node * root)
{
	if (root == NULL)
	{
		return;
	}
	print_postorder(root->left);
	print_postorder(root->right);
	cout << root->data << " ";
}
int height_of_tree(node * root)
{
	if (root == NULL)
	{
		return -1;
	}
	int h1 = height_of_tree(root->left);
	int h2 = height_of_tree(root->right);
	return max(h1, h2) + 1;
}
void print_kth_level(node * root, int k)
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
	print_kth_level(root->left, k - 1);
	print_kth_level(root->right, k - 1);
}
void print_all_levels(node * root)
{
	//N^2 complexity
	int h = height_of_tree(root);
	for (int i = 1; i <= h; i++)
	{
		print_kth_level(root, i);
		cout << endl;
	}
}
void bfs_level(node * root)
{
	queue<node*> bfs;
	bfs.push(root);
	while (!bfs.empty())
	{
		node * f = bfs.front();
		bfs.pop();
		cout << f->data << " ";
		if (f->left != NULL) bfs.push(f->left);
		if (f->right != NULL) bfs.push(f->right);
	}
}
void bfs_level_by_level(node * root)
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
			if (f->left != NULL) bfs.push(f->left);
			if (f->right != NULL) bfs.push(f->right);
		}
		else
		{
			cout << endl;
			if (!bfs.empty())
				bfs.push(NULL);
		}
	}
}
int count_of_nodes(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int c1 = count_of_nodes(root->left);
	int c2 = count_of_nodes(root->right);
	return c1 + c2  +  1;
}
int sum_of_nodes(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int s1 = sum_of_nodes(root->left);
	int s2 = sum_of_nodes(root->right);
	return s1 + s2  +  root->data;
}
int diameter(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int d1 = diameter(root->left);
	int d2 = diameter(root->right);
	int d3 = height_of_tree(root->left) + height_of_tree(root->right);
	return max(d1, max(d2, d3));
}
typedef pair<int, int> pair_hd;
//p.first represents diamerter
//p.second represents height
pair_hd fast_diameter(node * root)
{
	pair_hd p;
	if (root == NULL)
	{
		p.first = p.second = 0;
		return p;
	}
	pair_hd p_left = fast_diameter(root->left);
	pair_hd p_right = fast_diameter(root->right);

	p.second = max(p_left.second , p_right.second) + 1;

	p.first = max((p_left.second + p_right.second), max(p_left.first, p_right.first));
	return p;
}
int replace_node_by_sum_of_children(node *& root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}
	int w1 = replace_node_by_sum_of_children(root->left);
	int w2 = replace_node_by_sum_of_children(root->right);
	int w = root->data;
	root->data = w1 + w2;
	return w + root->data;
}
class h_and_balance
{
public:
	int height;
	bool is_balanced;
};
h_and_balance is_height_balanced(node * root)
{
	h_and_balance h;
	if (root == NULL)
	{
		h.height = -1;
		h.is_balanced = true;
		return h;
	}
	h_and_balance left = is_height_balanced(root->left);
	h_and_balance right = is_height_balanced(root->right);

	h.height = max(left.height, right.height) + 1;
	if (left.is_balanced == false || right.is_balanced == false)
	{
		h.is_balanced = false;
	}
	else
	{
		if (abs(left.height - right.height) <= 1)
		{
			h.is_balanced = true;
		}
		else h.is_balanced = false;
	}
	return h;
}
node *  build_tree_from_array(int *a, int s, int e)
{
	if (s > e)
	{
		return NULL;
	}
	int mid = (s + e) / 2;
	node * root = new node(a[mid]);
	root->left = build_tree_from_array(a, s, mid - 1);
	root->right = build_tree_from_array(a, mid + 1, e);
	return root;

}
int i = 0;
node * build_tree_from_pre_and_in( int s, int e, int *pre, int *in)
{
	if (s > e)
	{
		return NULL;
	}
	int temp_r = pre[i];
	node * root = new node(temp_r);
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == temp_r)
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = build_tree_from_pre_and_in( s, index - 1, pre, in);
	root->right = build_tree_from_pre_and_in( index + 1, e, pre, in);
	return root;
}
node * build_tree_from_post_and_in( int s, int e, int *post, int *in)
{
	if (s > e)
	{
		return NULL;
	}
	int temp_r = post[i];
	node * root = new node(temp_r);
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == temp_r)
		{
			index = j;
			break;
		}
	}
	i--;
	root->right = build_tree_from_post_and_in( index + 1, e, post, in);
	root->left = build_tree_from_post_and_in( s, index - 1, post, in);
	return root;
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
	//int a[] = {1, 2, 3, 4, 5};
	//int n = 5;
	//int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	//int in[]  = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 4, 8, 5, 3, 6, 7};
	int in[]  = {4, 8, 2, 5, 1, 6, 3, 7};
	int n = 8;
	//root = build_tree(root);
	root = build_tree_from_pre_and_in( 0, n - 1, pre, in);
	/*cout << "Preorder : " ; print_preorder(root); cout << endl;
	cout << "Inorder : " ; print_inorder(root); cout << endl;
	cout << "Postorder : "; print_postorder(root); cout << endl;*/
	//cout << height_of_tree(root);
	//print_kth_level(root, 3);
	//print_all_levels(root);
	//bfs_level_by_level(root);
	//cout << endl << count_of_nodes(root);
	//cout << endl << sum_of_nodes(root);
	//cout << endl << diameter(root);
	// pair_hd p = fast_diameter(root);
	// cout << "Height : " << p.second << endl;
	// cout << "Diameter : " << p.first << endl;
	bfs_level_by_level(root);
	//replace_node_by_sum_of_children(root);
	//cout << endl;
	//bfs_level_by_level(root);
	// h_and_balance h = is_height_balanced(root);
	// cout << "Height : " << h.height;
	// if (h.is_balanced) cout << "is_balanced";
	// else cout << "not is_balanced";


	return 0;

}
