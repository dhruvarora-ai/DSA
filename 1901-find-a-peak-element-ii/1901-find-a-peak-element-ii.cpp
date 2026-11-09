class Solution {
public:
    int max_index(vector<vector<int>>& mat,  int col){
        int maxi =-1;
        int row = -1;
        for(int i=0; i<mat.size(); i++){
            if(maxi<mat[i][col]){
                maxi = mat[i][col];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int large_index = max_index(mat,mid);
            int left =-1;
            int right = -1;
            if(mid>0){
                left = mat[large_index][mid-1];
            }
            if(mid<mat[0].size()-1){
                right = mat[large_index][mid+1];
            }

            if(mat[large_index][mid]>left && mat[large_index][mid]>right){
                return {large_index,mid};
            }
            else if(mat[large_index][mid]<left){
                high = mid-1;
            }
            else if(mat[large_index][mid]<right){
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};