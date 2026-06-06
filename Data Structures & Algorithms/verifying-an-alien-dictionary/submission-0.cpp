class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();

        unordered_map<char, int> umap;

        for(int i = 0; i<order.size(); i++){
            umap[order[i]] = i;
        }


        for(int i = 0; i<n-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            for(int j = 0; j<w1.size(); j++){

                if(j == w2.size()) return false;

                if(w1[j] == w2[j]){
                   continue;
                }
                else{
                    if(umap[w1[j]] > umap[w2[j]]){
                        return false;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        return true;
    }
};