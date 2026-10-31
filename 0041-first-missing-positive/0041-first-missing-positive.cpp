class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        long long el = 1LL* *max_element(nums.begin(),nums.end())+1;
        for(int i=1; i<=nums.size(); i++){
            if(s.find(i)==s.end()){
                el = i;
                break;
            }
        }
        return el;
    }
};