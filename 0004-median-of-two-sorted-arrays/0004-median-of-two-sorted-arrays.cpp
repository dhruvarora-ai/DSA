class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 =0;
        int p2 =0;
        int p3 =0;
        
        int ind1 = (nums1.size()+nums2.size()-1)/2;
        int ind2 = (nums1.size()+nums2.size()-1)/2 + 1;
        double el1 = -1.0;
        double el2 = -1.0;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<=nums2[p2]){
                if(p3==ind1){
                    el1 = nums1[p1];
                }
                if(p3==ind2){
                    el2=nums1[p1];
                    p1++;
                    p3++;
                    break;
                }
                p1++;
                p3++;
            }
            else{
                if(p3==ind1){
                    el1 = nums2[p2];
                }
                if(p3==ind2){
                    el2 = nums2[p2];
                    p2++;
                    p3++;
                    break;
                }
                p2++;
                p3++;
            }
        }
        while(p1<nums1.size()){
            if(p3==ind1){
                el1 = nums1[p1];
            }
            if(p3==ind2){
                el2 = nums1[p1];
                p1++;
                p3++;
                break;
            }
            p1++;
            p3++;
        }
        while(p2<nums2.size()){
            if(p3==ind1){
                el1 = nums2[p2];
            }
            if(p3==ind2){
                el2 = nums2[p2];
                p2++;
                p3++;
                break;
            }
            p2++;
            p3++;
        }
        if((nums1.size()+nums2.size())%2==0){
            return (el1+el2)/2.0;
        }
        return el1;

        
    }
};