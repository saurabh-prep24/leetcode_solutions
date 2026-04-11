class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> elems;
        for (int i = 0; i < nums.size(); i++) {
            elems[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        int k;
        for (auto i : elems) {
            vector<int> pos = i.second;
            if (pos.size() >= 3) {
                for (k = 2; k < pos.size(); k++) {
                    // temp = min(temp, abs(pos[k - 2] - pos[k - 1]) +
                    //  abs(pos[k - 1] - pos[k]) +
                    //  abs(pos[k] - pos[k - 2]));
                    // i,j,k are increasing so
                    // k-j + j-i + k-i is abs
                    // = 2(k-i)
                    ans = min(ans, 2 * (pos[k] - pos[k - 2]));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};