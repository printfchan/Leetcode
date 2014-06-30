/************************************************************************/
/* 
https://oj.leetcode.com/problems/gray-code/
The gray code is a binary numeral system where two successive values(相邻) differ in only one bit.

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
二进制码→格雷码（编码）：
此方法从对应的n位二进制码字中直接得到n位格雷码码字，步骤如下：
对n位二进制的码字，从右到左，以0到n-1编号
如果二进制码字的第i位和i+1位相同，则对应的格雷码的第i位为0，否则为1（当i+1=n时，二进制码字的第n位被认为是0，即第n-1位不变）[5]
公式表示：（G：格雷码，B：二进制码）

例如：二进制码0101，为4位数，所以其所转为之格雷码也必为4位数，因此可取转成之二进位码第五位为0，即0 b3 b2 b1 b0。
0 xor 0=0，所以g3=0
0 xor 1=1，所以g2=1
1 xor 0=1，所以g1=1
0 xor 1=1，所以g0=1
因此所转换为之格雷码为0111
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