/************************************************************************/
/* 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfitSeg(vector<int> &prices, int n) {
		if (n < 2)
			return 0;

		int max_profit = 0;
		int min_price = prices[0];
		for (int i = 1; i < n; ++i)
		{
			if ((prices[i] - min_price) > max_profit)
			{
				max_profit = prices[i] - min_price;
			}
			if (min_price > prices[i])
			{
				min_price = prices[i];
			}
		}
		return max_profit;
	}

	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)
			return 0;

		vector<int> seg_max;
		seg_max.push_back(0);

		int min_price = prices[0];
		int max_profit = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if ((prices[i] - min_price) > max_profit)
			{
				max_profit = prices[i] - min_price;
			}
			if (prices[i] < min_price)
			{
				min_price = prices[i];
			}
			seg_max.push_back(max_profit);
		}

		vector<int> seg_min(prices.size());
		seg_min[prices.size() - 1] = 0;

		int max_price = prices[prices.size() - 1];

		int min_profit = 0;
		for (int i = prices.size() - 1 - 1; i >= 0; --i)
		{
			if ((prices[i] - max_price) < min_profit)
			{
				min_profit = prices[i] - max_price;
			}
			if (prices[i] > max_price)
			{
				max_price = prices[i];
			}
			seg_min[i] = -min_profit;
		}

		int index = 1;
		int left = 0;
		while (index < prices.size())
		{
			while (index < prices.size())
			{
				if (prices[index] >= prices[left])
				{
					index++;
					left++;
				}
				else{
					index++;
					left++;
					break;
				}
			}

			int left_max = seg_max[left - 1];
			int right_max = seg_min[left];

			if (left_max + right_max > max_profit)
			{
				max_profit = left_max + right_max;
			}
		}

		return max_profit;
	}
};

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(3);
	prices.push_back(5);
	prices.push_back(7);
	prices.push_back(2);
	prices.push_back(6);
	prices.push_back(7);
	prices.push_back(8);
	prices.push_back(9);
	prices.push_back(0);
	Solution solution;
	cout << solution.maxProfit(prices);
	system("pause");
	return 0;
}