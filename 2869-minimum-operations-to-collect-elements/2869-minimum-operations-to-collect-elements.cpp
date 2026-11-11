class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i=1; i<=k; i++){
            s.insert(i);
        }
        int operations = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(s.find(nums[i])!=s.end()){
                s.erase(nums[i]);
            }
            operations++;
            if(s.size()==0){
                break;
            }
        }
        return operations;
    }
};