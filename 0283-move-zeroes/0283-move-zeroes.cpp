class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                p1=i;
                break;
            }
        }
        if(p1==-1){
            return;
        }
        int p2=p1+1;
        while(p2<nums.size()){
            if(nums[p2]!=0){
                swap(nums[p1],nums[p2]);
                p1++;
            }
            p2++;
        }
        return;
    }
};