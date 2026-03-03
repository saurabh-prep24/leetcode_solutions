class Solution {
public:
    string prepare(string num) {
        string ans = "";
        ans += num + "1";
        for (int i = 0; i < num.size(); i++) {
            num[i] = !(num[i]-'0') + '0';
        }
        reverse(num.begin(), num.end());
        ans += num;
        // cout<<num<<"->"<<ans<<endl;
        return ans;
    }
    char findKthBit(int n, int k) {
        string num = "0";
        if (n <= 1) {
            return num[0];
        }

        for (int i = 1; i < n; i++) {
            num = prepare(num);
            // cout << num << endl;
        }
        return num[k-1];
    }
};