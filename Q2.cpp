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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fake_head = new ListNode(0);
        ListNode* ptr = fake_head;
        int carry = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int cur = l1->val + l2->val;
            ptr->next = new ListNode((cur + carry) % 10);
            ptr = ptr->next;
            carry = (cur + carry >= 10) ? 1 : 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL)
        {
            ptr->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry >= 10) ? 1 : 0;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while (l2 != NULL)
        {
            ptr->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry >= 10) ? 1 : 0;
            l2 = l2->next;
            ptr = ptr->next;
        }
        if(carry == 1)
            ptr->next = new ListNode(1);
        return fake_head->next;
    }
};

// Note: new ListNode() return a pointer, we can also use ListNode ptr = ListNode(0) to 'new' a real node, and then use & to fetch that pointer
