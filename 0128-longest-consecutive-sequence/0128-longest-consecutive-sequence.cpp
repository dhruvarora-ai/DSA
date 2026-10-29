class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }   
        int maxl=0;
        for(int i:s){
            int l = 1;
            if(s.find(i+1)==s.end()){
                while(s.find(i-1)!=s.end()){
                    l++;
                    i--;
                }
                maxl = max(maxl,l);
            }
        }
        return maxl;
    }
};