#pragma once
#include "public.h"
using namespace std;

class Solution {
public:
	// prefix sum
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		unordered_map<int, int> prefixSum;
		int sum = 0;
		prefixSum[0] = 1;
		for (auto& num : nums) {
			sum += num;
			if (prefixSum[sum - k])
			{
				res += prefixSum[sum - k];
			}
			prefixSum[sum]++;
		}
		return res;
	}
};
