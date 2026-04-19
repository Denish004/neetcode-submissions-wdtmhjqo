class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize!=0) return false;

        map<int, int> omap;

        for(auto x : hand){
            omap[x]++;
        }


        while(!omap.empty()){


            auto it = omap.begin();
            int key = it->first, val = it->second;

            for(int i = 0; i<groupSize; i++ ){
                if(omap.find(key+i)==omap.end()) return false;

                omap[key+i]--;
                if(omap[key+i]==0){
                    omap.erase(key+i);
                }

            }


        }


    return true;

    }
};
