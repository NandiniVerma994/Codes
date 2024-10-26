class Solution {
public:
    int addDigits(int num) {
        int n = num;
        int sum = 0;
        while(n > 0) {
            int rem = n % 10;//8
            sum += rem;//8
            n = n/10;//3
            if(n == 0) {
                if(sum >= 0 && sum <= 9) {
                    return sum;
                }
                else {
                    n = sum;
                    sum = 0;
                }
            }
        }
        return n;
    }
};