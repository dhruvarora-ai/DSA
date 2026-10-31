class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int el = -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==low || mid==high){
                el = nums[mid];
                break;
            }
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                el = nums[mid];
                break;
            }
            if(nums[mid]==nums[mid-1]){
                if((mid+1)%2==0){
                    low=mid+1;
                }
                else{
                    high = mid-2;
                }
            }
            if(nums[mid]==nums[mid+1]){
                if((high-mid+1)%2==0){
                    high = mid-1;
                }
                else{
                    low=mid+2;
                }
            }
        }
        return el;
    }
};