class Solution {
public:
    int max_idx(vector<vector<int>>& mat,int mid){
        int maxi = INT_MIN;
        int max_idx = -1;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][mid]>maxi){
                maxi = mat[i][mid];
                max_idx = i;
            }
        }
        return max_idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int low =0;
       int high = mat[0].size()-1;
       while(low<=high){
        int mid = (low+high)/2;
        int largest_idx = max_idx(mat,mid); 
        int left = -1;
        int right = -1;
        if(mid>0){
            left = mat[largest_idx][mid-1];
        }
        if(mid<mat[0].size()-1){
            right = mat[largest_idx][mid+1];
        }
        if(mat[largest_idx][mid]>left && mat[largest_idx][mid]>right){
            return {largest_idx,mid};
        }
        else if(mat[largest_idx][mid]<left){
            high = mid-1;
        }
        else if(mat[largest_idx][mid]<right){
            low = mid+1;
        }
       } 
       return {-1,-1};
    }
};