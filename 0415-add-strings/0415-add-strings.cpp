class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i = n-1;
        int j = m-1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) {
                //Converting char to int
                sum += num1[i--] - '0';
            }
            if(j >= 0) {
                sum += num2[j--] - '0';
            }
            int rem = sum % 10;
            carry = sum / 10;
            res += rem + '0';//converting int to char
        }
        reverse(res.begin(), res.end());
        return res;
    }
};