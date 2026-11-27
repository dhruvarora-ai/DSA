class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>mpp;   
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        int total_even = 0;
        int total_odd =0;
        int largest_odd = 0;
        bool first_odd=true;
        for(auto it:mpp){
            if(it.second %2 ==0){
                total_even+= it.second;
            }
            if(it.second%2 !=0){
                if(first_odd){
                    largest_odd = it.second;
                    first_odd = false;
                    continue;
                }
                if(it.second>largest_odd){
                    total_odd+= largest_odd -1;
                    largest_odd = it.second;
                }
                else{
                    total_odd+= it.second - 1;
                }
            }
        }
        return total_even + largest_odd+ total_odd;
    }
};