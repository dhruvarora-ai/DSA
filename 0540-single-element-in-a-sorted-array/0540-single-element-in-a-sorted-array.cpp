class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-2;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        while(low<=high){
            if(low==high){
                return nums[low];
            }
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if(mid%2==1){
                    low = mid+1;
                }
                else{
                    high = mid-2;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==1){
                    high = mid-1;
                }
                else{
                    low=mid+2;
                }
            }
        }
        return -1;
    }
};