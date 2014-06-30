/************************************************************************/
/* 
https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit(5,6).

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int max(int a, int b)
	{
		return (a > b ? a : b);
	}
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0)
			return 0;
		if (height.size() == 1)
			return height[0];
		
		vector<int> record;
		for (int i = 0; i < height.size(); ++i)
		{
			record.push_back(0);
		}

		vector<int> smallStack;
		smallStack.push_back(0);
		//record[0] = height[0];
		int max_area = height[0];
		int w = 0;

		for (int i = 1; i < height.size(); ++i)
		{
			if (height[i] >= height[smallStack.back()])
			{
				smallStack.push_back(i);
			}
			else{
				w = smallStack.back();
				while (!smallStack.empty())
				{
					if (height[smallStack.back()] > height[i])
					{
						record[smallStack.back()] += height[smallStack.back()] * (i - smallStack.back());
						//w = smallStack.back();
						if (record[smallStack.back()] > max_area)
							max_area = record[smallStack.back()];
						
						smallStack.pop_back();
					}else
						break;
				}
				// height[i] is smaller than before any
				if (smallStack.empty())
				{
					record[i] += height[i] * i;
				}
				else{
					record[i] += height[i] * (i-smallStack.back()-1);
				}
				smallStack.push_back(i);
			}
		}
		
		w = smallStack.back();
		while (!smallStack.empty())
		{
			record[smallStack.back()] += height[smallStack.back()] * (w - smallStack.back() + 1);

			if (record[smallStack.back()] > max_area)
				max_area = record[smallStack.back()];

			smallStack.pop_back();
		}

		return max_area;
	}
};

int main()
{
	vector<int> height;
	height.push_back(999);
	height.push_back(999);
	height.push_back(999);
	height.push_back(999);

	/*height.push_back(1);
	height.push_back(2);
	height.push_back(3);
	height.push_back(4);
	height.push_back(5);*/

	/*height.push_back(5);
	height.push_back(4);
	height.push_back(1);
	height.push_back(2);*/
	/*height.push_back(6);
	height.push_back(2);
	height.push_back(3);*/
	/*height.push_back(3);
	height.push_back(6);
	height.push_back(5);
	height.push_back(7);
	height.push_back(4);
	height.push_back(8);
	height.push_back(1);
	height.push_back(0);*/

	/*height.push_back(5);
	height.push_back(4);
	height.push_back(4);
	height.push_back(6);
	height.push_back(3);
	height.push_back(2);
	height.push_back(9);
	height.push_back(5);
	height.push_back(4);
	height.push_back(8);
	height.push_back(1);
	height.push_back(0);
	height.push_back(0);
	height.push_back(4);
	height.push_back(7);
	height.push_back(2);*/

	Solution solution;
	cout << solution.largestRectangleArea(height);

	system("pause");
	return 0;
}