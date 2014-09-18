/************************************************************************/
/* 
https://oj.leetcode.com/problems/container-with-most-water/
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int min_h(int a, int b)
	{
		return a < b ? a : b;
	}
	int maxArea(vector<int> &height) {
		if (height.size() < 2)
			return 0;
		int count = height.size();
		int left = 0;
		int right = count - 1;
		int area = min_h(height[left], height[right]) * (right - left);
		int maxarea = area;

		while (left < right)
		{
			int flag;
			if (height[left] < height[right])
			{
				flag = left;
				while (left < right && height[flag] >= height[left])
				{
					left++;
				}
			}
			else{
				flag = right;
				while (left < right && height[right] <= height[flag])
				{
					right--;
				}
			}
			if (left != right)
			{
				area = min_h(height[left], height[right]) * (right - left);
				if (maxarea < area)
				{
					maxarea = area;
				}
			}
		}
		return maxarea;
	}
};

int main()
{
	vector<int> height;
	height.push_back(3);
	height.push_back(8);
	height.push_back(6);
	height.push_back(9);
	height.push_back(5);

	Solution solution;
	cout << solution.maxArea(height);

	system("pause");
	return 0;
}