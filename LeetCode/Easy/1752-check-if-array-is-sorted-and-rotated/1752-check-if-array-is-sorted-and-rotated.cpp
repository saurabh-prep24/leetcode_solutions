class Solution {
public:
    // time: O(N*N logN)
    // space: O(N)
    bool brute(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        if (nums == sorted) {
            return 1;
        }
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
    // time: O(N)
    // space: O(1)
    bool check(vector<int>& nums) {
        int drops = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            // count drops where curr > next
            // for rotated - check last elem separately
            // or do (i+1)%N for next
            if (nums[i] > nums[(i + 1) % n]) {
                drops++;
            }
        }
        return drops <= 1;
    }
};