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
    ListNode* rotateRight(ListNode* head, int k) {
        // no head or single node then return
        if (!head || !head->next) {
            return head;
        }
        // count nodes
        int n = 0;
        ListNode* t = head;
        while (t) {
            t = t->next;
            n++;
        }
        // normalise k inside n
        k = k % n;
        if (k == 0) {
            return head;
        }
        // reach (n-k)th node from start
        t = head;
        int c = 1;
        while (t && c < n - k) {
            t = t->next;
            c++;
        }
        // store tail, newHead, prevHead, temp before changing links
        ListNode* tail = t;
        ListNode* newHead = t->next;
        ListNode* temp = t->next;
        ListNode* prevHead = head;
        // last node points to nil
        t->next = NULL;
        // move broken list end
        while (temp->next) {
            temp = temp->next;
        }
        // join broken list to original head
        temp->next = prevHead;
        // return new head for ans
        return newHead;
    }
};