class Solution {
public:
    int getRotDig(int d) {
        switch (d) {
        case 0:
            return d;
        case 1:
            return d;
        case 8:
            return d;
        case 2:
            return 5;
        case 5:
            return 2;
        case 6:
            return 9;
        case 9:
            return 6;
        defaul:
            return -1;
        }
        return -1;
    }
    bool isValidN(int n) {
        if (n < 10) {
            int rotDig = getRotDig(n);
            return rotDig != -1 && n != rotDig;
        }
        int rotDig = 0, m = 1;
        int t = n;
        while (n) {
            int d = n % 10;
            int r = getRotDig(d);
            if (r == -1)
                return 0;
            rotDig += m * r;
            n /= 10;
            m *= 10;
        }
        // cout << "getD: " << t << " " << rotDig << endl;
        return t != rotDig;
    }
    int brute(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool valid = isValidN(i);
            // cout << i << " " << valid << " " << ans << endl;
            if (valid) {
                ans++;
            }
        }
        return ans;
    }
    int rotatedDigits(int n) { return brute(n); }
};