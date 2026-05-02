class Solution {
public:
    int calculate(int a, int b, string op) {
        if (op == "+")
            return a + b;
        else if (op == "-")
            return a - b;
        else if (op == "*")
            return a * b;
        else if (op == "/")
            return a / b;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> digits;
        for (auto i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int top1 = digits.top();
                digits.pop();
                int top2 = digits.top();
                digits.pop();
                int temp = calculate(top2, top1, i);
                digits.push(temp);
            } else {
                digits.push(stoi(i));
            }
        }
        int ans = digits.top();
        digits.pop();
        return ans;
    }
};