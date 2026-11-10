class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int low = 0;
        int high = arr.size()-1;
        int missing = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid]-mid-1;
            if(missing<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(high==-1){
            return k; //k is lesser than 1st element in this case
        }
        missing = arr[high]-high-1; //missing at high index
        int required = k-missing;  //required to get to kth missing element
        return arr[high]+required;
    }
};