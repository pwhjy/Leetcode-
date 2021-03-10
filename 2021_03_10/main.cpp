class Solution {
public:
    int calculate(string s) {
        int l = s.size();
        int i = 0;
        int sign = 1;//用来表示正负
        long sum = 0;
        stack<int>q;
        q.push(1);
        for(int i = 0; i < l; i++){
            if(s[i] == ' '){
                continue;
            } else if (s[i] == '+'){
                sign = q.top();
            } else if (s[i] == '-'){
                sign = -q.top();
            } else if (s[i] == '('){
                q.push(sign);
            } else if (s[i] == ')'){
                q.pop();
            } else{
                long temp = 0;
                while(i<l && s[i] >='0' && s[i]<='9' ){
                    temp = temp * 10 + s[i] - '0';//多位数所以需要*10
                    i++;
                }
                i--;
                sum += sign * temp;
            }
        }
        return sum;
    }
};