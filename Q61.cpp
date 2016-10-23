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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int lens = 1;
        ListNode* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
            lens++;
        }
        k = k % lens;
        if(k == 0)
            return head;
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr1 = fakeHead;
        ListNode* ptr2 = fakeHead;
        while(k != 0)
        {
            ptr1 = ptr1->next;
            k--;
        }
        while(ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode* tail = ptr2;
        while(tail->next != NULL)
            tail = tail->next;
        ListNode* tmp = fakeHead->next;
        fakeHead->next = ptr2->next;
        ptr2->next = NULL;
        tail->next = tmp;
        return fakeHead->next;
    }
};
