class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > v;
        int i =0, n= s.size();
        while(i<n){
            vector<char> t(numRows, '-');
            int j = 0;
            while(i<n && j<numRows){
                t[j] = s[i];
                j++;
                i++;
            }
            v.push_back(t);
            if(i==n)    break;
            j=numRows-2;
            while(j>0 && i<n){
                vector<char> t2(numRows, '-');
                t2[j] = s[i];
                i++;
                j--;
                v.push_back(t2);
            }
        }
        string ans = "";
        for(int i =0; i<numRows;i++){
            for(int j = 0;j<v.size();j++){
                if(v[j][i] != '-')
                    ans += v[j][i];
            }
        }
        return ans;
    }
};