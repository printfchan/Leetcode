/************************************************************************/
/* 
https://oj.leetcode.com/problems/merge-intervals/
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(struct Interval a, struct Interval b)
	{
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ret;

		sort(intervals.begin(), intervals.end(), &Solution::cmp);

		for (int i = 0; i < intervals.size(); ++i)
		{
			int start = intervals[i].start;
			int end = intervals[i].end;

			while (i + 1 < intervals.size())
			{
				if ((intervals[i + 1].start >= start && intervals[i + 1].start <= end) || 
					(intervals[i + 1].end >= start && intervals[i + 1].end <= end))
				{
					start = (intervals[i + 1].start > start ? start : intervals[i + 1].start);
					end = (intervals[i + 1].end > end ? intervals[i + 1].end : end);
					i++;
				}
				else
					break;
			}

			Interval inter(start, end);
			ret.push_back(inter);
		}
		return ret;
	}
};

int main()
{
	vector<Interval> intervals;
	Interval item1(1, 3);
	intervals.push_back(item1);
	Interval item2(2, 6);
	intervals.push_back(item2);
	Interval item3(8, 10);
	intervals.push_back(item3);
	Interval item4(15, 18);
	intervals.push_back(item4);

	Solution solution;
	vector<Interval> result = solution.merge(intervals);

	system("pause");
	return 0;
}