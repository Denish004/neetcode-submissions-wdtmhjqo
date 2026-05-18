class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> stars;


        for(int i = 0; i<s.size(); i++){
            if(s[i]==')'){

                if(!open.empty()){
                    open.pop();
                }
                else if(!stars.empty()){
                    stars.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else{
                stars.push(i);
            }

        }


        while(!open.empty() && !stars.empty()){
            int oi = open.top();
            open.pop();
            int si = stars.top();
            stars.pop();

            if(oi>si){
                return false;
            }

        }


        if(open.empty()){
            return true;
        }


        return false;


    }
};
