/************************************************************************/
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 

However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2)
			return 0;

		int max_profit = 0;
		int index = 1;
		int left = 0;
		while (index < prices.size())
		{
			int seg = 0;
			while (index < prices.size())
			{
				if (prices[index] >= prices[left])
				{
					seg += prices[index] - prices[left];
					index++;
					left++;
				}
				else{
					index++;
					left++;
					break;
				}
			}
			max_profit += seg;
		}
		
		return max_profit;
	}
};

int main()
{
	vector<int> price;
	price.push_back(2);
	price.push_back(3);
	price.push_back(5);
	price.push_back(3);
	price.push_back(4);
	price.push_back(1);
	price.push_back(7);

	Solution solution;
	cout << solution.maxProfit(price);

	system("pause");
	return 0;
}