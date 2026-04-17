class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        int maxLength = 1;
        int l = 0, r = 1;
        string prev =  " ";

        while(r<n){
            if(arr[r-1] < arr[r] && prev!="<"){
                maxLength = max(maxLength, r-l+1);
                r++;
                prev = "<"; 
            }
            else if(arr[r-1]>arr[r] && prev!=">"){
                maxLength = max(maxLength, r-l+1);
                r++;
                prev = ">"; 
            }
            else{
                if(arr[r]==arr[r-1]) r++;
                l = r-1;
                prev = " ";
            }
        }
    return maxLength;


    }
};