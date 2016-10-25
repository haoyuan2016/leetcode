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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr = fakeHead;
        while(ptr != NULL && ptr->next != NULL)
        {
            if(ptr->next->next && ptr->next->next->val == ptr->next->val)
            {
                int a = ptr->next->val;
                ListNode* tmp = ptr->next->next;
                while(tmp != NULL && tmp->val == a)
                    tmp = tmp->next;
                ptr->next = tmp;
            }
            else
                ptr = ptr->next;
        }
        return fakeHead->next;
    }
};
