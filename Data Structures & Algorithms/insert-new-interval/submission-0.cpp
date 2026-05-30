class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int n = intervals.size();

        for(int i = 0; i<n; i++){
            if(newStart<=intervals[i][1] && newEnd>=intervals[i][0]){
                newStart = min(newStart, intervals[i][0]);
                newEnd = max(newEnd, intervals[i][1]);
            }
            else if(newStart>intervals[i][1]){
                res.push_back(intervals[i]);
            }
            else{
                res.push_back({newStart, newEnd});
                copy(intervals.begin()+i, intervals.end(), back_inserter(res));
                return res;
            }
        }

        res.push_back({newStart, newEnd});

        return res;
    }
};
