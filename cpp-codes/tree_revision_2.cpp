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
node * build_binary_tree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node * root = new node(d);
	root->left = build_binary_tree();
	root->right = build_binary_tree();
	return root;
}
void print_level_by_level(node * root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		node * f = q.front();
		q.pop();
		if (f)
		{
			cout << f->data << " ";
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else if (f == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
	}
}
unordered_map<int, int> mp;
void print_left_view(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (mp[k] == 0)
	{
		cout << root->data << " ";
		mp[k]++;
	}
	print_left_view(root->left, k + 1);
	print_left_view(root->right, k + 1);
}
void print_right_view(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	if (mp[k] == 0)
	{
		cout << root->data << " ";
		mp[k]++;
	}
	print_right_view(root->right, k + 1);
	print_right_view(root->left, k + 1);
}
map<int, pair<int, int> > mp1;
void print_bottom_view(node * root, int k, int h)
{
	if (root == NULL)
	{
		return;
	}
	if (mp1.find(k) == mp1.end())
	{
		mp1[k] = {root->data, h};
	}
	else
	{
		if (mp1[k].second <= h)
		{
			mp1[k] = {root->data, h};
		}
	}
	print_bottom_view(root->left, k - 1, h + 1);
	print_bottom_view(root->right, k + 1, h + 1);
}
map<int, pair<int, int> > mp2;
void print_top_view(node * root, int k, int h)
{
	if (root == NULL)
	{
		return;
	}
	if (mp2.find(k) == mp2.end())
	{
		mp2[k] = {root->data, h};
	}
	else
	{
		if (mp2[k].second >= h)
		{
			mp2[k] = {root->data, h};
		}
	}
	print_top_view(root->left, k - 1, h + 1);
	print_top_view(root->right, k + 1, h + 1);
}
int ans = INT_MIN;
int maximum_path_sum(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int op1 = maximum_path_sum(root->left);
	int op2 = maximum_path_sum(root->right);

	int case1 = root->data + op1;
	int case2 = root->data + op2;
	int case3 = root->data + op1 + op2;
	int case4 = root->data;

	int v1 = max(case1, case2);
	int v2 = max(case3, case4);

	ans = max(ans, max(v1, v2));
	int w = 0;
	return max(w, max(op1, op2)) + root->data; //same as max(case1,case2,case4)

}
int max_node2node_sum  = INT_MIN;
int max_leave_node_sum(node * root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = INT_MIN;
	int right = INT_MIN;
	if (root->left) left = max_leave_node_sum(root->left);
	if (root->right) right = max_leave_node_sum(root->right);

	if (root->left && root->right)
	{
		max_node2node_sum = max(max_node2node_sum, (left + right + root->data));
		wer(max_node2node_sum);
		cout << endl;
	}
	if (root->left && root->right)
		return  (max(left, right) + root->data);
	if (root->left)
		return (left + root->data);
	if (root->right)
		return (right + root->data);
	else return root->data;
}

map<int, list<int>> vop;
void vertical_print(node * root, int k)
{
	if (root == NULL)
	{
		return;
	}
	vop[k].push_back(root->data);
	vertical_print(root->left, k - 1);
	vertical_print(root->right, k + 1);
}
void mirror(node *& root)
{
	if (root == NULL)
	{
		return;
	}
	node * f = root->left;
	root->left = root->right;
	root->right = f;
	mirror(root->left);
	mirror(root->right);
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
	node * root = build_binary_tree();
	print_level_by_level(root);
	cout << endl;
	//print_left_view(root, 0);
	//print_right_view(root, 0);
	// print_bottom_view(root, 0, 0);
	// for (auto x : mp1)
	// {
	// 	pair<int, int> p = x.second;
	// 	cout  << p.first << " ";
	// }
	// print_top_view(root, 0, 0);
	// for (auto x : mp2)
	// {
	// 	pair<int, int> p = x.second;
	// 	cout  << p.first << " ";
	// }
	// maximum_path_sum(root);
	// cout << ans;
	// cout << endl;
	// max_leave_node_sum(root);
	// cout << max_node2node_sum << endl;
	// vertical_print(root, 0);
	// cout << "Vertical Order Print : \n";
	// for (auto x : vop)
	// {
	// 	for (auto y : x.second)
	// 	{
	// 		cout << y << " ";
	// 	}
	// 	cout << endl;
	// }
	mirror(root);
	cout << endl;
	print_level_by_level(root);
	return 0;
}
