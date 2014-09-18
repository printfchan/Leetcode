/************************************************************************/
/* 
https://oj.leetcode.com/problems/string-to-integer-atoi/
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed 
by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		if (str == NULL)
			return 0;

		long long result = 0;
		while (*str != '\0' && (*str <= 0x20 || *str >= 0x7f))
		{
			str++;
		}

		if (*str == '\0')
			return 0;

		int pos_neg = 1;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
			{
				pos_neg = -1;
			}
			str++;
		}

		if (*str == '\0')
			return 0;

		bool point = false;
		while (*str != '\0')
		{
			if (isdigit(*str))
			{
				result = result * 10 + *str - '0';
				if (result > INT_MAX)
				{
					break;
				}
			}
			else
			{
				break;
			}
			str++;
		}
		result *= pos_neg;
		if (result > INT_MAX)
		{
			return INT_MAX;
		}
		if (result < INT_MIN)
		{
			return INT_MIN;
		}
		return (int)result;
	}
};

int main()
{
	char *str = "   -009457d389457893  ";

	Solution solution;
	cout << solution.atoi(str);

	system("pause");
	return 0;
}