class Solution {
public:
    

    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> leftProduct(n, 1);
        vector<int> rightProduct(n, 1);

        
        leftProduct[0]= nums[0];
        rightProduct[n-1]= nums[n-1];

       

        // int maxProduct = INT_MIN;

        int maxProduct = max(leftProduct[0], rightProduct[n-1]);
        for(int i = 1; i<n; i++){
            
            int lProduct  = nums[i];
            int rProduct = nums[n-i-1];

            if(leftProduct[i-1]!=0){
                lProduct = lProduct*leftProduct[i-1];
            }

            if(rightProduct[n-i]!=0){
                rProduct = rProduct*rightProduct[n-i];
            }

        
            
      
            
            leftProduct[i] = lProduct;
            rightProduct[n-i-1] = rProduct;

            maxProduct = max(maxProduct, max(leftProduct[i], rightProduct[n-i-1]));

        }

        return maxProduct;


    }
};
