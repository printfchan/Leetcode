#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	static int maxPoints(vector<Point> &points) {
		const double max_double = (1 << 30);
		int size = points.size();
		if (size < 2)
			return size;

		map<double, int> mp;
		int max_count = 0;
		int result = 0;
		
		int deltay = 0;
		int deltax = 0;
		
		int same_point = 0;

		double delta;

		map<double, int>::iterator it;
		for (int i = 0; i < size; ++i)
		{
			max_count = 0;
			same_point = 0;
			for (int j = 0; j < size; ++j)
			{
				if (i!=j)
				{
					deltay = points[i].y - points[j].y;
					deltax = points[i].x - points[j].x;

					if (deltax == 0)
					{
						if (deltay == 0)
						{
							same_point++;
							continue;
						}
						if (mp.find(max_double) == mp.end())
						{
							mp[max_double] = 1;
						}
						else{
							mp[max_double]++;
						}
						continue;
					}
					else{
						delta = deltay / (double)deltax;
						if (mp.find(delta) == mp.end())
						{
							mp[delta] = 1;
						}
						else{
							mp[delta]++;
						}
					}
				}
			}

			for (it = mp.begin(); it != mp.end(); ++it)
			{
				if (it->second > max_count)
					max_count = it->second;
			}
			if (max_count + same_point + 1 > result)
			{
				result = max_count + same_point + 1;
			}
			mp.clear();
		}
		return result;
	}
};
int main()
{
	vector<Point> pp;

	Point p1(1, 1);
	pp.push_back(p1);

	Point p2(2, 2);
	pp.push_back(p2);

	Point p3(3, 4);
	pp.push_back(p3);

	Point p4(-1, 1);
	pp.push_back(p4);
	cout << Solution::maxPoints(pp);
	system("pause");
	return 0;
}


