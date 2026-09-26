class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr[0]>arr[1]){
            return 0;
        }
        else if(arr[arr.size()-1]>arr[arr.size()-2]){
            return arr.size()-1;
        }
        int low=1;
        int high = arr.size()-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};