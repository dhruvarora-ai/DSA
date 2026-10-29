class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int maxl = INT_MIN;
        for(int i:s){
            int l =1;
            if(s.find(i+1)==s.end()){
                while(s.find(i-1)!=s.end()){
                    l++;
                    i--;
                }
            }
            maxl = max(maxl,l);
        }
        return maxl;
    }
};