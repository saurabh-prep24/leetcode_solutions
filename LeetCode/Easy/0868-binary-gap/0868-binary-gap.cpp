class Solution {
public:
    int binaryGap(int n) {
        int i = 0;
        int j = 0;
        int ans = 0;
        bool found = 0;
        while (n) {
            int c = n & 1;
            // cout<<c<<" "<<i<<" "<<j<<" "<<ans<<endl;
            if (found && c == 1) {
                ans = max(ans, j - i);
                i = j;
            } else if (!found && c == 1) {
                i = j;
                found = 1;
            }
            j++;
            n = n >> 1;
        }
        return ans;
    }
};