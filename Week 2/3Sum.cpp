// Time complexity :- O(n^2)
// Space complexity :- O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int> >ans;
        if(n < 3)  return ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            while(i>0 && i<n-2 && nums[i] == nums[i-1])
            {
                i++;
            }
            
            int j = i+1, k = n-1;
            while(j < k)
            {
                long sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else
                {
                    j++;
                    while(j<k && nums[j] == nums[j-1])
                    {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};