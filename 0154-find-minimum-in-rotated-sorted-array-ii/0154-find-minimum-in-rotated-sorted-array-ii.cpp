class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                mini =min(mini,nums[mid]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                mini = min(nums[low],mini);
                low = mid+1;
            }
            else if(nums[mid]<=nums[high]){
                mini = min(nums[mid],mini);
                high = mid-1;
            }
        }
        return mini;
    }
};