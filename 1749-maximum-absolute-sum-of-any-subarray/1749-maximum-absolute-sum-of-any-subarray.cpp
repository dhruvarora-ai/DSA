class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini = INT_MAX;
        int sum1 =0;
        for(int i=0; i<nums.size(); i++){
            sum1+= nums[i];
            mini = min(sum1, mini);
            if(sum1>0){
                sum1=0;
            }
        }
        int maxi =INT_MIN;
        int sum2 = 0;
        for(int i=0; i<nums.size(); i++){
            sum2+= nums[i];
            maxi = max(maxi, sum2);
            if(sum2<0){
                sum2=0;
            }
        }
        return max(maxi, abs(mini));
    }
};