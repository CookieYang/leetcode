#pragma once
#include "public.h"
#include "structs.h"
using namespace std;

class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA)
		{
			return headA;
		}
		if (!headB)
		{
			return headB;
		}

		int aLength = 1;
		int bLength = 1;

		ListNode* p1 = headA;
		while (p1->next != nullptr)
		{
			p1 = p1->next;
			aLength++;
		}
		ListNode* p2 = headB;
		while (p2->next != nullptr)
		{
			p2 = p2->next;
			bLength++;
		}

		ListNode* longList;
		ListNode* shortList;
		if (aLength > bLength)
		{
			longList = headA;
			shortList = headB;
		}
		else
		{
			longList = headB;
			shortList = headA;
		}

		int diff = abs(aLength - bLength);

		while (diff != 0)
		{
			longList = longList->next;
			diff--;
		}

		while (longList != shortList && longList != nullptr)
		{
			longList = longList->next;
			shortList = shortList->next;
		}

		return longList;
	}
};