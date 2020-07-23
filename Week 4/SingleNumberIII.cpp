// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int curr = 0;
        for(int x: nums)
            curr ^= x;
        // cout<<curr<<endl;
        vector<int>res(2, 0);
        int diff_bit = curr & -curr;
        
        for(int x: nums)
        {
            if((x&diff_bit) == 0)
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};