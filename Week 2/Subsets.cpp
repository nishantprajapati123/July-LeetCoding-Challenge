// Time complexity :- O(n*2^n)
// Space complexity :- O(n*2^n)
class Solution {
public:
    void generate(int id, vector<int>&curr, vector<int>&nums, vector<vector<int> >&ans)
    {
        ans.push_back(vector<int>(curr.begin(), curr.end()));
        
        for(int i = id; i<nums.size();i++)
        {
            curr.push_back(nums[i]);
            generate(i+1, curr, nums, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        int n = nums.size();
        if(n == 0)  return ans;
        
        vector<int>curr;
        generate(0, curr, nums, ans);
        return ans;
    }
};