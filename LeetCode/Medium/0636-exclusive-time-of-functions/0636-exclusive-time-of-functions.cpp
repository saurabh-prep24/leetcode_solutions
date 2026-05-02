class Solution {
public:
    struct E {
    public:
        int id;
        string op;
        int time;
        int chExecTime; // store child func exec time
    };

    // split by dem
    vector<string> split(string s, char dem) {
        vector<string> ans;
        string t = "";
        for (auto i : s) {
            if (i != dem) {
                t += i;
            } else {
                ans.push_back(t);
                t = "";
            }
        }
        if (t != "") {
            ans.push_back(t);
        }
        return ans;
    }
    // convert to event
    E convert(string s) {
        auto sp = split(s, ':');
        return
        E{id : stoi(sp[0]), time : stoi(sp[2]), op : sp[1], chExecTime : 0};
    }
    void print(E e) {
        cout << e.id << " " << e.op << " " << e.time << " " << e.chExecTime
             << endl;
    }

    // store all start events in stack
    // if there is any end event then calc durations
    // duration = currE.end - st.top().start + 1
    // remove if any chile exec time is present
    // pop the start even and add child exec time for next top start event
    // so parent can subtract all child exec times from its duration
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> execTimes(n, 0);
        stack<E> st;
        for (int i = 0; i < logs.size(); i++) {
            string curr = logs[i];
            E currEvent = convert(curr);
            if (currEvent.op == "start") {
                // push start events
                st.push(currEvent);
            } else {
                // for end events
                // pop curr top and calc durations
                // update chile exec duration to next top
                E startEvent = st.top();
                st.pop();
                // calc duration
                int duration = currEvent.time - startEvent.time + 1;
                // exclude child exec duration
                execTimes[currEvent.id] += duration - startEvent.chExecTime;
                if (st.size() > 0) {
                    // add duration to curr top child exec duration
                    st.top().chExecTime += duration;
                }
            }
        }
        // return ans
        return execTimes;
    }
};