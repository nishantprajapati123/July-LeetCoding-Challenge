// Time complexity :- O(n*2^n)
// Space complexity :- O(n*2^n)
class Solution {
public:
    vector<string> rec(const string& sentence, const vector<string>& dict,
    unordered_map<string, vector<string>>& found) 
    {
    
        if(found.count(sentence)) {
            return found[sentence];
        }

        int n = sentence.size();
        vector<string> result;
        for(int i = 1; i <= n; i++) {
            string word = sentence.substr(0, i);
            string rem = sentence.substr(i);
            if(find(dict.begin(), dict.end(), word) != dict.end()) {
                if(rem.empty()) {
                    result.push_back(word);
                }
                else {
                    for(auto& s: rec(rem, dict, found)) {
                        result.push_back(word + " " + s);
                    }
                }
            }
        }

        found[sentence] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> found;
        return rec(s, wordDict, found);
    }
};