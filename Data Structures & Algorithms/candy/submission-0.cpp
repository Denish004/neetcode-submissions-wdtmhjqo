class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

       vector<int> candies(n, 1);

       if(n==1){
        return 1;
       }


        queue<int> q;

        for(int i = 1; i<n-1 ; i++){

            if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                q.push(i);
            }
        }

        if(ratings[0]<=ratings[1]) q.push(0);

        if(ratings[n-1]<=ratings[n-2]) q.push(n-1);




        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                int nodeInd = q.front();
                q.pop();

                if(nodeInd+1<n && ratings[nodeInd+1]>ratings[nodeInd]){
                    candies[nodeInd+1] = candies[nodeInd]+1;
                    q.push(nodeInd+1);
                }
                if(nodeInd-1>=0 && ratings[nodeInd-1]>ratings[nodeInd]){
                    candies[nodeInd-1]= candies[nodeInd]+1;
                    q.push(nodeInd-1);
                }
            }

        }


    int total = accumulate(candies.begin(), candies.end(), 0);


    return total;

    }
};



    //   5 4    4      5
    //             3     4       6
    //                     3   2   3   3
    //                       1                2 
    //                                           1
    //   1 1 1 1
    //   2 2 2 1
    //   3 3 2 1
    //   4 3 2 1 

