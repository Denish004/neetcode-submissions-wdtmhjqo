class Solution {
public:
    string getPalindrome(int left, int right,  string s){
        if(left < 0 || right > s.size()-1) return s.substr(left+1, right-left-1);

        
        if(s[left]==s[right]){
            return getPalindrome(left-1, right+1, s);
        }

        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();

        string ans = "";
        for(int i= 0; i<n; i++ ){
           string oddPalindrome = getPalindrome(i, i, s );
           if(ans.size()<oddPalindrome.size()) ans = oddPalindrome;
        }

        for(int i = 0; i<n-1; i++){
            string evenPalindrome = getPalindrome(i, i+1, s);
            if(ans.size()<evenPalindrome.size()) ans = evenPalindrome;
        }

        return ans;
    }
};
