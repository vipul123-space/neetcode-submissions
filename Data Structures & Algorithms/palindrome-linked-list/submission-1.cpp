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
int countNodes(ListNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
ListNode *reverseList(ListNode *head)
{
    ListNode *r = NULL;
    ListNode *q = NULL;
    ListNode *p = head;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;

    return head;
}

    bool isPalindrome(ListNode* head) {
            int length = countNodes(head);
            if(length==1)return true;
    int mid = length / 2;

    ListNode *middleNode = head;
    for (int i = 0; i < mid - 1; i++)
        middleNode = middleNode->next;

    ListNode *secondHalf = (length % 2 == 0) ? middleNode->next : middleNode->next->next;
    ListNode *revList = reverseList(secondHalf);

    while (revList)
    {
        if (head->val != revList->val)
            return false;

        head = head->next;
        revList = revList->next;
    }
    return true;
    }
};