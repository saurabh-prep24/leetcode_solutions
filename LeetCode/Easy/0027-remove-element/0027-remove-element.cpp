class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int st = -1;
        // first occurrence
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                st = i;
                break;
            }
        }

        // if val not found return full arr size
        if (st == -1) {
            return nums.size();
        }

        // remove all val with forward elems
        for (int j = st + 1; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[st] = nums[j];
                st++;
            }
        }
        return st;
    }
};