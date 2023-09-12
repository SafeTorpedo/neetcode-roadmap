#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        ListNode *ptr;
        if (list1->val > list2->val)
        {
            ptr = list2;
            list2 = list2->next;
        }
        else
        {
            ptr = list1;
            list1 = list1->next;
        }
        ListNode *current = ptr;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 == NULL)
            current->next = list2;
        else
            current->next = list1;

        return ptr;
    }
};