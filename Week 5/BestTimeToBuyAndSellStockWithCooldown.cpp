// Time complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n < 2)   return 0;
        int dp[n][2];   //0->buy, 1->sell
        
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        
        dp[1][0] = -min(prices[0], prices[1]);
        dp[1][1] = max(0, prices[1] - prices[0]);
        
        for(int i=2;i<n;i++)
        {
            //either don't buy, or max profit from sell at i-2 - current price 
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i]);
            
            //either don't sell or add current price to i-1th buy
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};