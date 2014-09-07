/************************************************************************/
/* 
https://oj.leetcode.com/problems/rotate-image/
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		int h = matrix.size();
		if (h < 2)
			return;

		int w = matrix[0].size();
		if (w < 2)
			return;

		int r = h / 2;
		int s = 0, e = w;
		for (int i = 0; i < r; ++i)
		{
			for (int j = s; j < e-1; ++j)
			{
				int tmp = matrix[i][e - (j - s) - 1];
				matrix[i][e - (j - s) - 1] = matrix[j][i];
				matrix[j][i] = matrix[e - 1][j];
				matrix[e - 1][j] = matrix[e - (j - s) - 1][e - 1];
				matrix[e - (j - s) - 1][e - 1] = tmp;
			}
			s++;
			e--;
		}
	}
};

int main()
{
	vector<vector<int>> matrix;
	int n = 4;
	vector<int> item(4);
	item[0] = 1;
	item[1] = 2;
	item[2] = 3;
	item[3] = 4;
	matrix.push_back(item);
	item[0] = 5;
	item[1] = 6;
	item[2] = 7;
	item[3] = 8;
	matrix.push_back(item);
	item[0] = 9;
	item[1] = 10;
	item[2] = 11;
	item[3] = 12;
	matrix.push_back(item); 
	item[0] = 13;
	item[1] = 14;
	item[2] = 15;
	item[3] = 16;
	matrix.push_back(item);
	/*int n = 2;
	vector<int> item(2);
	item[0] = 1;
	item[1] = 2;
	matrix.push_back(item);
	item[0] = 3;
	item[1] = 4;
	matrix.push_back(item);*/
	/*int n = 1;
	vector<int> item(1);
	item[0] = 1;
	matrix.push_back(item);*/

	Solution solution;
	solution.rotate(matrix);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}