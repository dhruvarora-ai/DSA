class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left =0;
        int right = matrix[0].size()-1;
        int bottom = 0;
        int top = matrix.size()-1;
        vector<int>v;
        while(left<=right && bottom<=top){
            for(int i=left; i<=right; i++){
                v.push_back(matrix[bottom][i]);
            }
            bottom++;
            for(int i=bottom; i<=top; i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(bottom<=top){
                for(int i=right; i>=left; i--){
                    v.push_back(matrix[top][i]);
                }
                top--;
            }
            if(left<=right){
                for(int i= top; i>=bottom; i--){
                    v.push_back(matrix[i][left]);
                }
            left++;
            }
        }
        return v;
    }
};