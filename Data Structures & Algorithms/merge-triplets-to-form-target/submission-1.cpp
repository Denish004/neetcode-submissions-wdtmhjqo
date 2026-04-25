class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        vector<int>result(3, 0);

        for(int i = 0; i<n; i++){
            if(triplets[i][0]<= target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
            result[0] = max(triplets[i][0], result[0]);
            result[1] = max(triplets[i][1], result[1]);
            result[2] = max(triplets[i][2], result[2]);
            }
           
        }

        if(result==target)return true;

        return false;
    }
};
