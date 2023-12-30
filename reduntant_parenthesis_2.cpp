#include <bits/stdc++.h>
using namespace std;
bool checkRedundancy(string& str)
{

	stack<char> st;
	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (ch != ')')
		{
			st.push(ch);
		}
		else
		{
			char top = st.top();
			st.pop();
			bool flag = true;
			while (top != '(') {


				if (top == '+' || top == '-' ||
				        top == '*' || top == '/')
					flag = false;


				top = st.top();
				st.pop();
			}

			// If operators not found
			if (flag == true)
				return true;
		}

	}
	return false;
}

// Function to check redundant brackets
void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// Driver code
int main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;
	findRedundant(str);

	return 0;
}
