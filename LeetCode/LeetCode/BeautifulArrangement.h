#pragma once
#include "public.h"
using namespace std;

class Solution {
public:
	int countArrangement(int N) {
		vector<vector<int>> possibilities;
		int res = 0;
		if (N == 0)
		{
			return res;
		}
		for (int i = 0; i < N; i++)
		{
			vector<int> tmp;
			for (int j = 1; j < N + 1; j++)
			{
				if (j % (i + 1) == 0 || (i + 1) % j == 0)
				{
					tmp.push_back(j);
				}
			}
			possibilities.push_back(tmp);
		}
		vector<int> used;
		DPS(possibilities, used, res, 0);
		return res;
	}

	void DPS(vector<vector<int>>& possibilities, vector<int>& used, int& res, int depth) {
		if (depth == possibilities.size())
		{
			res++;
			return;
		}
		vector<int> tmp = possibilities[depth];
		for (size_t i = 0; i < tmp.size(); i++)
		{
			if (find(used.begin(), used.end(), tmp[i]) == used.end())
			{
				used.push_back(tmp[i]);
				DPS(possibilities, used, res, depth + 1);
				used.pop_back();
			}
			else
			{
				continue;
			}
		}
		return;
	}
};

class Solution2 {
	int  counter(vector<int> &nums, int n)
	{
		if (0 >= n)
		{
			return 1;
		}

		int cnt = 0;
		for (int pos = 0; pos<n; pos++)
		{
			if ((0 == nums[pos] % n) || (0 == n % nums[pos]))
			{
				//cout<<"idx: "<<idx<<" nums[idx-1]: "<<nums[idx-1]<<" nums[pos]: "<<nums[pos]<<endl;
				swap(nums[pos], nums[n - 1]);
				cnt += counter(nums, n - 1);
				swap(nums[pos], nums[n - 1]);
			}
		}

		return cnt;
	}

public:
	int countArrangement(int N) {
		vector<int> nums;
		int cnt = 0;

		for (int n = 1; n <= N; n++)
		{
			nums.push_back(n);
		}

		cnt = counter(nums, N);

		return cnt;
	}
};