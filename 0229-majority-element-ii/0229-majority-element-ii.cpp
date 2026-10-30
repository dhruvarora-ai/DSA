class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = 0;
        int el2 = 0;
        int p1=0;
        vector<int>v;
        if(nums.size()==0){
            return v;
        }
        while(p1<nums.size()){
            if(cnt1==0 && nums[p1]!=el2){
                el1 = nums[p1];
                cnt1++;
            }
            else if(nums[p1]==el1){
                cnt1++;
            }
            else if(cnt2==0){
                el2=nums[p1];
                cnt2++;
            }
            else if(nums[p1]==el2){
                cnt2++;
            }
            else if(nums[p1]!=el1 && nums[p1]!=el2){
                cnt1--;
                cnt2--;
            }
            p1++;
        }
        int c1 = 0;
        int c2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
        }
        if(c1>nums.size()/3){
            v.push_back(el1);
        }
        if(c2>nums.size()/3){
            v.push_back(el2);
        }
        return v;
    }
};