class Solution {
public:
    string prepare(string num) {
        string ans = "";
        ans += num + "1";
        for (int i = 0; i < num.size(); i++) {
            num[i] = !(num[i] - '0') + '0';
        }
        reverse(num.begin(), num.end());
        ans += num;
        // cout<<num<<"->"<<ans<<endl;
        return ans;
    }

    // time: O(n * 2^n)
    // every time - str = str + "1" + rev(inv(str))
    // so each time len getting doubled
    // for n = 1 -> [0]
    // for n = 2 -> [011]
    // for n = 3 -> [0111001]
    // for n = 4 -> [011100110110001] ~ 15
    // space: O(2^n)
    // for each times: 1 + 2 + 4 + 8 + ... + 2^n
    // operations are inceasing with n
    // for each itr we are not doing 2^n from i = 1 -> n
    // so time is not O(N * 2^N) but O(2)
    char brute(int n, int k) {
        string num = "0";
        if (n <= 1) {
            return num[0];
        }

        for (int i = 1; i < n; i++) {
            num = prepare(num);
            // cout << num << endl;
        }
        return num[k - 1];
    }

    // recusrive
    // on observing for each loop
    // we can see that str + '1' + rev(inv(str))
    // so using binary seatch like approach we
    // can use total len of str and mid comparision with k
    // if mid = k then return '1' -> mid is always 1
    // if k < mid then left side -> return rec(n-1, k) [call rec for sub-prob]
    // if k > mid then in right side -> return inv(rec(n-1, len-k+1))
    // ie we are getting last kth bit and then inv it for ans
    // len = 2^n - 1
    // base condition is n = 1 return '0'
    // time: O(n)
    // space: O(n) // rec stack for n calls
    char recOpt(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int len = (1 << n) - 1; // (2^n - 1)
        int mid = (len + 1) / 2;

        if (mid == k) {
            // mid so '1'
            return '1';
        } else if (k < mid) {
            // left side
            return recOpt(n - 1, k);
        }

        // right side so invert ans
        char ans = recOpt(n - 1, len - k + 1);
        return !(ans - '0') + '0';
    }

    char findKthBit(int n, int k) {
        // return brute(n, k);
        return recOpt(n, k);
    }
};