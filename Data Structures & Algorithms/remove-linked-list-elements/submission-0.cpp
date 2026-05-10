/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
            if (!head)
        return NULL;

    ListNode *dummy = new ListNode(-1);
    ListNode *curr = head;
    ListNode *p = dummy;
    p->next = curr;

    while (curr)
    {
        if (curr->val != val)
        {
            p = curr;
            curr = curr->next;
            continue;
        }
        ListNode *temp = curr;
        p->next = curr->next;
        curr = curr->next;
        delete (temp);
    }

    return dummy->next;
    }
};