class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // next greater elem - monotonic stack
        int n = temperatures.size();
        // store next greater elem index
        vector<int> nextGreater(n);
        // monotonic stack
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            // remove all smaller or equal top elem
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            // store for curr - as index diff is needed so (-i)
            nextGreater[i] = st.size() > 0 ? st.top() - i : 0;
            // push curr to stack
            st.push(i);
        }
        // return ans
        return nextGreater;
    }
};