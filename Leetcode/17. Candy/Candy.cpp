/************************************************************************/
/* 
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// O(n) O(n)
class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.size() < 2)
			return ratings.size();
		
		int result = 0;
		int size = ratings.size();
		vector<int> candy;
		for (int i = 0; i < size; ++i)
		{
			candy.push_back(1);
		}

		for (int i = 1; i < size; ++i)
		{
			// large than left
			if (ratings[i] > ratings[i - 1])
				candy[i] = candy[i - 1] + 1;
		}
		for (int i = size-2; i >= 0; --i)
		{
			// large than right
			if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i+1])
				candy[i] = candy[i + 1] + 1;
		}
		
		for (int i = 0; i < size; ++i)
		{
			result += candy[i];
		}
		return result;
	}
};

int main()
{
	Solution solution;
	vector<int> rating;

	rating.push_back(1);
	rating.push_back(3);
	rating.push_back(2);
	rating.push_back(9);
	rating.push_back(4);
	rating.push_back(5);
	rating.push_back(6);
	rating.push_back(8);
	rating.push_back(7);

	cout << solution.candy(rating);

	system("pause");
	return 0;
}