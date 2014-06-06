/************************************************************************/
/* 
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0)
		{
			vector<int> nullItem;
			return nullItem;
		}

		vector<int> item(rowIndex + 1);

		for (int i = 0; i <= rowIndex; ++i)
		{
			item[0] = 1;
			item[i] = 1;
			for (int j = i - 1; j > 0; --j)
			{
				item[j] = item[j] + item[j - 1];
			}
		}
		return item;
	}
};
int main()
{
	Solution solution;
	vector<int> result = solution.getRow(0);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}