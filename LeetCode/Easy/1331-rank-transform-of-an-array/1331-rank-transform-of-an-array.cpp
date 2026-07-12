class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        // ordered map for sorted elems
        map<int, vector<int>> pos;
        // store all elem to index map
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
        // fill up rank in ans
        int rank = 1;
        for (auto i : pos) {
            for (auto j : i.second) {
                ans[j] = rank;
            }
            rank++;
        }
        return ans;
    }
};