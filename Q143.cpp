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
    void reorderList(ListNode*& head) {
        if(head == NULL) return;
        if(head->next == NULL || head->next->next == NULL) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverse(slow->next);
        slow->next = NULL;
        ListNode* fakeHead = new ListNode(0);
        ListNode* tmp = fakeHead;
        while(fast != NULL)
        {
            tmp->next = head;
            head = head->next;
            tmp = tmp->next;
            tmp->next = fast;
            fast = fast->next;
            tmp = tmp->next;
        }
        tmp->next = head;
        head = fakeHead->next;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL) return NULL;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr = fakeHead;
        ListNode* tail = ptr->next;
        while(tail->next != NULL)
        {
            ListNode* tmp = ptr->next;
            ptr->next = tail->next;
            tail->next = ptr->next->next;
            ptr->next->next = tmp;
        }
        return fakeHead->next;
    }
};
