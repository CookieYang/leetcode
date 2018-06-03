#pragma once

#include "public.h"

using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		vector<vector<int>> subArrays;
		int res = 0;
		int sum = 0;
		int continuity = 0;
		vector<int> init;
		subArrays.push_back(init);
		bool bFlag = false;
		bool sFlag = false;
		for (int num : A)
		{
			if (num <= R && num >= L)
			{
				vector<int>& lastArr = subArrays[subArrays.size() - 1];
				lastArr.push_back(num);
				bFlag = false;
				sFlag = false;
			}
			else if (num > R)
			{
				if (!bFlag)
				{
					vector<int> otherArr;
					subArrays.push_back(otherArr);
				}
				bFlag = true;
				sFlag = false;
			}
			else
			{
				if (!sFlag)
				{
					sum += 0.5 * (1 + continuity) * continuity;
					continuity = 1;
				}
				else
				{
					continuity++;
				}
				vector<int>& lastArr = subArrays[subArrays.size() - 1];
				lastArr.push_back(num);
				sFlag = true;
				bFlag = false;
			}
		}

		if (continuity != 0)
		{
			sum += 0.5 * (1 + continuity) * continuity;
		}

		for (auto arr : subArrays) {
			if (arr.size() != 0)
			{
				res += 0.5 * (1 + arr.size()) * arr.size();
			}
		}

		return res - sum;
	}
};


class Solution2 {
	int countSeqsUnder(vector<int>&A, int limit) const {
		int count = 0, size = (int)A.size();
		if (size) {
			int nInSeq = 0, *pA = &A[0], *pe = pA + size;
			while (pA < pe) {
				nInSeq = *pA++ <= limit ? nInSeq + 1 : 0;
				count += nInSeq;
			}
		}
		return count;
	};
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) const {
		return countSeqsUnder(A, R) - countSeqsUnder(A, L - 1);
	};
};