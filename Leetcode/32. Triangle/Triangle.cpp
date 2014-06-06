/************************************************************************/
/* 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
   [2],
  [3,4],
 [6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int min(int a, int b)
	{
		return (a < b ? a : b);
	}

	int minimumTotal(vector<vector<int>> &triangle) {
		int len = triangle.size();
		int size = len + 2;
		vector<int> step(size);
		for (int i = 0; i < size; ++i)
		{
			step[i] = INT_MAX;
		}
		step[1] = 0;
		int tmp;
		int pre;
		for (int i = 0; i < triangle.size(); ++i)
		{
			pre = step[0];
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				tmp = step[j + 1];
				step[j + 1] = min(pre, tmp) + triangle[i][j];
				pre = tmp;
			}
		}
		int ret = step[0];
		for (int i = 1; i < size - 1; ++i)
		{
			if (ret > step[i])
			{
				ret = step[i];
			}
		}
		return ret;
	}
};

int main()
{
	vector<vector<int> > triangle;
	vector<int> lev;

	lev.push_back(2);
	triangle.push_back(lev);
	lev.clear();
	lev.push_back(3);
	lev.push_back(4);
	triangle.push_back(lev);
	lev.clear();
	lev.push_back(6);
	lev.push_back(5);
	lev.push_back(7);
	triangle.push_back(lev);
	lev.clear();
	lev.push_back(4);
	lev.push_back(1);
	lev.push_back(8);
	lev.push_back(3);
	triangle.push_back(lev);
	Solution solution;
	cout << solution.minimumTotal(triangle);
	system("pause");
	return 0;
}