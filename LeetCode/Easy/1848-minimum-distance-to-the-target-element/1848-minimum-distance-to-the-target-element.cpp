class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start, j = start, n = nums.size();
        int ans = INT_MAX;
        while (i >= 0 || j < n) {
            if (i >= 0 && nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
            if (j < n && nums[j] == target) {
                ans = min(ans, abs(j - start));
            }
            i--;
            j++;
            if(ans != INT_MAX){
                break;
            }
        }
        return ans;
    }
};