#pragma once
#include <vector>
#include <algorithm>
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
public:
	int countArrangement(int N) {
		vector<int> A(N);
		int i = 1;
		for_each(A.begin(), A.end(), [&](int &a) { a = i++; });
		return backtrack(N, A);
	}

	int backtrack(int N, vector<int>&A) {
		if (N == 0) return 1;
		int cnt = 0;
		for (int i = 0; i<N; i++)
			if (A[i] % N == 0 || N % A[i] == 0)
			{
				swap(A[i], A[N - 1]);
				cnt += backtrack(N - 1, A);
				swap(A[i], A[N - 1]);
			}
		return cnt;
	}
};