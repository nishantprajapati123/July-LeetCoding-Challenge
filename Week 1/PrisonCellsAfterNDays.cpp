// Time complexity :- O(loop)
// Space complexity :- O(1)
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        unordered_map<string, int>mp;
        
        for(int i=0;i<N;i++)
        {
            string s = "";
            for(int x: cells)   s += to_string(x);
            
            // found 
            if(mp.find(s) != mp.end())
            {
                int loop = i - mp[s];
                // cout<<mp[s]<<" "<<i<<" "<<loop<<endl;
                int rem_day = (N - i) % loop;
                return prisonAfterNDays(cells, rem_day);
            }
            else    // not found
            {
                mp.insert({s, i});
                int prev = cells[0];
                for(int j=1;j<=6;j++)
                {
                    int next = cells[j+1];
                    int curr = cells[j];
                    cells[j] = prev == next;
                    prev = curr;
                }
            }
            
            cells[0] = cells[7] = 0;
        }
        return cells;
    }
};