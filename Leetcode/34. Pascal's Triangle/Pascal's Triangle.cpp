/************************************************************************/
/* 
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],
[1,4,6,4,1]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows < 1)
		{
			return result;
		}

		for (int i = 0; i < numRows; ++i)
		{
			vector<int> item(i + 1);
			item[0] = 1;
			item[i] = 1;
			for (int j = 1; j < i; ++j)
			{
				item[j] = result[i - 1][j - 1] + result[i - 1][j];
			}
			result.push_back(item);
		}

		return result;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> result = solution.generate(5);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}