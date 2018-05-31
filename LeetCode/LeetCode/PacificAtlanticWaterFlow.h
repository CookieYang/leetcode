#pragma once
#include "public.h"

using namespace std;

class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> ans;
		int m = matrix.size();
		if (m == 0)
			return ans;
		int n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));

		for (int i = 0; i<m; i++)
		{
			pacific[i][0] = true;
			atlantic[i][n - 1] = true;
		}
		for (int j = 0; j<n; j++)
		{
			pacific[0][j] = true;
			atlantic[m - 1][j] = true;
		}

		for (int k = 0; k<2; k++)
		{
			for (int i = 0; i<m; i++)
			{
				for (int j = 0; j<n; j++)
				{
					if ((i>0 && pacific[i - 1][j] == true && matrix[i][j] >= matrix[i - 1][j]) || (j>0 && pacific[i][j - 1] == true && matrix[i][j] >= matrix[i][j - 1]))
					{
						pacific[i][j] = true;
					}
				}
			}

			for (int i = m - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{

					if (pacific[i][j] == false && (i<m - 1 && pacific[i + 1][j] == true && matrix[i][j] >= matrix[i + 1][j]) || (j<n - 1 && pacific[i][j + 1] == true && matrix[i][j] >= matrix[i][j + 1]))
					{
						pacific[i][j] = true;
					}
				}
			}
		}
		for (int k = 0; k<2; k++)
		{
			for (int i = m - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					if ((i<m - 1 && atlantic[i + 1][j] == true && matrix[i][j] >= matrix[i + 1][j]) || (j<n - 1 && atlantic[i][j + 1] == true && matrix[i][j] >= matrix[i][j + 1]))
					{
						atlantic[i][j] = true;
					}
				}
			}

			for (int i = 0; i<m; i++)
			{
				for (int j = 0; j<n; j++)
				{
					if (atlantic[i][j] == false && (i>0 && atlantic[i - 1][j] == true && matrix[i][j] >= matrix[i - 1][j]) || (j>0 && atlantic[i][j - 1] == true && matrix[i][j] >= matrix[i][j - 1]))
					{
						atlantic[i][j] = true;
					}
				}
			}
		}

		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (pacific[i][j] == true && atlantic[i][j] == true)
					ans.push_back(make_pair(i, j));
			}
		}
		return ans;
	}
};