#pragma once
#include "public.h"

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		map<string, pair<int, int>> table;
		for (size_t i = 0; i < list1.size(); i++)
		{
			string s = list1[i];
			pair<int, int> tmp{i, 2000 };
			table[s] = tmp;
		}
		for (size_t i = 0; i < list2.size(); i++)
		{
			string s = list2[i];
			if (table.find(s) != table.end())
			{
				pair<int, int>* p = &table[s];
				p->second = i;
			}
		}
		vector<string> res;
		int sum = INT_MAX;
		for (auto t : table) {
			string s = t.first;
			pair<int, int> p = t.second;
			int index = p.first + p.second;
			if (index == sum)
			{
				res.push_back(s);
			}
			else if (index < sum)
			{
				sum = index;
				res.clear();
				res.push_back(s);
			}
		}
		return res;
	}
};