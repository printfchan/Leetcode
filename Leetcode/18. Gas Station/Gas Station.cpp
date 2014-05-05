/************************************************************************/
/* 
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.size() != cost.size() || gas.size() == 0)
			return -1;

		vector<int> status(gas.size());
		int sum = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			status[i] = gas[i] - cost[i];
			sum += status[i];
		}
		if (sum < 0)
		{
			return -1;
		}

		sum = 0;
		int startIndex = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			sum += status[i];
			if (sum < 0)
			{
				startIndex = ((i + 1) % gas.size());
				sum = 0;
			}
		}
		return startIndex;
	}
};
int main()
{
	vector<int> gas;
	vector<int> cost;

	gas.push_back(4);
	/*gas.push_back(2);
	gas.push_back(5);
	gas.push_back(4);*/

	cost.push_back(5);
	/*cost.push_back(2);
	cost.push_back(4);
	cost.push_back(4);*/

	Solution solution;
	
	cout << solution.canCompleteCircuit(gas, cost);

	system("pause");
	return 0;
}