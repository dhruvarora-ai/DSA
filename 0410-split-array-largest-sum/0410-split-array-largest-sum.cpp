class Solution {
public:
    bool check(vector<int>& nums, int k, int max_sum){
        int sum=0;
        int count =1;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]>max_sum){
                count++;
                sum = nums[i];
            }
            else{
                sum+= nums[i];
            }
        }
        if(count<=k){
            return true;
        }
        else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
      int low = *max_element(nums.begin(),nums.end());
      int high = accumulate(nums.begin(),nums.end(),0);
      int ans=-1;
      while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(nums,k,mid);
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