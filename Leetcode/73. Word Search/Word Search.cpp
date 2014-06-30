/************************************************************************/
/* 
https://oj.leetcode.com/problems/word-search/
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 

The same letter cell may not be used more than once.

For example,
Given board =

[
	["ABCE"],
	["SFCS"],
	["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool bIfFind = false;
	bool DFS(vector<vector<char> > &board, int starty, int startx, string& word, int k)
	{
		if (k == word.length() - 1)
		{
			bIfFind = true;
			return bIfFind;
		}

		if (bIfFind)
			return true;

		board[starty][startx] = ' ';

		const static int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

		int h = board.size();
		int w = board[0].size();
		int xx = 0;
		int yy = 0;
		for (int i = 0; i < 4; ++i)
		{
			yy = starty + dir[i][1];
			xx = startx + dir[i][0];

			if (xx >= 0 && xx < w && yy >=0 && yy < h)
			{
				if (board[yy][xx] == word[k+1])
				{
					if (DFS(board, yy, xx, word, k + 1))
					{
						board[starty][startx] = word[k];
						return true;
					}
				}
			}
		}

		board[starty][startx] = word[k];
		return false;
	}

	bool exist(vector<vector<char> > &board, string word) {
		int h = board.size();
		if (h == 0)
			return false;
		
		int w = board[0].size();
		if (w == 0)
			return false;

		if (word.length() == 0)
			return true;
		
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == word[0])
				{
					if (DFS(board, i, j, word, 0))
					{
						return true;
					}
				}
			}
		}
		
		return false;
	}
};

int main()
{
	vector<vector<char> > board;
	/*vector<char> item(4);
	item[0] = 'A';
	item[1] = 'B';
	item[2] = 'C';
	item[3] = 'E';
	board.push_back(item);
	item[0] = 'S';
	item[1] = 'F';
	item[2] = 'C';
	item[3] = 'S';
	board.push_back(item);
	item[0] = 'A';
	item[1] = 'D';
	item[2] = 'E';
	item[3] = 'E';
	board.push_back(item);
	string word = "SEE";*/

	vector<char> item(3);
	item[0] = 'C';
	item[1] = 'A';
	item[2] = 'A';
	board.push_back(item);
	item[0] = 'A';
	item[1] = 'A';
	item[2] = 'A';
	board.push_back(item);
	item[0] = 'B';
	item[1] = 'C';
	item[2] = 'D';
	board.push_back(item);
	string word = "AAB";

	Solution solution;
	cout << solution.exist(board, word);

	system("pause");
	return 0;
}