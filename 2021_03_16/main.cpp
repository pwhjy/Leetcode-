class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n));
        int top = 0,down = n-1,left = 0,right = n-1;
        int num = 0;
        while(num!=n*n){
            for(int i =left;i<=right;++i){
                ret[top][i] = ++num;
            }
            for(int i = top+1;i<=down;++i){
                ret[i][right] = ++num;
            }
            for(int i = right-1;i>=left;--i){
                ret[down][i] = ++num;
            }
            for(int i = down-1;i>top;--i){
                ret[i][left] = ++num;
            }
            ++top;
            --down;
            ++left;
            --right;
        }
        return ret;
    }
};