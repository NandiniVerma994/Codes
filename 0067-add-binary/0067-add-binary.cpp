class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string res = "";
        while(i >= 0 && j >= 0) {
            int sum = carry + (a[i--] - '0') + (b[j--] - '0');//1+1+0 = 2 ka binary 10 hota h jisme 1 carry ko jayega isliye binary nikalo 10 ka 
            carry = sum / 2; 
            int dig = sum % 2; 
            res += dig + '0';//converting number to char
        }

        while(i >= 0) {
            int sum = carry + (a[i--] - '0');
            carry = sum / 2; 
            int dig = sum % 2; 
            res += dig + '0';
        }

        while(j >= 0) {
            int sum = carry + (b[j--] - '0');
            carry = sum / 2; 
            int dig = sum % 2; 
            res += dig + '0';
        }

        if(carry > 0) {
            res += carry + '0';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};