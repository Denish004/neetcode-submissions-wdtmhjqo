class Solution {
public:
    int calTriboNumber(int n){
        if(n== 0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;

        return calTriboNumber(n-1) + calTriboNumber(n-2) + calTriboNumber(n-3);
    }
    int tribonacci(int n) {
      return   calTriboNumber(n);
    }
};