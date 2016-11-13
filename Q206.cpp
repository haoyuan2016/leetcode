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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr = fakeHead;
        
        ListNode* tail = ptr->next;
        while(tail->next != NULL)
        {
            ListNode* tmp = ptr->next;
            ptr->next = tail->next;
            tail->next = tail->next->next;
            ptr->next->next = tmp;
        }
        return fakeHead->next;
    }
};
