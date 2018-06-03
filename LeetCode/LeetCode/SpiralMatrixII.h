#pragma once
#include "public.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> result;

		for (size_t i = 0; i < n; i++)
		{
			vector<int> tmp(n);
			result.push_back(tmp);
		}

		int time = 0;
		int num = 1;
		for (int i = n; i > 0;)
		{
			// right
			for (int j = 0; j < n - 2 * time; j++)
			{
				result[time][time + j] = num;
				num++;
			}

			// down

			for (int j = 0; j < n - 2 * time - 1; j++)
			{
				result[time + j + 1][n - 1 - time] = num;
				num++;
			}

			// left

			for (int j = 0; j < n - 2 * time - 1; j++)
			{
				result[n - 1 - time][n - 2 - time - j] = num;
				num++;
			}

			// up

			for (int j = 0; j < n - 2 * time - 2; j++)
			{
				result[n - 2 - time - j][time] = num;
				num++;
			}

			i -= 2;
			time++;
		}
	
		return result;
	}
};