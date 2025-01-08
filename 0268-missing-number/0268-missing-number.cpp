class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();//n = 3
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<n; i++) {//i=0->3------> 0,1,2
            xor2 = xor2 ^ nums[i];//3 ^ 0 ^ 1
            xor1 = xor1 ^ (i+1);//1 ^ 2 ^ 3
        }
        return xor1 ^ xor2;

        
    }
};