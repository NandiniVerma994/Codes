class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        if(n == 3) {
            for(int i=0; i<n; i++) {
                product *= nums[i];
            }
            return product;
        }
        //-1, 0, 2, 3
        sort(nums.begin(), nums.end());
        int negProd = 0;
        if(nums[0] < 0 && nums[1] < 0) {
            negProd = 1;
            negProd = nums[0] * nums[1];
            negProd *= nums[n-1];
        }

        for(int i=n-1; i>=n-3; i--) {
            product *= nums[i];
        }
        
        
        if(negProd > product) {
            return negProd;
        }
        return product;
    }
};