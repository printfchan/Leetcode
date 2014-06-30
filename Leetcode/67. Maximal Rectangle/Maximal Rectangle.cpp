/************************************************************************/
/* 
https://oj.leetcode.com/problems/maximal-rectangle/
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	struct Info
	{
		int width;
		int height;
	};
	int maximalRectangle(vector<vector<char> > &matrix) {
		int area_max = 0;
		if (matrix.empty())
			return area_max;

		int len = matrix[0].size();
		vector<vector<Info>> step;
		vector<Info> item;

		struct Info info;
		info.width = 0;
		info.height = 0;

		vector<Info> preline;
		for (int i = 0; i < matrix[0].size(); ++i)
			preline.push_back(info);
		
		int c = 0;
		for (int i = 0; i < matrix.size(); ++i)
		{
			c = 1;
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (matrix[i][j] == '1')
				{
					info.width = c;
					info.height = preline[j].height + 1;
					c++;
				}
				else{
					info.width = 0;
					info.height = 0;
					c = 1;
				}
				item.push_back(info);
			}
			preline = item;
			step.push_back(item);
			item.clear();
		}
		
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (matrix[i][j] == '1')
				{
					int w = step[i][j].width;
					int h = step[i][j].height;
					bool w_changed = false;

					if (w == 1 || h == 1)
					{
						if (w*h>area_max)
						{
							area_max = w*h;
							continue;
						}
					}
					for (int m = 0; m < h; m++)
					{
						w_changed = false;
						for (int n = 0; n < w; n++)
						{
							if (matrix[i-m][j-n] == '0')
							{
								if ((m+1)*n > area_max)
								{
									area_max = (m + 1)*n;
								}
								w_changed = true;
								w = n + 1;
								break;
							}
						}
						if (!w_changed)
						{
							if (w*(m+1) > area_max)
							{
								area_max = w*(m + 1);
							}
						}
					}
				}
			}
		}
		
		return area_max;
	}
};

int main()
{
	vector<vector<char>> matrix;

	/*vector<char> item(8);
	item[0] = '0';
	item[1] = '1';
	item[2] = '0';
	item[3] = '1';
	item[4] = '1';
	item[5] = '1';
	item[6] = '0';
	item[7] = '1';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '0';
	item[2] = '1';
	item[3] = '1';
	item[4] = '0';
	item[5] = '1';
	item[6] = '1';
	item[7] = '1';
	matrix.push_back(item);
	item[0] = '1';
	item[1] = '1';
	item[2] = '1';
	item[3] = '1';
	item[4] = '1';
	item[5] = '1';
	item[6] = '0';
	item[7] = '0';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '1';
	item[2] = '1';
	item[3] = '1';
	item[4] = '1';
	item[5] = '0';
	item[6] = '1';
	item[7] = '1';
	matrix.push_back(item);
	item[0] = '1';
	item[1] = '0';
	item[2] = '1';
	item[3] = '0';
	item[4] = '1';
	item[5] = '1';
	item[6] = '0';
	item[7] = '1';
	matrix.push_back(item);*/

	vector<char> item(2);
	item[0] = '1';
	item[1] = '0';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '1';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '1';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '1';
	matrix.push_back(item);
	item[0] = '1';
	item[1] = '1';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '0';
	matrix.push_back(item);
	item[0] = '0';
	item[1] = '1';
	matrix.push_back(item);

	Solution solution;
	cout << solution.maximalRectangle(matrix);

	system("pause");
	return 0;
}