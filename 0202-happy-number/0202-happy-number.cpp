class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        int sqSum = 0;
        int num = n;//19//82
        map<int,int> mpp;
        while(num > 0) {
            int rem = num % 10;//9//0//2//8
            sqSum += rem * rem;//81//82//4//68
            num = num / 10;//1//0//8//0
            if(num == 0) {
                if(mpp.find(sqSum) != mpp.end()) {
                    return false;
                }
                mpp[sqSum] = 1;
                if(sqSum == 1) return true;
                else {
                    num = sqSum;
                    sqSum = 0;
                }
            }
        }
        return false;

        

    }
};