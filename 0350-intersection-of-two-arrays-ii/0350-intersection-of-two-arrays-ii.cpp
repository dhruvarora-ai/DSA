class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i=0; i<nums1.size(); i++){
            mpp1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            mpp2[nums2[i]]++;
        }
        int size=0;
        vector<int>v;
        for(auto it:mpp1){
            if(mpp2.find(it.first)!=mpp2.end()){
                size=min(mpp2[it.first], it.second);
                for(int j=0; j<size; j++){
                    v.push_back(it.first);
                }
            }
        }
        return v;
    }
};