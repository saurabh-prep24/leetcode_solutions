class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hashmap for visited elem and find counter part [targe-curr] in map
        unordered_map<int, int> st; // map[elem] -> index
        for (auto i = 0; i < nums.size(); i++) {
            // check if counter part exists in map
            if (st.find(target - nums[i]) != st.end()) {
                // return index of both elems
                return {st[target - nums[i]], i};
            }
            // add curr elem mapped to i
            st[nums[i]] = i;
        }
        // empty
        return {};
    }
};