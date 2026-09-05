class Solution {
public:
    int sum_division(int divisor, vector<int>& nums){
        int sum = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]%divisor==0){
                sum=sum+ (nums[i]/divisor);
            }
            else{
                sum+= (nums[i]/divisor) + 1;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
      int low = 1;
      int high = *max_element(nums.begin(), nums.end());  
      int ans=0;
      while(low<=high){
        int mid = (low+high)/2;
        int sum = sum_division(mid,nums);
        if(sum<=threshold){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return ans;
    }
};