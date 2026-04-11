class Solution {
public:
    int getDist(vector<int>& v) {
        int i = 0, j = 1, k = 2;
        int d = INT_MAX;
        while (k < v.size()) {
            int s = abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[i]);
            d = min(d, s);
            k++;
            j++;
            i++;
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