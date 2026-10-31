class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        bool insorted = false;
        int index=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                index=mid;
                break;
            }
            if(insorted){
                if(nums[mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid]){
                    high = mid-1;
                    insorted = true;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]<=nums[high]){
                if(nums[mid]<target && nums[high]>=target){
                    low=mid+1;
                    insorted=true;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return index;
    }
};