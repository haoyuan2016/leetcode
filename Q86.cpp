/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        ListNode* fakeHead1 = new ListNode(0);
        ListNode* fakeHead2 = new ListNode(0);
        ListNode* res1 = fakeHead1;
        ListNode* res2 = fakeHead2;
        while(head != NULL)
        {
            if(head->val < x)
            {
                fakeHead1->next = new ListNode(head->val);
                fakeHead1 = fakeHead1->next;
            }
            else
            {
                fakeHead2->next = new ListNode(head->val);
                fakeHead2 = fakeHead2->next;
            }
            head = head->next;
        }
        fakeHead1->next = res2->next;
        return res1->next;
    }
};
