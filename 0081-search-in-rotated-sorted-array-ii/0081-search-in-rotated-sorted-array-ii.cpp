class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int low=0;
       int high = nums.size()-1;
       bool insorted=false;
       while(low<=high){
        int mid =(low+high)/2;
        if(nums[mid]==target){
            return true;
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
        }
        if(insorted==false){
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]){
                    insorted=true;
                    high = mid-1;
                    continue;
                }
                else{
                    low=mid+1;
                    continue;
                }
            }
            if(nums[mid]<=nums[high]){
                if(target>nums[mid] && target<=nums[high]){
                    insorted=true;
                    low=mid+1;
                    continue;
                }
                else{
                    high = mid-1;
                    continue;
                }
            }
        }

       }
       return false;
    }
};