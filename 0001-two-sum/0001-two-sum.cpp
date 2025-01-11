class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded) != mpp.end()) {
                ans.push_back(mpp[moreNeeded]);
                ans.push_back(i);

            }
            else if(mpp.find(moreNeeded) == mpp.end()) {
                mpp[num] = i;
            }
        }
        return ans;
    }
};