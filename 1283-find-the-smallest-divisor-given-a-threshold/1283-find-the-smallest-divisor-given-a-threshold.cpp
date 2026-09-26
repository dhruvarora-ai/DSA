class Solution {
public:
    bool check(vector<int>& nums, int threshold, int mid){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%mid==0){
                sum+= nums[i]/mid;
            }
            else{
                sum+= nums[i]/mid +1;
            }
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
      int low = 1;
      int high = *max_element(nums.begin(),nums.end());
      int ans=-1;
      while(low<=high){
        int mid = (low+high)/2;
        bool possible = check(nums,threshold, mid);
        if(possible){
            ans=mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return ans;
    }
};