/************************************************************************/
/* 
https://oj.leetcode.com/problems/plus-one/
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
(最高位排在表头)
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int num = 0;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else{
				digits[i]++;
				return digits;
			}
		}
		
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(8);

	Solution solution;
	vector<int> result = solution.plusOne(digits);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

	system("pause");
	return 0;
}