class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int p1 = 0;
        int p2 = 0;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<=nums2[p2]){
                v.push_back(nums1[p1]);
                p1++;
            }
            else{
                v.push_back(nums2[p2]);
                p2++;
            }
        }
        while(p1<nums1.size()){
            v.push_back(nums1[p1]);
            p1++;
        }
        while(p2<nums2.size()){
            v.push_back(nums2[p2]);
            p2++;
        }
        if(v.size()%2==0){
            double ans = v[(v.size()/2)-1] + v[v.size()/2];
            return ans/2; 
        }
        
        return v[(v.size()/2)]; 
    }
};