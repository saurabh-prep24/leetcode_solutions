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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Time: O(n)
        // Space: O(n) - can be opt by using one of input LL but not needed here
        // dummy node
        ListNode * dummy = new ListNode(-1);
        // tail of new LL
        ListNode * tail = dummy;
        // carry
        int c= 0;
        // loop till any node or carry is present
        while(l1 || l2 || c>0){
            // sum of curr node data
            int sum = c;

            // add l1 node val and move l1
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            // add l2 node val and move l2
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            // create new node with sum
            ListNode* temp = new ListNode(sum%10);
            // move tail
            tail->next = temp;
            tail = tail->next;
            // update carry
            c = sum/10;
        }
        // delete dummy node from memory
        ListNode * ans = dummy->next;
        delete(dummy);

        // return ans
        return ans;
    }
};