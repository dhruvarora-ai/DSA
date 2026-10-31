class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        int index = -1;
        bool insorted = false;
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]==target){
                index=mid;
                break;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(insorted){
                if(nums[mid]>target){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]){
                    insorted = true;
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid]<=nums[high]){
                if(nums[mid]<target && nums[high]>=target){
                    insorted = true;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        if(index!=-1){
            return true;
        }
        return false;
    }
};