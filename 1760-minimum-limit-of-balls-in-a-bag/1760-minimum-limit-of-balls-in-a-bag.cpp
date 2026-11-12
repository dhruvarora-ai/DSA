class Solution {
public:
    bool check(vector<int>& nums, int max_balls, int max_operations){
        long long cnt_operations = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%max_balls==0){
                cnt_operations+= (nums[i]/max_balls) - 1;
            }
            else{
                cnt_operations+= (nums[i]/max_balls) ;
            }
        }
        if(cnt_operations<=max_operations){
            return true;
        }
        return false;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            bool possible = check(nums, mid, maxOperations);
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