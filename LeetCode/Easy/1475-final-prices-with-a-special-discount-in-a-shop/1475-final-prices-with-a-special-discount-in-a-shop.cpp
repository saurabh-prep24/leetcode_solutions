class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // same as NextSmaller elem - monotonic stack
        int n = prices.size();
        // next smaller elem
        vector<int> nextSmaller(n);
        // monotonic inc stack
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            // remove all greater elem on top
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            // store next smaller for curr elem
            nextSmaller[i] = st.size() > 0 ? st.top() : 0;
            // push curr elem to st
            st.push(prices[i]);
        }
        // ans arr - can be replaced by nextSmaller but as n<=500 not much diff
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // store (price-discount)
            ans.push_back(prices[i] - nextSmaller[i]);
        }
        return ans;
    }
};