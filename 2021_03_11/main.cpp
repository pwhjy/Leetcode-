class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};//官方答案

class Solution {
public:
    int calculate(string s) {
        int l = s.length();
        stack<int>q;
        int i = 0;
        long num = 0;
        char sign = '+';
        while (i < l){
            if (s[i] == ' '){
                i++;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                sign = s[i];
                i++;
            } else {
                while (i < l && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                if (sign == '-') {
                    num = -num;
                } else if (sign == '*') {
                    num = num * q.top();
                    q.pop();
                } else if (sign == '/') {
                    num = q.top() / num;
                    q.pop();
                }
                q.push(num);
                num = 0;
            }
            
        }
        long ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};//栈的方法
