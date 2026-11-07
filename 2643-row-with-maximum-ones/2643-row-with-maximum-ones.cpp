class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mat_zero =0;
        int index = 0;
        for(int i=0; i<mat.size(); i++){
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt>mat_zero){
                mat_zero = cnt;
                index = i;
            }
        }
        return {index,mat_zero};
    }
};