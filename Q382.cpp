// Solution one: by calculating the length of the single list;
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* ptr = head;
        fake_head = head;
        while(ptr)
        {
            ptr = ptr->next;
            length++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int a = rand() % length;
        ListNode* tmp = fake_head;
        while(a)
        {
            a--;
            tmp = tmp->next;
        }
        return tmp->val;
    }
private:
    int length = 0;
    ListNode* fake_head = NULL;
};
// solution two: using probability.
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* ptr = head;
        int cur = 1;
        int tmp = head->val;
        while(ptr->next)
        {
            ptr = ptr->next;
            cur++;
            if(rand() % cur == cur - 1) tmp = ptr->val;
        }
        return tmp;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
