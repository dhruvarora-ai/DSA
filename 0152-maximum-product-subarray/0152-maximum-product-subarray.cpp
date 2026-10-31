class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i=0; i<nums.size(); i++){
            prefix = prefix* nums[i];
            suffix = suffix*nums[nums.size()-1-i];
            int maxi = max(prefix,suffix);
            max_product = max(max_product, maxi); 
            if(suffix==0){
                suffix = 1;
            }
            if(prefix ==0){
                prefix = 1;
            }
        }

        return max_product;
    }
};