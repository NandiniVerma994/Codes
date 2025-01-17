class Solution {
public:
    // bool linearSearch(vector<int>& nums, int element) {
    //     int n = nums.size();
    //     for(int i=0; i<n; i++) {
    //         if(nums[i] == element) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if(n == 0) {
        //     return 0;
        // }
        // int longest = 1;
        // for(int i=0; i<n; i++) {
        //     int x = nums[i];
        //     int cnt = 1;
        //     while(linearSearch(nums, x+1) == true) {
        //         cnt++;
        //         x+=1;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;
        int n = nums.size();
        if(n == 0) return 0;
        int lastSmaller = INT_MIN;
        int longest = 1;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            
            if(nums[i]-1 == lastSmaller) {
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};