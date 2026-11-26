class Solution {
public:
    string reverseOnlyLetters(string s) {
        int p1 = 0;
        int p2= s.size()-1;
        while(p1<p2){
            if(!(isalpha(s[p1]))){
                p1++;
                continue;
            }
            if(!(isalpha(s[p2]))){
                p2--;
                continue;
            }
            swap(s[p1],s[p2]);
            p1++;
            p2--;
        }
        return s;
    }
};