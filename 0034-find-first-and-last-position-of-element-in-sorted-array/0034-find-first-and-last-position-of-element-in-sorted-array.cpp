class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target){
                    last = mid;
                }
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        int low1=0;
        int high1 = nums.size()-1;
        while(low1<=high1){
            int mid1 = (low1+high1)/2;
            if(nums[mid1]>=target){
                if(nums[mid1]==target){
                    first = mid1;
                }
                high1 = mid1-1;
            }
            else{
                low1=mid1+1;
            }
        }
        return {first,last};
    }
};