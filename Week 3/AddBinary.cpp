// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length();
        int m = b.length();
        int diff = abs(n-m);
        
        if(n < m)
        {
            for(int i=1;i<=diff;i++)    a.insert(0, "0");
        }
        else if(m < n)
        {
            for(int i=1;i<=diff;i++)    b.insert(0, "0");   
        }
        
        string ans = "";
        int c = 0;
        for(int i=a.length()-1;i>=0;i--)
        {
            int c1 = a[i] - '0';
            int c2 = b[i] - '0';
            
            int res = c1 ^ c2 ^ c;
            if(c1 + c2 + c > 1) c = 1;
            else    c = 0;
            ans.insert(0, to_string(res));
        }
        if(c == 1)
            ans.insert(0, '1');
        
        return ans;
    }
};