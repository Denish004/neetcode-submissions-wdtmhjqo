class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inward(n+1, 0);
        vector<int>outward(n+1, 0);

        for(auto t : trust){
            inward[t[1]]++;
            outward[t[0]]++;
        }

        for(int i = 1; i<=n; i++){
            if(inward[i]== n-1 && outward[i]==0){
                return i;
            }
        }

        return -1;
    }
};