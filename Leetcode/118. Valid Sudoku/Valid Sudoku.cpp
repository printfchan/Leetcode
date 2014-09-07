/************************************************************************/
/*
https://oj.leetcode.com/problems/valid-sudoku/
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool ValidNum(vector<vector<char> > &board, int y, int x)
	{
		int full[9];

		memset(full, 0, sizeof(full));
		for (int i = 0; i < 9; ++i)
		{
			if (board[y][i] != '.')
			{
				if (full[board[y][i] - '1'])
				{
					return false;
				}
				full[board[y][i] - '1'] = 1;
			}
		}

		memset(full, 0, sizeof(full));
		for (int i = 0; i < 9; ++i)
		{
			if (board[i][x] != '.')
			{
				if (full[board[i][x] - '1'])
				{
					return false;
				}
				full[board[i][x] - '1'] = 1;
			}
		}

		int xx, yy;
		xx = x / 3;
		yy = y / 3;
		xx = xx * 3;
		yy = yy * 3;

		memset(full, 0, sizeof(full));

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (board[yy + i][xx + j] != '.')
				{
					if (full[board[yy + i][xx + j] - '1'])
					{
						return false;
					}
					full[board[yy + i][xx + j] - '1'] = 1;
				}
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		bool isValid = true;

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
				{
					isValid = ValidNum(board, i, j);
					if (!isValid)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> board;
	vector<char> item(9);

	string line;

	line = "..9748...";
	//line = "519748632";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = "7........";
	//line = "783652419";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = ".2.1.9...";
	//line = "426139875";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = "..7...24.";
	//line = "357986241";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = ".64.1.59.";
	//line = "264317598";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = ".98...3..";
	//line = "198524367";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = "...8.3.2.";
	//line = "975863124";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = "........6";
	//line = "832491756";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	line = "...2759..";
	//line = "641275983";
	item.assign(line.begin(), line.end());
	board.push_back(item);

	Solution solution;
	cout << solution.isValidSudoku(board);

	system("pause");
	return 0;
}