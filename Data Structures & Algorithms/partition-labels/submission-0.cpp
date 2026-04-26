class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();


        unordered_map<char, int> lastOccur;

        for(int i = 0; i<n; i++){
            lastOccur[s[i]] = i;
        }

        int l = 0, r = 0;
        vector<int> ans;

        while(l<n && r<n){
            for(int i = l; i<=r; i++ ){
                r = max(r, lastOccur[s[i]]);
            }

            ans.push_back(r-l+1);
            l = r+1;
            r = l;
        }


        return ans;




    }
};
