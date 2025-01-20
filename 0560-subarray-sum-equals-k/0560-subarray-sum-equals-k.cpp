
        class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;// preSum, cnt -> kitna baar aaya h
        mp[0] = 1;
        long long preSum = 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mp[remove];//how many cnt are there in hashmap with remove wala value that u add to cnt aur agr nhi h hashmap me toh add nhi hoga
            mp[preSum]++;
        }
        return cnt;
    }
};
