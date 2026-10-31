class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing = -1;
        int repeating = -1;
        int n = nums.size();
        long long sum_n =1LL* (n*(n+1))/2;
        long long sumsq_n = 1LL*n*(n+1)*(2LL*n+1)/6;
        long long s1 = 0;
        for(int i=0; i<nums.size(); i++){
            s1+= nums[i];
        }
        int x = s1 - sum_n;
        long long ss1 = 0;
        for(int i=0; i<nums.size(); i++){
            ss1+= 1ll* nums[i]*nums[i];
        } 
        int y = (ss1 - sumsq_n)/x;
        repeating = (x+y)/2;
        missing = y - repeating;
        return {repeating,missing};

    }
};