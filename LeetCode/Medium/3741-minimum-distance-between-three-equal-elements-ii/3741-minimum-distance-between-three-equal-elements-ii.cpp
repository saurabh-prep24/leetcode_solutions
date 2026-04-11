class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> elems;
        for (int i = 0; i < nums.size(); i++) {
            elems[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto i : elems) {
            vector<int> pos = i.second;
            if (pos.size() >= 3) {
                int temp = INT_MAX;
                for (int k = 2; k < pos.size(); k++) {
                    temp = min(temp, abs(pos[k - 2] - pos[k - 1]) +
                                         abs(pos[k - 1] - pos[k]) +
                                         abs(pos[k] - pos[k - 2]));
                    k++;
                }
                ans = min(ans, temp);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};