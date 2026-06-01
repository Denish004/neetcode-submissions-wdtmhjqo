class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int N = meetings.size();

        sort(meetings.begin(), meetings.end());


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> scheduledMeetings;


        priority_queue<int, vector<int>, greater<int>> roomsPq;

        vector<int> countMeetings(n, 0);

        for(int i = 0; i<n; i++){
            roomsPq.push(i);
        }

        for(int i = 0; i<N; i++){
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];

            while(!scheduledMeetings.empty() && scheduledMeetings.top().first<=currStart){
                roomsPq.push(scheduledMeetings.top().second);
                scheduledMeetings.pop();
            }


            if(!roomsPq.empty()){
                 scheduledMeetings.push({currEnd, roomsPq.top()});
                 countMeetings[roomsPq.top()]++;
                roomsPq.pop();
            }
            else{
                int newStart = scheduledMeetings.top().first;
                int newEnd = currEnd + newStart - currStart;
                int room =   scheduledMeetings.top().second;

                scheduledMeetings.pop();


                scheduledMeetings.push({newEnd, room});
                // scheduledMeetings.push();
                 countMeetings[room]++;
            }

           
          




        }



    int roomIdx = 0;
    int maxi = 0;

    for(int i = 0; i<n; i++){
        if(countMeetings[i] > maxi){
            roomIdx = i;
            maxi = countMeetings[i];
        }
    }

    return roomIdx;

    }
};