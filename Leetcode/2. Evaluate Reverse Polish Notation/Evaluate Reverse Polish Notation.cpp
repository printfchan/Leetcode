/************************************************************************/
/* 
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	static int evalRPN(vector<string> &tokens) {
		vector<int> num;
		vector<string>::iterator it;
		for (it = tokens.begin(); it != tokens.end(); ++it)
		{
			if ((*it)[0] >= '0' && (*it)[0] <= '9' || (*it).length() > 1)
			{
				num.push_back(atoi(it->c_str()));
			}
			else{
				int b = num.back();
				num.pop_back();
				int a = num.back();
				num.pop_back();
				switch ((*it)[0])
				{
				case '+':
					num.push_back(a + b);
					break;
				case '-':
					num.push_back(a - b);
					break;
				case '*':
					num.push_back(a * b);
					break;
				case '/':
					num.push_back(a / b);
					break;
				default:
					break;
				}
			}
			
		}
		return num.back();
	}
};

int main()
{
	vector<string> expression;
	expression.push_back("3");
	expression.push_back("-4");
	expression.push_back("+");

	cout << Solution::evalRPN(expression);

	system("pause");
	return 0;
}