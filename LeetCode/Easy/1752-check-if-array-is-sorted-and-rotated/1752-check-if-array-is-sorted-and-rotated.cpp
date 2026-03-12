class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[0]) {
                // check remaining
                bool found = 1;
                for (int j = 0; j < n; j++) {
                    if (nums[(i + j) % n] != sorted[j]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    return found;
                }
            }
        }
        return false;
    }
};