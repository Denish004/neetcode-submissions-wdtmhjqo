class Solution {
public:
    int countWays(int ind, int prev, unordered_map<string, char>&umap, string&s){
    
   
    if(ind==0){
          string st = s.substr(ind, prev-ind);
          if(umap.count(st)) return 1;
          else return 0;
    }

    string st = s.substr(ind, prev-ind);
    int breakPart = 0;
    if(umap.count(st)){
    breakPart = countWays(ind-1, ind, umap, s);
    }
    int notBreakPart = countWays(ind-1, prev, umap, s);


    return breakPart + notBreakPart;
      

    }
    int numDecodings(string s) {
        int n = s.size();
        unordered_map<string, char> umap;

        for(char c = 'A'; c<='Z'; c++){
            string st = to_string(c-'A'+1);
            umap[st] = c;
        }
        

       return  countWays(n-1, n, umap, s);
    }
};


//   1012

//   101 2-> B     

//   101 -> 
//   10 1->A                       101
//   10                            1 01->Invalid  101      
//   1 0 ->Invalid    10                          101->Invalid
//                   10 -> J 


//    1012

//    10 12  ->L

//    10 
//    1 0 ->Invalid     10
//                      10->J