class Solution {
public:
    string reverseWords(string s) {
        // if(s == "") return s;
        string ans = "";
        vector<string>temp;
        s += " ";
        string curr = "";
        
        for(char c: s)
        {
            if(c == ' ')
            {
                if(curr != "")
                {
                    // cout<<curr;
                    temp.push_back(curr);
                    curr = "";
                }
            }
            else
                curr += c;
        }
        reverse(temp.begin(), temp.end());
        for(auto x: temp)   ans += x + " ";
        if(ans.size())  ans.pop_back();
        return ans;
    }
};