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
    ListNode* swapPairs(ListNode* head) {
        // if no head or single node then return
        if (!head || !head->next)
            return head;

        // curr
        ListNode* currNode = head;
        // next
        ListNode* nextNode = head->next;
        // rem list head for rec call
        ListNode* rem;
        // new head after swapping
        head = nextNode;

        // swap nodes if applicable
        if (currNode && nextNode) {
            // change links
            currNode->next = nextNode->next;
            ListNode* nextToNode = nextNode->next;
            nextNode->next = currNode;
            // store rem list head
            rem = nextToNode;
        }

        // 2nd node is now currNode after swapping
        // map its next to rec call ans 
        // head of rem swapped list
        currNode->next = swapPairs(rem);
        
        // return stored head
        return head;
    }
};