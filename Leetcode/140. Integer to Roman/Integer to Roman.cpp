/************************************************************************/
/* 
https://oj.leetcode.com/problems/integer-to-roman/
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
/************************************************************************/

/*
个位数举例
Ⅰ,1 】Ⅱ，2】 Ⅲ，3】 Ⅳ，4 】Ⅴ，5 】Ⅵ，6】Ⅶ，7】 Ⅷ，8 】Ⅸ，9 】
十位数举例
Ⅹ，10】 Ⅺ，11 】Ⅻ，12】 XIII,13】 XIV,14】 XV,15 】XVI,16 】XVII,17 】XVIII,18】 XIX,19】 XX,20】
XXI,21 】XXII,22 】XXIX,29】 XXX,30】 XXXIV,34】 XXXV,35 】XXXIX,39】 XL,40】 L,50 】LI,51】 LV,55】
LX,60】 LXV,65】 LXXX,80】 XC,90 】XCIII,93】 XCV,95 】XCVIII,98】 XCIX,99 】
百位数举例
C,100】 CC,200 】CCC,300 】CD,400】 D,500 】DC,600 】DCC,700】 DCCC,800 】CM,900】 CMXCIX,999】
千位数举例
M,1000】 MC,1100 】MCD,1400 】MD,1500 】MDC,1600 】MDCLXVI,1666】 MDCCCLXXXVIII,1888 】MDCCCXCIX,1899 】
MCM,1900 】MCMLXXVI,1976】 MCMLXXXIV,1984】 MCMXC,1990 】MM,2000 】MMMCMXCIX,3999】MDCCCLXXXIV
*/
/************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string roman;
		string A[4][3] = { "I", "V", "X",
							"X", "L", "C",
							"C", "D", "M",
							"M", "", ""};
		int k = 0;
		while (num > 0)
		{
			int p = num % 10;
			num /= 10;
			switch (p)
			{
			case 1:
			case 2:
			case 3:
				for (int i = 0; i < p; ++i)
				{
					roman = A[k][0] + roman;
				}
				break;
			case 4:
				roman = A[k][0] + A[k][1] + roman;
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				for (int i = 5; i < p; ++i)
				{
					roman = A[k][0] + roman;
				}
				roman = A[k][1] + roman;
				break;
			case 9:
				roman = A[k][0] + A[k][2] + roman;
				break;
			}
			k++;
		}
		return roman;
	}
};

int main()
{
	int num = 1896;

	Solution solution;
	cout << solution.intToRoman(num);

	system("pause");
	return 0;
}