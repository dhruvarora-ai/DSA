class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low1 = 0;
        int high1 = matrix.size()-1;
        int low2 = 0;
        int high2 = matrix[0].size()-1;
        bool in_target = false;
        bool found = false;
        while(low1<=high1){
            int mid1 = (low1+high1)/2;
            if(in_target){
                while(low2<=high2){
                    int mid2 = (low2+high2)/2;
                    if(matrix[mid1][mid2]==target){
                        found = true;
                        break;
                    }
                    else if(matrix[mid1][mid2]>target){
                        high2= mid2-1;
                    }
                    else{
                        low2 = mid2+1;
                    }
                }
                break;
            }

            if(matrix[mid1][low2]<=target && matrix[mid1][high2]>=target){
                in_target = true;
                continue;
            }
            else if(matrix[mid1][low2]>target){
                high1 = mid1-1;
            }
            else if(matrix[mid1][high2]<target){
                low1 = mid1+1;
            }
        }
        return found;
    }
};