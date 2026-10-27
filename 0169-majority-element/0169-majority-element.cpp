class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int p1=0;
        int el =0;
        while(p1<nums.size()){
            if(cnt==0){
                el = nums[p1];
                cnt=1;
            }
            else if(cnt>=1){
                if(nums[p1]==el){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            p1++;
        }
        int cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el){
                cnt2++;
            }
        }
        if(cnt2>(nums.size()/2)){
            return el;
        }
        return 0;
    }
};