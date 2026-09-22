class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        bool insorted= false;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(insorted==false){
                if(nums[low]<=nums[mid]){
                    if(target>=nums[low] && target<nums[mid]){
                        insorted=true;
                        high = mid-1;
                        continue;
                    }
                    else{
                        low=mid+1;
                        continue;
                    }
                }
                else if(nums[mid]<=nums[high]){
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
            if(insorted){
                if(nums[mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};