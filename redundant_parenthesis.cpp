
#include <iostream>
#include <stack>
using namespace std;
bool findDuplicateparenthesis(string str)
{
	stack<char> Stack;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		char ch = str[i];
		if (ch != ')')
		{
			Stack.push(ch);
		}
		else
		{

			char top = Stack.top();
			Stack.pop();
			if (top == '(')
				return true;
			else
			{
				while (top != '(')
				{
					top = Stack.top();
					Stack.pop();
				}
			}
		}

	}
	return false;
}

// Driver code
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;
		if (findDuplicateparenthesis(str))
			cout << "Duplicate" << endl;
		else
			cout << "Not Duplicates" << endl;
	}

	return 0;
}
