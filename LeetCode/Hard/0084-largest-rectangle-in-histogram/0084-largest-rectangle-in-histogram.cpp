class Solution {
public:
    int brute(vector<int>& heights) {
        // area = h * (r-l)
        // r = next smaller than curr
        // r = prev smaller than curr
        // h = curr value

        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int l = i;
            int r = i;
            while (l >= 0 && heights[l] >= heights[i]) {
                l--;
            }
            while (r < n && heights[r] >= heights[i]) {
                r++;
            }

            int area = h * (r - l - 1);
            // cout << area << " " << h << " " << l << " " << r << " " <<
            // maxArea
            //      << endl;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.size() > 0 ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.size() > 0 ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    int opt(vector<int>& heights) {
        // area = h * (r-l)
        // r = next smaller than curr
        // r = prev smaller than curr
        // h = curr value

        int maxArea = 0;
        int n = heights.size();
        vector<int> prevSmallers = prevSmaller(heights);
        vector<int> nextSmallers = nextSmaller(heights);
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int l = prevSmallers[i];
            int r = nextSmallers[i];
            if (r == -1) {
                r = n;
            }

            int area = h * (r - l - 1);
            // cout << area << " " << h << " " << l << " " << r << " " <<
            // maxArea
            //      << endl;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        // brute
        // return brute(heights);
        return opt(heights);
    }
};