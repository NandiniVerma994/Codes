class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > nums[(i+1) % n]) {// % n bcz we need to check the first element with the last element also for example in the case of [2, 1, 3, 4]....if 4 and 2 are not checked it will not give count = 1 which will eventually give true but it should be false because if the array is rotated by one place only ... that means if only one element is not at its correct place then it means the array is sorted and rotated ... and by rotating it we can get the sorted array but if more than 1 elements are not at its correct place means array is neither rotated nor sorted . Moreover for rest of the case like i=1 ...i+1%n gives the same number that is 2... for i=3...i+1%n gives 0 that is comparison with first element
                count++;
            }
        }
        if(count > 1) {
            return false;
        }
        return true;
    }
};