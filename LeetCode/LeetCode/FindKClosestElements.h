#pragma once
#include "public.h"
using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		auto b = arr.begin(), e = arr.end(), l = b, r = e;
		tie(l, r) = equal_range(b, e, x);
		while (r - l < k)
			l == b || r < e && x - *(l - 1) > *r - x ? ++r : --l;
		return vector<int>(l, min(l + k, r));
	}
};