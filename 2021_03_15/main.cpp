class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0, left = 0, bottom = m, right = n; 
        int i = 0, j = 0;
        while(ans.size() < m * n){
            top++;
            while(i < right && ans.size() < m * n){
                ans.push_back(matrix[j][i]);
                i++;
            }
            j++,i--;
            right--;
            while(j < bottom && ans.size() < m * n){
                ans.push_back(matrix[j][i]);
                j++;
            }
            bottom--;
            j--;i--;
            while(i >= left && ans.size() < m * n){
                ans.push_back(matrix[j][i]);
                i--;
            }
            i++;j--;
            left++;
            while(j >= top && ans.size() < m * n){
                ans.push_back(matrix[j][i]);
                j--;
            }
            i++,j++;
        }
        return ans;
    }
};