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
    ListNode* solve1(ListNode* head, int k) {
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

    // make LL circular instead of breaking in 2 parts
    ListNode* solve2(ListNode* head, int k) {
        // no head or single node then return
        if (!head || !head->next) {
            return head;
        }
        // count nodes
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        // normalise k inside n
        k = k % n;
        if (k == 0) {
            return head;
        }

        // make circular
        tail->next = head;

        // move to (n-k)th node
        int c = 1;
        ListNode* t = head;
        while (c < n - k) {
            t = t->next;
            c++;
        }
        // store newhead and point last node to null
        ListNode* newHead = t->next;
        t->next = NULL;
        // return new head
        return newHead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        // return solve1(head, k);
        return solve2(head, k);
    }
};