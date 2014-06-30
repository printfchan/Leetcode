/************************************************************************/
/* 
https://oj.leetcode.com/problems/gray-code/
The gray code is a binary numeral system where two successive values(����) differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
/************************************************************************/
/************************************************************************/
/* 
��������������루���룩��
�˷����Ӷ�Ӧ��nλ������������ֱ�ӵõ�nλ���������֣��������£�
��nλ�����Ƶ����֣����ҵ�����0��n-1���
������������ֵĵ�iλ��i+1λ��ͬ�����Ӧ�ĸ�����ĵ�iλΪ0������Ϊ1����i+1=nʱ�����������ֵĵ�nλ����Ϊ��0������n-1λ���䣩[5]
��ʽ��ʾ����G�������룬B���������룩

���磺��������0101��Ϊ4λ������������תΪ֮������Ҳ��Ϊ4λ������˿�ȡת��֮����λ�����λΪ0����0 b3 b2 b1 b0��
0 xor 0=0������g3=0
0 xor 1=1������g2=1
1 xor 0=1������g1=1
0 xor 1=1������g0=1
�����ת��Ϊ֮������Ϊ0111
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		
		int num = 0;
		int gray;
		int tmp;
		const int maxnum = (1<<n);
		
		while (num < maxnum)
		{
			tmp = num;
			gray = 0;
			for (int i = 0; i < n; ++i)
				gray |= (((tmp >> i) & 1) ^ ((tmp >> (i + 1)) & 1)) << i;
			
			result.push_back(gray);
			num++;
		}
		return result;
	}
};

int main()
{
	Solution solution;
	vector<int> result = solution.grayCode(4);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	
	system("pause");
	return 0;
}