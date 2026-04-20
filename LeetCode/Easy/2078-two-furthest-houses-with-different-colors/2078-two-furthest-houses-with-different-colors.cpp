class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (j >= 0 && colors[i] == colors[j]) {
                j--;
            } else {
                break;
            }
        }
        ans = max(ans, abs(j - i));

        i = 0, j = n - 1;
        while (i <= j) {
            if (i < n && colors[i] == colors[j]) {
                i++;
            } else {
                break;
            }
        }
        ans = max(ans, abs(j - i));
        return ans;
    }
};