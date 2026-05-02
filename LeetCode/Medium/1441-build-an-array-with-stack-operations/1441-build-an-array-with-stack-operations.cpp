class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int curr = 0;
        while (curr < target.size()) {
            for (int i = 1; i <= n; i++) {
                st.push(i);
                ans.push_back("Push");
                if (st.top() != target[curr]) {
                    st.pop();
                    ans.push_back("Pop");
                } else {
                    curr++;
                }
                if (curr == target.size())
                    break;
            }
        }
        return ans;
    }
};