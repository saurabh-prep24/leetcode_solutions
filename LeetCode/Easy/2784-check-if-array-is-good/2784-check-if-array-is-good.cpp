class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[n - 1] != n - 1 && nums[n - 1] != nums[n - 2]) {
            return 0;
        }

        for (int i = 0; i < n-1; i++) {
            if (nums[i] != i + 1)
                return 0;
        }
        return 1;
    }
};