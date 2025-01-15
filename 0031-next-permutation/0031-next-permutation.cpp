class Solution {
public:
    // nums[] = {2, 1, 5, 4, 3, 0, 0}
    
    void nextPermutation(vector<int>& nums) {
        // Step1: Find the breakpoint(if you change 300 in all possible ways it wont yield anything greater so we need to find out the breakpoint to yield something greater)
        int n = nums.size();
        int index = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        // if no indexes are returned means it is the last permutation showing that it the largest one so next permutation will be smallest one so you can just reverse it
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Step2: After getting the breakpoint search for the first greater element to the right of it
        for(int i=n-1; i>index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Step3: There will be many but we want just greater so we will do it so as to get 2, 3, 0, 0 , 1, 4, 5 so we revers
        reverse(nums.begin()+index+1, nums.end());
    }
};