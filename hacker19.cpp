#include <iostream>
#include <stack>
using namespace std;

// Function to find duplicate parenthesis in an expression
void duplicateparenthesis(string exp)
{
	// take a empty stack of characters
	stack<char> stack;

	// traverse the input expression
	for (int i = 0; i < exp.length(); i++)
	{
		// if current char in the expression is a not a closing parenthesis
		if (exp[i] != ')') {
			stack.push(exp[i]);
		}
		// if current char in the expression is a closing parenthesis
		else
		{
			// if the top element in the stack is an opening parenthesis,
			// the sub-expression of the form ((exp)) is found
			if (stack.top() == '(')
			{
				cout << "The expression have duplicate parenthesis.";
				return;
			}

			// pop till '(' is found for current ')'
			while (stack.top() != '(')
				stack.pop();

			// pop '('
			stack.pop();
		}
	 }

	 // if we reach here, then the expression does not have any
	 // duplicate parenthesis
	 cout << "The expression does not have duplicate parenthesis";
}

// main function
int main()
{
	string exp;
	cin>>exp;

	duplicateparenthesis(exp);

	return 0;
}
