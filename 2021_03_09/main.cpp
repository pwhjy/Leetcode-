class Solution {
public:
    string removeDuplicates(string S) {
        string stk;
        for (char ch : S) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};//官方C++版本答案

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>q;
        for(char str : S){
            if(!q.empty() && str==q.top()){
                q.pop();
            }else{
                q.push(str);
            }
        }
        string s="";
        while(!q.empty()){
            s+=q.top();
            q.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};//使用stack版本答案
