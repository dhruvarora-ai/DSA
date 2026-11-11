class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int low = 0;
        int high = arr.size()-1;
        int missing = high;
        while(low<=high){
            int mid = (low+high)/2;
            missing = arr[mid]-(mid+1);
            if(missing<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(high==-1){
            return k;
        }
        missing = arr[high]-(high+1);
        int required = k - missing;
        return arr[high] + required;
    }
};