class Solution {
public:
    // same as: LC [2615]
    // preq: LC [1685]
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> posMap;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            posMap[arr[i]].push_back(i);
        }
        vector<long long> ans(n, 0);

        for (auto& i : posMap) {
            auto& v = i.second;
            vector<long long> prefix = v;
            int m = v.size();
            for (int j = 1; j < m; j++) {
                prefix[j] += prefix[j - 1];
            }

            for (int j = 0; j < m; j++) {
                long long s = 0;
                s += (prefix[m - 1] - prefix[j]) - (v[j] * (m - 1 - j));
                if (j > 0)
                    s += (v[j] * j) - (prefix[j - 1]);
                ans[v[j]] = s;
            }
        }
        return ans;
    }
};