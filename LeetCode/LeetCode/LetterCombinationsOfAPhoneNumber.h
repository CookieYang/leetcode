#pragma once
#include "public.h"
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		string tmp;
		if (digits.size() == 0)
		{
			return result;
		}
		DFS(result, 0, digits, tmp);
		return result;
	}

	void DFS(vector<string>& result, int currentDepth, string digits, string& currentString) {
		int length = digits.size();
		if (currentDepth == length)
		{
			result.push_back(currentString);
			return;
		}
		char c = digits[currentDepth];
		if (QueryTable.find(c) != QueryTable.end())
		{
		    string s = QueryTable.at(c);
			for (char tmp : s) {
				currentString.push_back(tmp);
				DFS(result, currentDepth + 1, digits, currentString);
				currentString.pop_back();
			}
		}
	}

private:
	const map<char, string> QueryTable{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
};