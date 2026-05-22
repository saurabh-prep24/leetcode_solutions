class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, n = nums.size(), j = n - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;

            if (nums[m] == target) {
                // mid
                return m;
            } else if (nums[i] <= nums[m]) {
                if (target < nums[m] && target >= nums[i]) {
                    j = m - 1;
                } else
                    i = m + 1;
            } else {
                if (target > nums[m] && target <= nums[j]) {
                    i = m + 1;
                } else {
                    j = m - 1;
                }
            }
        }
        return -1;
    }
};
// 3
// 0,1,2,3,4,5,6 - a[m]
// 6,0,1,2,3,4,5 - t > a[m] && a
// 5,6,0,1,2,3,4
// 4,5,6,0,1,2,3
// 3,4,5,6,0,1,2
// 2,3,4,5,6,0,1
// 1,2,3,4,5,6,0