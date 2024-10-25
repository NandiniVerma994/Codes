class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1; i>=0; i--) {
            digits[i]++;
            if(digits[i] < 10) {
                return digits;
            }
            digits[i] = 0;
        }
        //agr first digit v 9 rhega toh beginning me 1 insert kro
        digits.insert(digits.begin(),1);
        return digits;
    }
};