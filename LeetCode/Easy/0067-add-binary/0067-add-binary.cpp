class Solution {
public:
    // Time: O(N)
    // Space: O(1)
    string addBinary(string a, string b) {
        // store ans
        string ans = "";
        // carry
        int c = 0;
        // start from last to avoid reverse saves O[n]
        int i = a.size() - 1, j = b.size() - 1;
        // loop till any rem dig or c > 0
        while (i >= 0 || j >= 0 || c > 0) {
            // curr sum of dig
            int s = c;
            if (i >= 0) {
                s += a[i]-'0';
                i--;
            }
            if (j >= 0) {
                s += b[j]-'0';
                j--;
            }
            // update ans 
            ans = to_string(s % 2)+ans;
            // update carry
            c = s / 2;
        }
        // return ans
        return ans;
    }
};