class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // mark a[i-1] as - for visiting then add all + to ans
        vector<int> ans;
        for(auto i:nums){
            // duplicates can come so add abs while marking
            nums[abs(i)-1] = - abs(nums[abs(i)-1]);
        }
        // all pos are missing numbers
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};