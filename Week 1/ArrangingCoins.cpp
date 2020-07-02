// TIme complexity :- O(log(n))
// Space complexity :- O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        
        int l = 0, r = n;
        int mid;
        int ans = 0;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            long long int total = (1ll * mid * (mid+1))/2;
            if(total <= n)
            {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};