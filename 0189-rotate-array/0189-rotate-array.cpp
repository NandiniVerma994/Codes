class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k > n) {
            return;
        }
        int temp[k];
        //for right
        int j = 0;
        for(int i=n-k; i<n; i++) {
            temp[j++] = nums[i];
        }
        for(int i=n-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }
        for(int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
        //for left
        // for(int i=0; i<k; i++) {
        //     temp[i] = nums[i];
        // }
        // for(int i=k; i<n; i++) {
        //     nums[i-k] = nums[i];
        // }
        // int j=0;
        // for(int i=n-k; i<n; i++) {
        //     nums[i] = temp[j++];
        // }
    }
};