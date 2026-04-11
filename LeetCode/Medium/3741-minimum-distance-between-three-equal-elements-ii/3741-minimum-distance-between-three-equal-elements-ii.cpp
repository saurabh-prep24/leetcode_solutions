class Solution {
public:
    int getDist(vector<int>& v) {
        int k = 2;
        int d = INT_MAX;
        while (k < v.size()) {
            int s = abs(v[k - 2] - v[k - 1]) + abs(v[k - 1] - v[k]) +
                    abs(v[k] - v[k - 2]);
            d = min(d, s);
            k++;
        }
        return d;
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> elems;
        for (int i = 0; i < nums.size(); i++) {
            elems[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto i : elems) {
            vector<int> pos = i.second;
            if (pos.size() >= 3) {
                ans = min(ans, getDist(pos));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};