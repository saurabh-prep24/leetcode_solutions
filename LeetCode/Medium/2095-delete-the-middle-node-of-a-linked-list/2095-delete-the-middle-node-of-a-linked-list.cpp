/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // slow
        ListNode* slow = head;
        // fast
        ListNode* fast = head;
        // prev to slow
        ListNode* prev = NULL;
        // travel fast to end of list
        while (fast && fast->next) {
            // store prev
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // if prev is still nil then return 
        // cases with no node or 1 node only
        if (!prev)
            return prev;

        // store slow
        ListNode* t = slow;
        // change links
        prev->next = slow->next;
        // remove slow
        delete (t);
        // return head
        return head;
    }
};