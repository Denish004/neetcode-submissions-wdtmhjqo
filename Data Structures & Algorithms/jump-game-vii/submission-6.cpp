class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
       
        queue<int>q;
        q.push(0);
        
        int farthest = 0;

        while(!q.empty()){
           
           int ind = q.front();
           q.pop();

         
                int atMin =max(farthest+1, ind + minJump);
                int atMax = min(n-1,ind+ maxJump);
                farthest = atMax;
                for(int i = atMin; i<=atMax; i++){
                    if(s[i]=='0'){
                         q.push(i);
                         if(i==n-1){
                            return true;
                         }
                    }
                   
                }
            
         
    
        }

      return false;
    }
};



   
