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
    void reorderList(ListNode *head)
    {
        if (head->next == NULL)
            return;

        // finding mid
        ListNode *temp = head, *middle = head, *previous = NULL;
        while (temp->next != NULL && temp->next->next != NULL)
        {
            temp = temp->next->next;
            previous = middle;
            middle = middle->next;
        }

        if (temp->next != NULL)
        {
            previous = middle;
            middle = middle->next;
        }
        previous->next = NULL;

        // reversing 2nd half
        ListNode *prev = NULL, *curr = middle, *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // merging both halves
        while (head != NULL && prev != NULL)
        {
            temp = head->next;
            next = prev->next;
            head->next = prev;

            if (temp == NULL)
                prev->next = next; // for odd length lists
            else
                prev->next = temp;

            head = temp;
            prev = next;
        }
    }
};