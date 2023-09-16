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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        bool carry = false;

        while (l1 != NULL || l2 != NULL)
        {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            int sum = (carry) ? val1 + val2 + 1 : val1 + val2;
            carry = (sum > 9) ? true : false;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        if (carry)
            curr->next = new ListNode(1);

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};