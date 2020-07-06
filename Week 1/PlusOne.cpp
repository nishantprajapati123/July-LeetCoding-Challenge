// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        digits[n-1] += 1;
        int c = digits[n-1]/10;
        digits[n-1] %= 10;
        for(int i=n-2;i>=0;i--)
        {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if(c == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};