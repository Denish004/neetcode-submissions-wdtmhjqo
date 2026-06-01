/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool customSort(Interval &a, Interval &b){
        if(a.start<b.start){
            return true;
        }
        else if(a.start == b.start){
            return a.end<b.end;
        }
        else return false;

    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n  = intervals.size();

        sort(intervals.begin(), intervals.end(), customSort);


        int minRooms = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
     
        for(int i = 0; i<n; i++){
            if(pq.empty()){
                minRooms++;
            }
            else{
                if(intervals[i].start<pq.top()){
                    minRooms++;
                }else{
                    pq.pop();
                }
            
            }

            pq.push(intervals[i].end);
        }

        return minRooms;
    }
};
