class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int found = false;
        for(int i=0; i<matrix.size(); i++){
            int low = 0;
            int high = matrix[0].size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(matrix[i][mid]==target){
                    found = true;
                    break;
                }
                else if(matrix[i][mid]>target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(found==true){
                return true;
            }
        }
        return false;
    }
};