/************************************************************************/
/* 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

	int longestConsecutive(vector<int> &num) {
		if (num.size() == 1)
		{
			return 1;
		}

		set<int> st;
		int max_len = 1;

		for (int i = 0; i < (int)num.size(); ++i)
		{
			st.insert(num[i]);
		}
		
		set<int>::iterator it = st.begin();
		while (!st.empty())
		{
			it = st.begin();
			int cur_item = *it;
			int cur_len = 1;
			st.erase(it);

			set<int>::iterator it_tmp;
			int tmp_item = cur_item + 1;
			while ((it_tmp = st.find(tmp_item)) != st.end())
			{
				cur_len++;
				tmp_item++;
				st.erase(it_tmp);
			}

			tmp_item = cur_item - 1;
			while ((it_tmp = st.find(tmp_item)) != st.end())
			{
				cur_len++;
				tmp_item--;
				st.erase(it_tmp);
			}
			if (max_len < cur_len)
			{
				max_len = cur_len;
			}
		}
		return max_len;
	}
};

int main()
{
	vector<int> array;
	array.push_back(100);
	array.push_back(4);
	array.push_back(200);
	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	Solution solution;
	cout << solution.longestConsecutive(array);

	system("pause");
	return 0;
}