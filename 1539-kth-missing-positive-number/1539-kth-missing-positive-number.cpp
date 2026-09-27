class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1;
        int count=0;
        for(int i=0; i<arr.size(); i++){
            while(arr[i]>num){
                count++;
                if(count==k){
                    return num;
                }
                num++;
            }
            num++;
        }
        while(true){
            count++;
            if(count==k){
                return num;
            }
            num++;
        }
        return -1;
    }
};