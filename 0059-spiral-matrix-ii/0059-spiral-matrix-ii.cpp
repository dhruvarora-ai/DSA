class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n, vector<int>(n));
        int top = n-1;
        int bottom =0;
        int left = 0;
        int right = n-1;
        int element = 1;
        while(left<=right || bottom<=top){
            for(int i=left; i<=right; i++){
                v[bottom][i]=element;
                element++;
            }   
            bottom++;
            for(int i=bottom; i<=top; i++){
                v[i][right] = element;
                element++;
            }
            right--;
            if(top>=bottom){
                for(int i=right; i>=left; i--){
                    v[top][i] = element;
                    element++;
                }
                top--;
            }
            if(left<=right){
                for(int i=top; i>=bottom; i--){
                    v[i][left] = element;
                    element++;
                }
                left++;
            }

        }
        return v;
    }
};