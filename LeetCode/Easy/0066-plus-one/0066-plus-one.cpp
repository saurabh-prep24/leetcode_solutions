class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int c = 1;
        int i = 0, sum = 0;
        while (i < digits.size()) {
            sum = digits[i] + c;
            // cout<<sum<<endl;
            digits[i] = (sum) % 10;
            c = (sum) / 10;
            i++;
        }
        if (c > 0) {
            digits.push_back(c);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};