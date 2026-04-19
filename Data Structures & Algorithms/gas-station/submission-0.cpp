class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gasTotal = accumulate(gas.begin(), gas.end(), 0);
        int costTotal = accumulate(cost.begin(), cost.end(), 0);

        if(gasTotal <costTotal){
            return -1;
        }

        int available = 0;
        int start = 0;

        for(int i = 0; i<n; i++){

            available+= (gas[i]- cost[i]);

            if(available<0){
                available = 0;
                start = i+1;
            }
        }


        return start;
    }
};
