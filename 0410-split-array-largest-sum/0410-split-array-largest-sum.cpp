class Solution {
public:
    bool check(vector<int>& nums, int k, int max_sum){
        int current_sum = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(current_sum + nums[i]>max_sum){
                cnt++;
                current_sum = nums[i];
            }
            else{
                current_sum+= nums[i];
            }
        }
        if(cnt<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(),nums.end());
       int high = accumulate(nums.begin(),nums.end(),0);
       int ans = high;
       while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(nums,k,mid);
        if(possible){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
       } 
       return ans;
    }
};