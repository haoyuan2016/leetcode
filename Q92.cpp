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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* ptr = fakeHead;
        int num = m;
        while(num > 1)
        {
            ptr = ptr->next;
            num--;
        }
        int rotates = 0;
        ListNode* tail = ptr->next;
        while(n - m > rotates)
        {
            ListNode* tmp = ptr->next;
            ptr->next = tail->next;
            tail->next = tail->next->next;
            ptr->next->next = tmp;
            rotates++;
        }
        return fakeHead->next;
    }
};
