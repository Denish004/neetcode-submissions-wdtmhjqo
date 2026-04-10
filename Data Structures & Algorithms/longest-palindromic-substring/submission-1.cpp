class Solution {
public:
    pair<int,int> getPalindrome(int left, int right,  string& s){
        if(left < 0 || right > s.size()-1) return {left+1, right-1};

        
        if(s[left]==s[right]){
            return getPalindrome(left-1, right+1, s);
        }

        return {left+1, right-1};
    }
    string longestPalindrome(string s) {
        int n = s.size();

      
        int lenAns = 0;
        int ansInd = -1;

        for(int i= 0; i<n; i++ ){
           pair<int,int> oddPalindrome = getPalindrome(i, i, s );
           int start = oddPalindrome.first;
           int end = oddPalindrome.second;
           int oddLength = end-start+1;
           if(lenAns<oddLength) {
            lenAns = oddLength ;
            ansInd= start;
           }
        }

        for(int i = 0; i<n-1; i++){
         pair<int,int> evenPalindrome = getPalindrome(i, i+1, s);
             int start = evenPalindrome.first;
           int end = evenPalindrome.second;
           int evenLength = end-start+1;
           if(lenAns<evenLength) {
            lenAns = evenLength ;
            ansInd= start;
           }
        }

        return s.substr(ansInd, lenAns);
    }
};
