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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* ptrHead = head;
        ListNode* tail = head->next;
        
        while(tail != NULL && tail->next != NULL)
        {
            ListNode* tmp = ptrHead->next;
            ptrHead->next = tail->next;
            tail->next = tail->next->next;
            ptrHead->next->next = tmp;
            tail = tail->next;
            ptrHead = ptrHead->next;
        }
        return head;
    }
};
