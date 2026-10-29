class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v;
        for(int i =0; i<nums.size(); i++){
            if(i%2==0){
                v.push_back(1);
            }
            else{
                v.push_back(-1);
            }
        }
        int p1 =0;
        int p2=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                v[p1]=nums[i];
                p1+=2;
            }
            else{
                v[p2]=nums[i];
                p2+=2;
            }
        }
        return v;
    }
};