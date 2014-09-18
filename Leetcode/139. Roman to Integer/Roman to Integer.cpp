/************************************************************************/
/* 
https://oj.leetcode.com/problems/roman-to-integer/
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
/************************************************************************/
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
	int romanToInt(string s) {
		int len = s.length();
		if (len < 1)
			return 0;
		int result = 0;
		int i = 0;
		int p = 0;
		while (i < len)
		{
			int n = 0;
			switch (s[i])
			{
			case 'M':
				n = 0;
				while (i < len && s[i] == 'M')
				{
					n += 1000;
					i++;
				}
				break;
			case 'C':
			case 'D':
				n = 0;
				// D...
				p = 500;
				if (s[i] == 'C')
				{
					// ...D
					p = 300;
				}
				while (i < len)
				{
					if (s[i] == 'C')
					{
						n += 100;
					}else if (s[i] == 'D')
					{
						n += p;
					}
					else if (s[i] == 'M')
					{
						n += 800;
					}else
						break;
					i++;
				}
				break;
			case 'X':
			case 'L':
				n = 0;
				// L...
				p = 50;
				if (s[i] == 'X')
				{
					// ...L
					p = 30;
				}
				while (i < len)
				{
					if (s[i] == 'X')
					{
						n += 10;
					}
					else if (s[i] == 'L')
					{
						n += p;
					}
					else if (s[i] == 'C')
					{
						n += 80;
					}
					else
						break;
					i++;
				}
				break;
			default:
				n = 0;
				// V...
				p = 5;
				if (s[i] == 'I')
				{
					// ...V
					p = 3;
				}
				while (i < len)
				{
					if (s[i] == 'I')
					{
						n += 1;
					}
					else if (s[i] == 'V')
					{
						n += p;
					}
					else if (s[i] == 'X')
					{
						n += 8;
					}else
						break;
					i++;
				}
				break;
			}
			result += n;
		}

		return result;
	}
};

int main()
{
	//string s = "DCXXI";
	string s = "MDCCCLXXXIV"; 

	Solution solution;
	cout << solution.romanToInt(s);

	system("pause");
	return 0;
}