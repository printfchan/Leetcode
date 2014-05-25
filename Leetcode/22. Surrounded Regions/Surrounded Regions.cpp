/************************************************************************/
/* 
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	typedef struct Point
	{
		Point(int xx, int yy)
		{
			x = xx;
			y = yy;
		}
		int x;
		int y;
	}Point;

	void solve(vector<vector<char>> &board) {
		if (board.size() == 0)
			return;
		if (board[0].size() == 0)
			return;

		int i, j;
		vector<Point> gray;

		// 1st line
		for (int i = 0; i < board[0].size(); ++i)
		{
			if (board[0][i] == 'O')
			{
				Mask(board, 0, i, 'O', 'x');
			}
		}

		// last line, can merge with the 1st line
		for (int i = 0; i < board[board.size()-1].size(); ++i)
		{
			if (board[board.size() - 1][i] == 'O')
			{
				Mask(board, board.size() - 1, i, 'O', 'x');
			}
		}
		
		// left column
		for (int i = 0; i < board.size(); ++i)
		{
			if (board[i][0] == 'O')
			{
				Mask(board, i, 0, 'O', 'x');
			}
		}

		// right column, can merge with the left column
		for (int i = 0; i < board.size(); ++i)
		{
			if (board[i][board[i].size()-1] == 'O')
			{
				Mask(board, i, board[i].size() - 1, 'O', 'x');
			}
		}

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j] == 'x')
				{
					board[i][j] = 'O';
				}
			}
		}
	}
	void Mask(vector<vector<char>> &board, int i, int j, char origin, char target)
	{
		vector<Point> area;

		area.push_back(Point(i, j));
		Point p(i, j);
		while (!area.empty())
		{
			p.x = area.back().x;
			p.y = area.back().y;

			board[p.x][p.y] = target;
			area.pop_back();

			// left
			if (isValid(p.x, p.y - 1, board.size(), board[p.x].size()))
			{
				if (board[p.x][p.y - 1] == origin)
				{
					area.push_back(Point(p.x, p.y - 1));
				}
			}

			// right
			if (isValid(p.x, p.y + 1, board.size(), board[p.x].size()))
			{
				if (board[p.x][p.y + 1] == origin)
				{
					area.push_back(Point(p.x, p.y + 1));
				}
			}

			// up
			if (isValid(p.x - 1, p.y, board.size(), board[p.x].size()))
			{
				if (board[p.x - 1][p.y] == origin)
				{
					area.push_back(Point(p.x - 1, p.y));
				}
			}

			// down
			if (isValid(p.x + 1, p.y, board.size(), board[p.x].size()))
			{
				if (board[p.x + 1][p.y] == origin)
				{
					area.push_back(Point(p.x + 1, p.y));
				}
			}
		}
	}

	bool isValid(int x, int y, int xx, int yy)
	{
		if (x < 0 || x >= xx)
		{
			return false;
		}
		if (y < 0 || y >= yy)
		{
			return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;

	vector<vector<char>> board;

	vector<char> item;
	item.push_back('X');
	item.push_back('X');
	item.push_back('X');
	item.push_back('X');
	board.push_back(item);

	item.clear();
	item.push_back('X');
	item.push_back('O');
	item.push_back('O');
	item.push_back('X');
	board.push_back(item);

	item.clear();
	item.push_back('X');
	item.push_back('X');
	item.push_back('O');
	item.push_back('X');
	board.push_back(item);

	item.clear();
	item.push_back('X');
	item.push_back('O');
	item.push_back('X');
	item.push_back('X');
	board.push_back(item);

	solution.solve(board);

	int i, j;
	for (i = 0; i < board.size(); ++i)
	{
		for (j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}