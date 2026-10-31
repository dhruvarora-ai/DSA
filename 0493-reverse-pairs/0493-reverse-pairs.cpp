class Solution {
public:
    long long mergeSort(vector<int>& nums, int low, int high){
        if(low>=high){
            return 0;
        }
        int mid = (low+high)/2;
        int leftCount = mergeSort(nums,low,mid);
        int rightCount = mergeSort(nums,mid+1,high);
        int count =0;
        int p1 = low;
        int p2 = mid+1;
        while(p1<=mid && p2<=high){
            if(nums[p1]>2LL*nums[p2]){
                count+= mid-p1+1;
                p2++;
            }
            else{
                p1++;
            }
        }
        int p11= low;
        int p22= mid+1;
        vector<int>v;
        while(p11<=mid && p22<=high){
            if(nums[p11]>=nums[p22]){
                v.push_back(nums[p22]);
                p22++;
            }
            else{
                v.push_back(nums[p11]);
                p11++;
            }
        }
        while(p11<=mid){
            v.push_back(nums[p11]);
            p11++;
        }
        while(p22<=high){
            v.push_back(nums[p22]);
            p22++;
        }
        for(int i=low; i<=high; i++){
            nums[i] = v[i-low];
        }
        return count + leftCount + rightCount;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};