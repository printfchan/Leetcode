/************************************************************************/
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
A sudoku puzzle...

http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png
...and its solution numbers marked in red.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	bool find_solution;
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

	void DFS(vector<vector<char> > &board, int y, int x)
	{
		if (find_solution)
			return;

		bool has_next = false;
		int xx, yy;
		for (int i = y; i < 9; ++i)
		{
			int j = 0;
			if (i == y)
			{
				j = x + 1;
			}
			for (; j < 9; ++j)
			{
				if (board[i][j] == '.' && !find_solution)
				{
					has_next = true;
					xx = j;
					yy = i;
					break;
				}
			}
			if (has_next)
			{
				for (int n = 1; n <= 9; ++n)
				{
					board[yy][xx] = (char)('0' + n);
					if (ValidNum(board, yy, xx))
					{
						DFS(board, yy, xx);
						if (find_solution)
						{
							return;
						}
					}
				}
				board[yy][xx] = '.';
				break;
			}
		}
		if (!has_next)
		{
			find_solution = true;
		}
	}

	void solveSudoku(vector<vector<char> > &board) {
		int height = board.size();
		if (height != 9)
			return;
		int width = board[0].size();
		if (width != 9)
			return;

		find_solution = false;

		if (board[0][0] == '.')
		{
			for (int n = 1; n <= 9; ++n)
			{
				board[0][0] = (char)('0' + n);
				if (ValidNum(board, 0, 0))
				{
					DFS(board, 0, 0);
					if (find_solution)
					{
						break;
					}
				}
			}
		}
		else
			DFS(board, 0, 0);
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
	solution.solveSudoku(board);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}