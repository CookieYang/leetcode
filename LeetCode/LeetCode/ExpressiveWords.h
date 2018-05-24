#pragma once
#include "public.h"

using namespace std;

class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		vector<pair<char, int>> dealedS;
		int Length = S.size();
		int res = 0;
		pair<char, int> tmp;
		tmp = pair<char, int>(' ', 0);
		if (Length <= 0)
		{
			return res;
		}
		for (char ch : S) {
			if (ch != tmp.first || ch == '\0')
			{
				dealedS.push_back(tmp);
				tmp =  pair<char, int>(ch, 1);
			}
			else
			{
				tmp.second++;
			}
		}
		dealedS.push_back(tmp);

		for (string s : words) {
			if (s.size() > Length || s.size() == 0)
			{
				continue;
			}
			else
			{
				char currentCh = s[0];
				int count = 1;
				int index = 1;
				bool success = true;
				for (int i = 1; i <= s.size(); i++)
				{
					char test = s[i];
					if (s[i] != currentCh || s[i] == '\0')
					{
						if (index >= dealedS.size())
						{
							success = false;
							break;
						}
						int repeate = dealedS[index].second;
						char ch = dealedS[index].first;
						if (ch != currentCh || count > repeate)
						{
							success = false;
							break;
						}
						else if (repeate <= 2 && (count != repeate))
						{
							success = false;
							break;
						}
						currentCh = s[i];
						count = 1;
						index++;
					}
					else
					{
						count++;
					}
				}
				if (success == true && index == dealedS.size())
				{
					res++;
				}
			}
		}
		return res;
	}
};