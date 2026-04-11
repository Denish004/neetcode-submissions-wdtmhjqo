class Solution {
public:
    int f(int i, int remTarget, vector<int>&stones){
        if(i==-1){
            return remTarget;
        }

        int pick = INT_MAX;
        if(stones[i]<=remTarget){
           pick = f(i-1, remTarget - stones[i], stones);
        }

        int notPick = f(i-1, remTarget, stones);

        return min(pick, notPick);



    }
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();

        int totalSum = accumulate(stones.begin(), stones.end(), 0); 

        int target = ceil(totalSum/2.0);

        int leftPile1Sum =  f(n-1, target, stones);

        int pile1Sum = target - leftPile1Sum;
        int pile2Sum = totalSum - pile1Sum;


        return abs(pile1Sum - pile2Sum);




    }
};



                    //             3  13        return 1;

                    //         .   .   .    .

                    //     . . ..  .    .   .       .. .. 

                    // 11(2)   12(1)   13(0)    9    11    10