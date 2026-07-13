class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int st = low, end = high;
        int minLen = 0, maxLen = 0;
        while (st) {
            minLen++;
            st /= 10;
        }
        while (end) {
            maxLen++;
            end /= 10;
        }
        cout << minLen << " " << maxLen << endl;
        vector<int> ans;
        for (int l = minLen; l <= maxLen; l++) {
            cout << "l:" << l << endl;
            for (int i = 1; i + l <= 10; i++) {
                long long d = pow(10, l - 1);
                long long c = 0;
                int j = i;
                while (d) {
                    c = j * d + c;
                    d /= 10;
                    j++;
                }
                cout << c << endl;
                if (c >= low && c <= high)
                    ans.push_back(c);
            }
        }
        return ans;
    }
};