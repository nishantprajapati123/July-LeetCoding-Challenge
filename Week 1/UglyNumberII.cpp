// Time complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        
        int ugly[n];
        ugly[0] = 1;
        // ugly[1] = 1;
        
        int i = 0, j = 0, k = 0;
        for(int u=1;u<n;u++)
        {
            int m2 = ugly[i]*2;
            int m3 = ugly[j]*3;
            int m5 = ugly[k]*5;
            
            int min_ = min({m2, m3, m5});
            ugly[u] = min_;
            
            if(min_ == m2)  i++;
            if(min_ == m3)  j++;
            if(min_ == m5)  k++;
            
        }
        return ugly[n-1];
    }
};