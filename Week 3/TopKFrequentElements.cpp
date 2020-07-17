// Time complexity :- O(nlog(k))
// Space complexity :- O(n + k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int>freq;
        for(int ele: nums)
            freq[ele]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minHeap;
        vector<int>ans;
        for(auto it: freq)
        {
            if(minHeap.size() < k)
            {
                minHeap.push({it.second, it.first});
            }
            else
            {
                int occur = minHeap.top().first;
                int number = minHeap.top().second;
                
                if(it.second > occur)
                {
                    minHeap.pop();
                    minHeap.push({it.second, it.first});
                }
            }
        }
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};