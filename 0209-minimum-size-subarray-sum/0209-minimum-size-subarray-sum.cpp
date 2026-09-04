class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int p1 = 0;
        int p2 =0;
        int sum = nums[p2];
        int mini=INT_MAX;
        while(p2<nums.size()){

            if(sum>=target){
                mini = min(mini, p2-p1+1);
                sum = sum - nums[p1];
                p1++;
            }
            else if(sum<target){
                p2++;
                if(p2<nums.size()){
                    sum = sum + nums[p2];
                }
            }  
        }
        if(mini!=INT_MAX){
            return mini;
        }
        else{
            return 0;
        }
    }
};