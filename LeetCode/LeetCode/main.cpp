#include "ExpressiveWords.h"
int main()
{
	Solution s;
	vector<string> words{ "dinnssoo", "ddinso", "ddiinnso", "ddiinnssoo", "ddiinso", "dinsoo", "ddiinsso", "dinssoo", "dinso" };
	int a =  s.expressiveWords("dddiiiinnssssssoooo", words);
	return 0;
}