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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow;
        newHead = myReverse(newHead);
        while(head != NULL && newHead != NULL)
        {
            if(head->val != newHead->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
    ListNode* myReverse(ListNode* head)
    {
        if(head == NULL) return NULL;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            ListNode* tmp = fakeHead->next;
            fakeHead->next = tail->next;
            tail->next= tail->next->next;
            fakeHead->next->next = tmp;
        }
        return fakeHead->next;
    }
};
