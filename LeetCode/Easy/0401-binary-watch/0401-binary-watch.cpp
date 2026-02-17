class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        int hours[12]={0};
        int minutes[60]={0};
        for(int i = 0 ;i <12;i++){
            hours[i] = countSetBits(i);
        }
        for(int i = 0 ;i <60;i++){
            minutes[i] = countSetBits(i);
        }

        vector<string> ans ;
        for(int i =0; i<12;i++){
            for(int j=0;j<60;j++){
                if(hours[i]+minutes[j]==turnedOn){
                    string currH = to_string(i);
                    string currM = "";
                    if(j < 10){
                        currM += "0";
                    }
                    currM+=to_string(j);
                    ans.push_back(currH+":"+currM);
                }
            }
        }
        return ans;
    }
};