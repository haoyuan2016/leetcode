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
        while(head != NULL && head->next != NULL)
        {
            while(head->next != NULL && head->next->val == head->val)
                head->next = head->next->next;
            head = head->next;
        }
        return fakeHead->next;
    }
};
