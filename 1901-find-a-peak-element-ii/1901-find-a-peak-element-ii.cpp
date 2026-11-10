class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int low = 0;
       int high = mat[0].size()-1;
       while(low<=high){
        int mid  = (low+high)/2;
        int maxi = INT_MIN;
        int max_row = 0;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][mid]>maxi){
                maxi = mat[i][mid];
                max_row = i;
            }
        }
        int left = -1;
        int right = -1;
        if(mid>0){
            left = mat[max_row][mid-1];
        }
        if(mid<mat[0].size()-1){
            right = mat[max_row][mid+1];
        }
        if(maxi>left && maxi>right){
            return {max_row,mid};
        }
        else if(maxi<left){
            high = mid-1;
        }
        else if(maxi<right){
            low=mid+1;
        }
       }
       return {-1,-1};
    }
};