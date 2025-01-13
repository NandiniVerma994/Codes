class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(cnt == 0) {
                element = nums[i];
                cnt++;
            }
            else if(element == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        int cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == element) {
                cnt2++;
            }
        }
        if(cnt2 = n/2) {
            return element;
        }
        return element;
    }
};