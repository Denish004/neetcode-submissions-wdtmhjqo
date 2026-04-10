class Solution {
public:
    int solve(int i, int j, string s1 , string s2){
        if(j>= s2.size()){
            return 1;
        }
        if(i>=s1.size()) return 0;
        int pick = 0;
        if(s1[i]==s2[j]){
           pick =  solve(i+1,j+1, s1, s2 );
        }

        int notPick = solve(i+1, j, s1, s2);


        return pick + notPick;
    }


    int numDistinct(string s, string t) {
        
        return solve(0,0, s, t);
    }
};



    

