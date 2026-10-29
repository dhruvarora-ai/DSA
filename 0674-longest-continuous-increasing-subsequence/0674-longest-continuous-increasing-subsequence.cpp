class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxl=1;
        int l =1;
        int p1 = 1;
        while(p1<nums.size()){
            if(nums[p1-1]<nums[p1]){
                l++;
                maxl = max(l, maxl);
            }
            else{
                l=1;
            }
            p1++;
        }
        return maxl;
    }
};