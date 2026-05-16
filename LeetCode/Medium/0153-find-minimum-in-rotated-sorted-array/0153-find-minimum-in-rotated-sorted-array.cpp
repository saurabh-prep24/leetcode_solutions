class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int i = 0, n = nums.size(), j = n - 1;
        int m;
        while (i < j) {
            m = i + (j - i) / 2;
            if (nums[m] < nums[j]) {
                j = m;
            } else {
                i = m + 1;
            }
        }
        return nums[i];
    }
};