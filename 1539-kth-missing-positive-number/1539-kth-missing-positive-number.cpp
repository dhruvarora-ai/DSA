class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int missing=0;
        int low=0;
        int high = arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            missing = arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high+k+1;
        
    }
};