class Solution {
public:
    bool isValidSerialization(string preorder) {
        int l = preorder.length();
        stack<int>q;
        q.push(1);
        int i = 0;
        while(i < l){
            if(q.empty()){
                return false;
            }
            else{
                if(preorder[i] == '#'){
                    q.top() -= 1;
                    if(q.top() == 0){
                        q.pop();
                    }
                    i++;
                } else if(preorder[i] == ','){
                    i++;
                } else {
                    while( i < l && preorder[i] != ','){
                        i++;
                    }
                    q.top() -= 1;
                    if(q.top() == 0){
                        q.pop();
                    }
                    q.push(2);
                }
            }
        }
        return q.empty();
    }
};