class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ans = "";
        int c = 0;
        while (i >= 0 || j >= 0 || c > 0) {
            int s = c;
            if (i >= 0) {
                s += a[i]-'0';
                i--;
            }
            if (j >= 0) {
                s += b[j]-'0';
                j--;
            }
            cout<<s<<endl;
            ans = to_string(s % 2)+ans;
            c = s / 2;
        }
        cout << ans << endl;
        return ans;
    }
};