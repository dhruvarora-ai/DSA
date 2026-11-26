class Solution {
public:
    bool check_palindrome(string s, int removed){
        int p1 = 0;
        int p2 = s.size()-1;
        while(p1<p2){
            if(p1==removed){
                p1++;
                continue;
            }
            if(p2==removed){
                p2--;
                continue;
            }
            if(s[p1]!= s[p2]){
                return false;;
            }
            p1++;
            p2--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int p1 =0;
        int p2 = s.size()-1;
        int mismatch =0;
        bool left=false;
        bool right = false;
        while(p1<p2){
            if(s[p1]!=s[p2]){
                mismatch+= 1;
                if(mismatch>1){
                    return false;
                }
                left = check_palindrome(s,p1);
                right = check_palindrome(s,p2);
                if(left){
                    p1+= 2;
                    p2--;
                }
                else if(right){
                    p2-= 2;
                    p1++;
                }
                else{
                    return false;
                }
            }
            else{
                p1++;
                p2--;
            }
        }
        return true;
    }
};