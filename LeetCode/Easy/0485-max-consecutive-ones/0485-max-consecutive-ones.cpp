class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = -1, j = 0, n = nums.size();
        while (j <= n) {
            if (j < n && nums[j]) {
                if (i == -1) {
                    i = j;
                }
            } else if (i != -1) {
                ans = max(ans, j - i);
                i = -1;
            }
            j++;
        }
        return ans;
    }
};