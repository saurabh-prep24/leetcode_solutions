class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int curr, vector<int> &temp){
        if(curr>=nums.size()){
            ans.push_back(temp);
            return;
        }
        // cout<<curr+1<<endl;
        helper(nums, ans, curr+1, temp);
        temp.push_back(nums[curr]);
        helper(nums, ans, curr+1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, ans, 0, temp); 
        return ans;
    }
};