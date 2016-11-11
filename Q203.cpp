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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr = fakeHead;
        while(ptr != NULL)
        {
            while(ptr->next && ptr->next->val == val)
            {
                if(ptr->next->next)
                    ptr->next = ptr->next->next;
                else
                {
                    ptr->next = NULL;
                    return fakeHead->next;
                }
            }
            ptr = ptr->next;
        }
        return fakeHead->next;
    }
};
