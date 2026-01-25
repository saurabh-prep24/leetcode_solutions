class Solution {
public:
    // int getNum(char c){
    //     // cout<<c<<" "<<c-'0'<<endl;
    //     return c - '0';
    // }
    string addStrings(string num1, string num2) {
        // reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());

        // int i =0 , j=0;
        // string ans = "";
        // int c=0;
        // while(i<num1.size() && j<num2.size()){
        //     int s = getNum(num1[i])+getNum(num2[j])+c;
        //     ans += to_string(s%10);
        //     c = s/10;
        //     i++;
        //     j++;
        // }
        // while(i<num1.size()){
        //     int s = getNum(num1[i])+c;
        //     ans += to_string(s%10);
        //     c = s/10;
        //     i++;
        // }
        // while(j<num2.size()){
        //     int s = getNum(num2[j])+c;
        //     ans += to_string(s%10);
        //     c = s/10;
        //     j++;
        // }
        // if(c>0){
        //     ans+=to_string(c);
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;


        int i = num1.size()-1, j=num2.size()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry>0){
            int d1 = i>=0 ? num1[i]-'0' : 0;
            int d2 = j>=0 ? num2[j]-'0' : 0;

            int curr = d1 + d2 + carry;
            ans = to_string(curr%10)+ans;
            carry = curr/10;

            i--;
            j--;
        }
        return ans;
    }
};