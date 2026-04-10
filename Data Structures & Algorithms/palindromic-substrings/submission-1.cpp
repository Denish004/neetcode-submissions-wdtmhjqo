class Solution {
public:
    int getPalindrome(int left, int right, string &s){
        // if(left<0 || right>= s.size()) return 0;


        // if(s[left]==s[right]){
        //     return 1 + getPalindrome(left-1, right+1, s);
        // }


        // return 0;
        int count = 0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;

    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i<n; i++){
          count+=getPalindrome(i,i, s );
          count+=getPalindrome(i, i+1, s);
        }


        return count;
    }
};
