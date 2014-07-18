/************************************************************************/
/* 
https://oj.leetcode.com/problems/valid-number/
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		if (s == NULL)
			return false;

		string str(s);

		int firstch = str.find_first_not_of(' ', 0);
		if (firstch != -1)
			str = str.substr(firstch);
		else
			return false;
		
		int lastch = str.find_last_not_of(' ');
		if (lastch != -1)
			str = str.substr(0, lastch+1);
	
		if (str == "")
			return false;
		
		if (str.find_first_of(' ', 0) != -1)
			return false;

		bool sig = (str[0] == '-' || str[0] == '+' ? true : false);
		if (sig)
			str = str.substr(1, string::npos);

		int sci = -1;
		int decimal = -1;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
				continue;
			
			if (str[i] == 'e' || str[i] == 'E')
			{
				if (sci < 0)
					sci = i;
				else
					return false;
			}
			else
			{
				if (str[i] == '.')
				{
					if (decimal < 0)
						decimal = i;
					else
						return false;
				}
				else{
					if (sci >= 0 && (str[i] == '-' || str[i] == '+') && (i-sci) == 1)
					{
						continue;
					}
					else
						return false;
				}
			}
		}

		if (sci == 0 )
			return false;

		if (sci > 0 && decimal >= 0)
		{
			if (sci < decimal)
			{
				return false;
			}
		}

		string real = str;
		string e = "";
		if (sci > 0)
		{
			real = str.substr(0, sci);
			e = str.substr(sci + 1, string::npos);

			if (real == "" || e == "")
			{
				return false;
			}

			// e must be a int number
			if (e[0] == '-' || e[0] == '+')
				e = e.substr(1, string::npos);
			if (e == "")
				return false;
		}

		if (decimal >= 0)
		{
			if (real.length()-1 == decimal && real.length() == 1)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	char s[] = "256523.e02";

	Solution solution;
	cout << solution.isNumber(s);

	system("pause");
	return 0;
}