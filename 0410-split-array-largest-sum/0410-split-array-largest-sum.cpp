class Solution {
public:
    int count_arrays(vector<int>& nums, int max_sum){
        int sum = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(sum+nums[i]>max_sum){
                count++;
                sum = nums[i];
            }
            else{
                sum+= nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid = (low+high)/2;
            int arrays = count_arrays(nums,mid);
            if(arrays>k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};