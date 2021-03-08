class Solution {
public:
    int minCut(string s) {
        int l = s.length();//得到字符串长度
        vector<vector<int>> ans(l, vector<int>(l, true));
        //ans向量用来建立分析s[i,j]是否为回文串
        for(int i = l-1; i >= 0; i--){
            for(int j = i+1; j < l; j++){
                ans[i][j] = (s[i]==s[j]) && (ans[i+1][j-1]);
            }
        }
        //dp计算最小值
        int f[2005];
        memset(f,10000,sizeof(f));
        for(int i = 0; i < l; i++){
            if(ans[0][i]){
                f[i] = 0;
            }
            else{
                for(int j = 0; j < i; j++){
                    if(ans[j+1][i]){
                        f[i]=min(f[i],f[j]+1);
                    }
                }
            }
        }
        return f[l-1];
    }
};