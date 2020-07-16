// Time complexity :- O(log(n))
// Space complexity :- O(1)
class Solution {
public:
    double myPow(double x, long n) {
        
        if(n < 0)
            return 1.0/myPow(x, -n);
        if(x == 1 || n == 0)  return 1;
        double temp = myPow(x*x, n/2);
        if(n&1)
            temp *= x;
        return temp;
    }
};