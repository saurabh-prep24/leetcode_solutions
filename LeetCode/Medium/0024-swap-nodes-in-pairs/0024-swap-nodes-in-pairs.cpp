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
    // time: O(n)
    // space: (n) // rec stack
    ListNode* rec(ListNode* head) {
        // if no head or single node then return
        if (!head || !head->next)
            return head;

        // [1 -> 2 -> 3 -> 4]
        //  h    t
        // [2 -> 1 -> | 3 -> 4]
        // t     h.   rec() - new head from rec
        // t = h->next
        // h->next = rec(t->next)
        // t->next = h
        // return t
        ListNode* nextNode = head->next;
        // point rec ans to head->next
        head->next = rec(head->next->next);
        // swap next node with head
        nextNode->next = head;
        // return nextNode as new head
        return nextNode;
    }

    // time: O(n)
    // space: O(1)
    ListNode* dummySwap(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummyHead = new ListNode();
        ListNode* prev = dummyHead;
        ListNode* curr = head;
        // [0] - P
        // [1(c) -> 2 -> 3 -> 3]
        // p->n = c->n
        // c->n = c->n->n
        // p->n->n = c
        // [0P -> 2 -> 1C -> 3 -> 4]
        // move
        // p = c
        // c= c->n
        while (curr && curr->next) {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }
        return dummyHead->next;
    }
    ListNode* swapPairs(ListNode* head) {
        // return rec(head);
        return dummySwap(head);
    }
};