class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int leader = arr[arr.size()-1];
        for(int i=arr.size()-2; i>=0; i--){
            int p = leader;
            if(arr[i]>=leader){
                leader = arr[i];
                arr[i];
            }
            arr[i] = p;
        }
        arr[arr.size()-1]=-1;
        return arr;

    }
};