class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;
        int p1=0;
        while(p1<nums.size()){
            if(nums[p1]==1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt=0;
            }
            p1++;
        }
        return maxi;
    }
};