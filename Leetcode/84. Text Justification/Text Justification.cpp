/************************************************************************/
/* 
https://oj.leetcode.com/problems/text-justification/
Given an array of words and a length L, format the text such that each line has exactly L characters 
and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
	"This    is    an",
	"example  of text",
	"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		int wcount = words.size();

		string item = "";
		if (wcount < 2)
		{
			if (wcount == 1)
				item += words[0];
			
			for (int i = item.length(); i < L; ++i)
				item += " ";
			result.push_back(item);
			return result;
		}

		int start;
		int end;
		int len;
		for (int i = 0; i < words.size();)
		{
			item = "";
			start = i;
			end = i;
			len = words[i].length();
			++i;

			while (i < words.size())
			{
				if (len + (i-start) + words[i].length() <= L)
				{
					end = i;
					len += words[i].length();
					++i;
				}
				else{
					break;
				}
				
			}
			int space = L - len;
			int count = end - start + 1;
			int div = 1;
			int perc = 0;
			
			if (i == words.size() || count == 1)
			{
				div = 1;
				perc = 0;
			}
			else{
				div = space / (count - 1);
				perc = space % (count - 1);
			}

			for (int j = start; j <= end; ++j)
			{
				if (j == start)
				{
					item = words[j];
				}
				else{
					for (int k = 0; k < div; ++k)
					{
						item += " ";
					}
					if (perc > 0)
					{
						item += " ";
						perc--;
					}
					item += words[j];
				}
			}
			if (item.length() < L)
			{
				for (int j = item.length(); j < L; ++j)
				{
					item += " ";
				}
			}
			result.push_back(item);

		}
		return result;
	}
};

int main()
{
	vector<string> words;
	words.push_back("this");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	int L = 16;

	Solution solution;
	vector<string> result = solution.fullJustify(words, L);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << "\"" << result[i] << "\"" << endl;
	}

	

	system("pause");
	return 0;
}