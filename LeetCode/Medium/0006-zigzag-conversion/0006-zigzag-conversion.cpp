class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows > s.size()) {
            return s;
        }

        // vector<vector<char> > v;
        // int i =0, n= s.size();
        // while(i<n){
        //     vector<char> t(numRows, '-');
        //     int j = 0;
        //     while(i<n && j<numRows){
        //         t[j] = s[i];
        //         j++;
        //         i++;
        //     }
        //     v.push_back(t);
        //     if(i==n)    break;
        //     j=numRows-2;
        //     while(j>0 && i<n){
        //         vector<char> t2(numRows, '-');
        //         t2[j] = s[i];
        //         i++;
        //         j--;
        //         v.push_back(t2);
        //     }
        // }
        // string ans = "";
        // for(int i =0; i<numRows;i++){
        //     for(int j = 0;j<v.size();j++){
        //         if(v[j][i] != '-')
        //             ans += v[j][i];
        //     }
        // }
        // return ans;

        // using vector of strings for simplicity
        vector<string> v(numRows, ""); // store per row
        int i = 0, n = s.size(), currRow = 0;
        bool isDown = 0; // track going down
        while (i < n) {
            // add s[i] to currRow string
            v[currRow] += s[i];
            // toggle for first and last rows
            if (currRow == 0 || currRow == numRows - 1) {
                isDown = !isDown;
            }
            // move i
            i++;
            // update currRow -> for down = currRow+1 else currRow-1
            currRow += isDown ? 1 : -1;
        }
        string ans = "";
        for (auto i : v) {
            // add to final ans
            ans += i;
        }
        return ans;
    }
};