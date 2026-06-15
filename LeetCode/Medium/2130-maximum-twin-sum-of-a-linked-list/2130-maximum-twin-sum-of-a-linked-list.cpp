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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = head;
        while (currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* midRev = reverse(slow);
        int ans = INT_MIN;
        while (midRev) {
            ans = max(ans, head->val + midRev->val);
            midRev = midRev->next;
            head = head->next;
        }
        return ans;
    }
};