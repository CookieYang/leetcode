#pragma once
#include "public.h"

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> w(26);
		for (char c : p) {
			w[c - 'a'] ++;
		}
		int start = 0;
		vector<int> result;
		for (size_t i = 0; i < s.size(); i++)
		{
			int cIndex = s[i] - 'a';
			w[cIndex]--;
			while (w[cIndex] < 0) {
				w[s[start] - 'a']++;
				start++;
			}
			if (i - start + 1 == p.size())
			{
				result.push_back(start);
				w[s[start] - 'a']++;
				start++;
			}
		}
		return result;
	}
};