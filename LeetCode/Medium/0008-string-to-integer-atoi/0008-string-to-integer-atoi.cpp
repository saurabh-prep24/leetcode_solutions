class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int ans = 0;

        // skip leading space char
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n)
            return ans;

        // sign
        bool neg = 0;
        if (s[i] == '-') {
            neg = 1;
            i++;
        } else if (s[i] == '+')
            i++;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int dig = s[i] - '0';
            if (ans > (INT_MAX - dig) / 10 ||
                neg && ans < neg*(INT_MIN + dig) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + dig;
            i++;
        }
        return neg ? -ans : ans;
    }
};