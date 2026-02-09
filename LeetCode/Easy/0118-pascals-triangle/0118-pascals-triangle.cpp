class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows < 1) {
            return ans;
        }
        ans.push_back({1});

        vector<int> prev = ans[0];
        for (int i = 1; i < numRows; i++) {
            vector<int> curr;
            curr.push_back(1);
            for (int j = 1; j < prev.size(); j++) {
                curr.push_back(prev[j - 1] + prev[j]);
            }
            curr.push_back(1);
            prev = curr;
            ans.push_back(curr);
        }
        return ans;
    }
};