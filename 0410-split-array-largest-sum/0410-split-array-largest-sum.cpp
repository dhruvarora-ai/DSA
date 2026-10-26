class Solution {
public:
    bool check(vector<int>& nums, int max_sum, int k){
        int sum =nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(sum+nums[i]>max_sum){
                sum = nums[i];
                cnt++;
            }
            else{
                sum+= nums[i];
            }
        }
        if(cnt>k){
            return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(nums,mid,k);
            if(possible){
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