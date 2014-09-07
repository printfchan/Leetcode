/************************************************************************/
/*
https://oj.leetcode.com/problems/insert-interval/
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ret;
		if (intervals.size() == 0)
		{
			ret.push_back(newInterval);
			return ret;
		}

		if (intervals[0].start > newInterval.end)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}

		if (intervals[intervals.size() - 1].end < newInterval.start)
		{
			intervals.insert(intervals.end(), newInterval);
			return intervals;
		}

		int inflag1 = -1;
		bool isIn1 = false;

		int inflag2 = -1;
		bool isIn2 = false;

		int i = 0;

		for (i = 0; i < intervals.size(); ++i)
		{
			if (inflag1 == -1)
			{
				if (intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)
				{
					inflag1 = i;
					isIn1 = true;
				}
				if (intervals[i].start > newInterval.start)
				{
					inflag1 = i;
					isIn1 = false;
				}
			}

			if (inflag2 == -1)
			{
				if (intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end)
				{
					inflag2 = i;
					isIn2 = true;
				}
				if (intervals[i].end < newInterval.end && (i == intervals.size() - 1 || intervals[i + 1].start > newInterval.end))
				{
					inflag2 = i;
					isIn2 = false;
				}
			}
		}


		for (i = 0; i < inflag1; ++i)
		{
			ret.push_back(intervals[i]);
		}

		int newstart = newInterval.start;
		int newend = newInterval.end;
		if (isIn1)
		{
			newstart = intervals[inflag1].start;
		}
		if (isIn2)
		{
			newend = intervals[inflag2].end;
		}
		Interval newinit(newstart, newend);
		ret.push_back(newinit);

		for (; i < intervals.size(); ++i)
		{
			if (intervals[i].start > newend)
			{
				ret.push_back(intervals[i]);
			}
		}

		return ret;
	}
};

int main()
{
	vector<Interval> intervals;
	Interval item1(1, 2);
	intervals.push_back(item1);
	Interval item2(3, 5);
	intervals.push_back(item2);
	Interval item3(6, 7);
	intervals.push_back(item3);
	Interval item4(8, 10);
	intervals.push_back(item4);
	Interval item5(12, 16);
	intervals.push_back(item5);

	Interval newInterval(-2, 15);

	Solution solution;
	vector<Interval> result = solution.insert(intervals, newInterval);

	system("pause");
	return 0;
}