class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int partition = 1;
        int count = 0;
        while(partition != n) {
            int leftSum = 0;
            int rightSum = 0;
            for(int i=0; i<partition; i++) {
                leftSum += nums[i];
            }
            for(int i=partition; i<n; i++) {
                rightSum += nums[i];
            }
            if((leftSum - rightSum)%2 == 0) {
                count++;
            }
            partition++;
        }
        return count; 
    }
};