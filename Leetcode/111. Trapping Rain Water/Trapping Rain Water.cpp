/************************************************************************/
/* 
https://oj.leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	const int min(const int a, const int b)
	{
		return (a < b ? a : b);
	}

	int trap(int A[], int n) {
		if (n < 3)
			return 0;

		// store all increase elev
		vector<int> elev;
		elev.push_back(0);

		int sum = 0;
		int result = 0;
		int low = 0;
		for (int i = 1; i < n; ++i)
		{
			if (A[i] > A[i-1])
			{
				sum = 0;
				low = A[elev.back()];
				elev.pop_back();
				while (!elev.empty())
				{
					sum += (min(A[elev.back()], A[i]) - low) * (i - elev.back() - 1);
					low = min(A[elev.back()], A[i]);
					if (A[elev.back()] <= A[i]) 
					{
						elev.pop_back();
					}
					else
						break;
				}
				elev.push_back(i);
				result += sum;
			}
			else{
				elev.push_back(i);
			}
		}
		return result;
	}
};

int main()
{
	int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	//int A[] = { 4, 2, 3 };

	Solution solution;
	cout << solution.trap(A, sizeof(A) / sizeof(A[0]));

	system("pause");
	return 0;
}