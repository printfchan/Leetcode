/************************************************************************/
/* 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size()  < 2)
			return 0;
		
		int max_profit = 0;
		int min_price = prices[0];
		for (int i = 1; i < prices.size(); ++i)
		{
			if ((prices[i]-min_price) > max_profit)
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
};

int main()
{
	vector<int> price;
	price.push_back(3);
	price.push_back(2);
	
	Solution solution;
	cout << solution.maxProfit(price);

	system("pause");
	return 0;
}