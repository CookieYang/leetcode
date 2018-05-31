#pragma once

#include "public.h"

using namespace std;

class Solution {
public:
	bool validTicTacToe(vector<string>& board)
	{
		int xW = 0;
		int oW = 0;
		int numX = 0;
		int numO = 0;
		for (int i = 0; i<board.size(); i++)
		{
			for (int j = 0; j<board[i].size(); j++)
			{
				checkSet(board[i][j], numX, numO);
			}

			if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
				checkSet(board[0][i], xW, oW);
			if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
				checkSet(board[i][0], xW, oW);
		}
		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
			checkSet(board[1][1], xW, oW);
		if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
			checkSet(board[1][1], xW, oW);

		return (numX == numO && xW == 0) || (numX == numO + 1 && oW == 0);
	}

	void checkSet(char v, int& x, int& o)
	{
		if (v == 'X')
			x++;
		else if (v == 'O')
			o++;
	}
};