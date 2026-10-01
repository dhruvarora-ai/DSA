class Solution {
public:
    int count_arrays(vector<int>& nums, int max_sum){
        int count = 1;
        int current_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(current_sum+ nums[i] >max_sum){
                count++;
                current_sum = nums[i];
            }
            else{
                current_sum+= nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans=low;
        while(low<=high){
            int mid = (low+high)/2;
            int arrays = count_arrays(nums,mid);
            if(arrays<=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};