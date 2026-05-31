class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for(int i = 1; i<n; i++){
            if(intervals[i][0]<=prevEnd){
                prevEnd = max(intervals[i][1], prevEnd);
            }
            else{
                res.push_back({prevStart, prevEnd});
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }

        res.push_back({prevStart, prevEnd});
        return res;

    }

};
