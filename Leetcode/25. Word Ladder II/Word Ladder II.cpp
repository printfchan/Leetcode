/************************************************************************/
/* 
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
/************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
//		vector<vector<string>> result;
//		vector<string> item;
//
//		unordered_map<string, vector<string>> pre;
//		unordered_map<string, vector<string>>::iterator mit;
//
//		dict.insert(end);
//
//		unordered_set<string>::iterator sit;
//		for (sit = dict.begin(); sit != dict.end(); ++sit)
//		{
//			pre[*sit] = item;
//		}
//
//		unordered_set<string> used_str;
//		unordered_set<string>::iterator suit;
//		bool find = false;
//		for (sit = dict.begin(); sit != dict.end();)
//		{
//			if (IsNear(start, *sit) == 1)
//			{
//				pre[*sit].push_back(start);
//				used_str.insert(*sit);
//				if (*sit == end)
//				{
//					find = true;
//				}
//				sit = dict.erase(sit);
//			}
//			else{
//				sit++;
//			}
//		}
//
//		if (find)
//		{
//			FindPath(start, end, pre, result, item);
//			return result;
//		}
//
//		while (true)
//		{
//			unordered_set<string> tmp_set;
//			for (sit = dict.begin(); sit != dict.end(); ++sit)
//			{
//				for (suit = used_str.begin(); suit != used_str.end(); ++suit)
//				{
//					if (IsNear(*suit, *sit) == 1)
//					{
//						pre[*sit].push_back(*suit);
//						tmp_set.insert(*sit);
//						if (*sit == end)
//						{
//							find = true;
//						}
//					}
//				}
//				if (find)
//				{
//					break;
//				}
//			}
//
//			if (find)
//			{
//				break;
//			}
//
//			used_str.clear();
//			for (sit = tmp_set.begin(); sit != tmp_set.end(); ++sit)
//			{
//				used_str.insert(*sit);
//				dict.erase(*sit);
//			}
//			
//			if (used_str.empty() || dict.empty())
//			{
//				return result;
//			}
//		}
//
//		FindPath(start, end, pre, result, item);
//		return result;
//	}
//	
//	int IsNear(const string& a, const string& b)
//	{
//		int len = a.length();
//		int dist = 0;
//		for (int i = 0; i < len; ++i)
//		{
//			if (a[i] != b[i])
//			{
//				dist++;
//				if (dist > 1)
//				{
//					return 2;
//				}
//			}
//		}
//		return dist;
//	}
//
//	void FindPath(string &start, string &end, unordered_map<string, vector<string>> &pre, vector<vector<string>> &result, vector<string> &item)
//	{
//		if (start == end)
//		{
//			item.push_back(end);
//			vector<std::string> curPath = item;
//			reverse(curPath.begin(), curPath.end());
//			result.push_back(curPath);
//			item.pop_back();
//			return;
//		}
//		item.push_back(end);
//		for (int i = 0; i < pre[end].size(); ++i)
//		{
//			FindPath(start, pre[end][i], pre, result, item);
//		}
//		item.pop_back();
//	}
//};

//class Solution {
//public:
//	int GetDist(const string& a, const string& b)
//	{
//		int len = a.length();
//		int dist = 0;
//		for (int i = 0; i < len; ++i)
//		{
//			if (a[i] != b[i])
//				dist++;
//		}
//		return dist;
//	}
//
//	void FindNeighbor(const string& start, const string& end, unordered_set<string> &dict, vector<vector<string>> &result, vector<string> &item)
//	{
//		if (GetDist(start, end) == 1)
//		{
//			item.push_back(end);
//			result.push_back(item);
//			item.pop_back();
//
//			return;
//		}
//
//		unordered_set<string>::iterator it;
//		bool flag;
//		for (it = dict.begin(); it != dict.end(); ++it)
//		{
//			flag = false;
//			for (int i = 0; i < item.size(); ++i)
//			{
//				if ((*it) == item[i])
//				{
//					flag = true;
//					break;
//				}
//			}
//			if (flag)
//				continue;
//
//			if (GetDist(start, *it) == 1)
//			{
//				item.push_back(*it);
//				FindNeighbor(*it, end, dict, result, item);
//				item.pop_back();
//			}
//		}
//	}
//
//	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
//		int length = start.length();
//		int dist = 0;
//		vector<vector<string>> result;
//		vector<string> item;
//
//		item.push_back(start);
//
//		FindNeighbor(start, end, dict, result, item);
//
//		return result;
//		/*vector<vector<string>> minResult;
//		vector<vector<string>>::iterator it;
//		int min_len = INT_MAX;
//		for (it = result.begin(); it != result.end(); ++it)
//		{
//			if (it->size() <= min_len)
//			{
//				if (it->size() < min_len)
//					minResult.clear();
//				minResult.push_back(*it);
//				min_len = it->size();
//			}
//		}
//
//		return minResult;*/
//	}
//};

class Solution {
public:
	std::vector<std::vector<std::string> > findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
	{

		result_.clear();
		std::unordered_map<std::string, std::vector<std::string>> prevMap;

		for (auto iter = dict.begin(); iter != dict.end(); ++iter)
		{
			prevMap[*iter] = std::vector<std::string>();
		}

		std::vector<std::unordered_set<std::string>> candidates(2);

		int current = 0;
		int previous = 1;

		candidates[current].insert(start);

		while (true)
		{
			current = !current;
			previous = !previous;

			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
			{
				dict.erase(*iter);
			}

			candidates[current].clear();

			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
			{
				for (size_t pos = 0; pos < iter->size(); ++pos)
				{
					std::string word = *iter;
					for (int i = 'a'; i <= 'z'; ++i)
					{
						if (word[pos] == i)
						{
							continue;
						}

						word[pos] = i;

						if (dict.count(word) > 0)
						{
							prevMap[word].push_back(*iter);
							candidates[current].insert(word);
						}
					}
				}
			}

			if (candidates[current].size() == 0)
			{
				return result_;
			}
			if (candidates[current].count(end))
			{
				break;
			}
		}


		std::vector<std::string> path;
		GeneratePath(prevMap, path, end);

		return result_;
	}

private:
	void GeneratePath(std::unordered_map<std::string, std::vector<std::string>> &prevMap, std::vector<std::string>& path,
		const std::string& word)
	{
		if (prevMap[word].size() == 0)
		{
			path.push_back(word);
			std::vector<std::string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			result_.push_back(curPath);
			path.pop_back();
			return;
		}

		path.push_back(word);
		for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
		{
			GeneratePath(prevMap, path, *iter);
		}
		path.pop_back();
	}

	std::vector<std::vector<std::string>> result_;
};
int main()
{
	string start, end;
	start = "nape";
	end = "mild";
	unordered_set<string> dict;
	dict.insert("dose");
	dict.insert("ends");
	dict.insert("dine");
	dict.insert("jars");
	dict.insert("prow");
	dict.insert("soap");
	dict.insert("guns");
	dict.insert("hops");
	dict.insert("cray");
	dict.insert("hove");
	dict.insert("ella");
	dict.insert("hour");
	dict.insert("lens");
	dict.insert("jive");
	dict.insert("wiry");
	dict.insert("earl");
	dict.insert("mara");
	dict.insert("part");
	dict.insert("flue");
	dict.insert("putt");
	dict.insert("rory");
	dict.insert("bull");
	dict.insert("york");
	dict.insert("ruts");
	dict.insert("lily");
	dict.insert("vamp");
	dict.insert("bask");
	dict.insert("peer");
	dict.insert("boat");
	dict.insert("dens");
	dict.insert("lyre");
	dict.insert("jets");
	dict.insert("wide");
	dict.insert("rile");
	dict.insert("boos");
	dict.insert("down");
	dict.insert("path");
	dict.insert("onyx");
	dict.insert("mows");
	dict.insert("toke");
	dict.insert("soto");
	dict.insert("dork");
	dict.insert("nape");
	dict.insert("mans");
	dict.insert("loin");
	dict.insert("jots");
	dict.insert("male");
	dict.insert("sits");
	dict.insert("minn");
	dict.insert("sale");
	dict.insert("pets");
	dict.insert("hugo");
	dict.insert("woke");
	dict.insert("suds");
	dict.insert("rugs");
	dict.insert("vole");
	dict.insert("warp");
	dict.insert("mite");
	dict.insert("pews");
	dict.insert("lips");
	dict.insert("pals");
	dict.insert("nigh");
	dict.insert("sulk");
	dict.insert("vice");
	dict.insert("clod");
	dict.insert("iowa");
	dict.insert("gibe");
	dict.insert("shad");
	dict.insert("carl");
	dict.insert("huns");
	dict.insert("coot");
	dict.insert("sera");
	dict.insert("mils");
	dict.insert("rose");
	dict.insert("orly");
	dict.insert("ford");
	dict.insert("void");
	dict.insert("time");
	dict.insert("eloy");
	dict.insert("risk");
	dict.insert("veep");
	dict.insert("reps");
	dict.insert("dolt");
	dict.insert("hens");
	dict.insert("tray");
	dict.insert("melt");
	dict.insert("rung");
	dict.insert("rich");
	dict.insert("saga");
	dict.insert("lust");
	dict.insert("yews");
	dict.insert("rode");
	dict.insert("many");
	dict.insert("cods");
	dict.insert("rape");
	dict.insert("last");
	dict.insert("tile");
	dict.insert("nosy");
	dict.insert("take");
	dict.insert("nope");
	dict.insert("toni");
	dict.insert("bank");
	dict.insert("jock");
	dict.insert("jody");
	dict.insert("diss");
	dict.insert("nips");
	dict.insert("bake");
	dict.insert("lima");
	dict.insert("wore");
	dict.insert("kins");
	dict.insert("cult");
	dict.insert("hart");
	dict.insert("wuss");
	dict.insert("tale");
	dict.insert("sing");
	dict.insert("lake");
	dict.insert("bogy");
	dict.insert("wigs");
	dict.insert("kari");
	dict.insert("magi");
	dict.insert("bass");
	dict.insert("pent");
	dict.insert("tost");
	dict.insert("fops");
	dict.insert("bags");
	dict.insert("duns");
	dict.insert("will");
	dict.insert("tart");
	dict.insert("drug");
	dict.insert("gale");
	dict.insert("mold");
	dict.insert("disk");
	dict.insert("spay");
	dict.insert("hows");
	dict.insert("naps");
	dict.insert("puss");
	dict.insert("gina");
	dict.insert("kara");
	dict.insert("zorn");
	dict.insert("boll");
	dict.insert("cams");
	dict.insert("boas");
	dict.insert("rave");
	dict.insert("sets");
	dict.insert("lego");
	dict.insert("hays");
	dict.insert("judy");
	dict.insert("chap");
	dict.insert("live");
	dict.insert("bahs");
	dict.insert("ohio");
	dict.insert("nibs");
	dict.insert("cuts");
	dict.insert("pups");
	dict.insert("data");
	dict.insert("kate");
	dict.insert("rump");
	dict.insert("hews");
	dict.insert("mary");
	dict.insert("stow");
	dict.insert("fang");
	dict.insert("bolt");
	dict.insert("rues");
	dict.insert("mesh");
	dict.insert("mice");
	dict.insert("rise");
	dict.insert("rant");
	dict.insert("dune");
	dict.insert("jell");
	dict.insert("laws");
	dict.insert("jove");
	dict.insert("bode");
	dict.insert("sung");
	dict.insert("nils");
	dict.insert("vila");
	dict.insert("mode");
	dict.insert("hued");
	dict.insert("cell");
	dict.insert("fies");
	dict.insert("swat");
	dict.insert("wags");
	dict.insert("nate");
	dict.insert("wist");
	dict.insert("honk");
	dict.insert("goth");
	dict.insert("told");
	dict.insert("oise");
	dict.insert("wail");
	dict.insert("tels");
	dict.insert("sore");
	dict.insert("hunk");
	dict.insert("mate");
	dict.insert("luke");
	dict.insert("tore");
	dict.insert("bond");
	dict.insert("bast");
	dict.insert("vows");
	dict.insert("ripe");
	dict.insert("fond");
	dict.insert("benz");
	dict.insert("firs");
	dict.insert("zeds");
	dict.insert("wary");
	dict.insert("baas");
	dict.insert("wins");
	dict.insert("pair");
	dict.insert("tags");
	dict.insert("cost");
	dict.insert("woes");
	dict.insert("buns");
	dict.insert("lend");
	dict.insert("bops");
	dict.insert("code");
	dict.insert("eddy");
	dict.insert("siva");
	dict.insert("oops");
	dict.insert("toed");
	dict.insert("bale");
	dict.insert("hutu");
	dict.insert("jolt");
	dict.insert("rife");
	dict.insert("darn");
	dict.insert("tape");
	dict.insert("bold");
	dict.insert("cope");
	dict.insert("cake");
	dict.insert("wisp");
	dict.insert("vats");
	dict.insert("wave");
	dict.insert("hems");
	dict.insert("bill");
	dict.insert("cord");
	dict.insert("pert");
	dict.insert("type");
	dict.insert("kroc");
	dict.insert("ucla");
	dict.insert("albs");
	dict.insert("yoko");
	dict.insert("silt");
	dict.insert("pock");
	dict.insert("drub");
	dict.insert("puny");
	dict.insert("fads");
	dict.insert("mull");
	dict.insert("pray");
	dict.insert("mole");
	dict.insert("talc");
	dict.insert("east");
	dict.insert("slay");
	dict.insert("jamb");
	dict.insert("mill");
	dict.insert("dung");
	dict.insert("jack");
	dict.insert("lynx");
	dict.insert("nome");
	dict.insert("leos");
	dict.insert("lade");
	dict.insert("sana");
	dict.insert("tike");
	dict.insert("cali");
	dict.insert("toge");
	dict.insert("pled");
	dict.insert("mile");
	dict.insert("mass");
	dict.insert("leon");
	dict.insert("sloe");
	dict.insert("lube");
	dict.insert("kans");
	dict.insert("cory");
	dict.insert("burs");
	dict.insert("race");
	dict.insert("toss");
	dict.insert("mild");
	dict.insert("tops");
	dict.insert("maze");
	dict.insert("city");
	dict.insert("sadr");
	dict.insert("bays");
	dict.insert("poet");
	dict.insert("volt");
	dict.insert("laze");
	dict.insert("gold");
	dict.insert("zuni");
	dict.insert("shea");
	dict.insert("gags");
	dict.insert("fist");
	dict.insert("ping");
	dict.insert("pope");
	dict.insert("cora");
	dict.insert("yaks");
	dict.insert("cosy");
	dict.insert("foci");
	dict.insert("plan");
	dict.insert("colo");
	dict.insert("hume");
	dict.insert("yowl");
	dict.insert("craw");
	dict.insert("pied");
	dict.insert("toga");
	dict.insert("lobs");
	dict.insert("love");
	dict.insert("lode");
	dict.insert("duds");
	dict.insert("bled");
	dict.insert("juts");
	dict.insert("gabs");
	dict.insert("fink");
	dict.insert("rock");
	dict.insert("pant");
	dict.insert("wipe");
	dict.insert("pele");
	dict.insert("suez");
	dict.insert("nina");
	dict.insert("ring");
	dict.insert("okra");
	dict.insert("warm");
	dict.insert("lyle");
	dict.insert("gape");
	dict.insert("bead");
	dict.insert("lead");
	dict.insert("jane");
	dict.insert("oink");
	dict.insert("ware");
	dict.insert("zibo");
	dict.insert("inns");
	dict.insert("mope");
	dict.insert("hang");
	dict.insert("made");
	dict.insert("fobs");
	dict.insert("gamy");
	dict.insert("fort");
	dict.insert("peak");
	dict.insert("gill");
	dict.insert("dino");
	dict.insert("dina");
	dict.insert("tier");


	vector<vector<string>> result;

	Solution solution;

	result = solution.findLadders(start, end, dict);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
