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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *curr = dummy, *pre = dummy, *nex = dummy;
        int ctr = 0;

        while (curr->next != NULL)
        {
            curr = curr->next;
            ctr++;
        }

        while (ctr >= k)
        {
            curr = pre->next;
            nex = curr->next;
            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            ctr -= k;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};