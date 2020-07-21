// Time complexity :- O(n*m)
// Space complexity :- O(1)
class Solution {
    int d1[4] = {1,-1,0,0};
    int d2[4] = {0,0,1,-1};
public:
    bool dfs(vector<vector<char>>&board, int x, int y, int id, string &word)
    {
        if(board[x][y] != word[id])
            return false;
        board[x][y] = '#';
        if(id == word.length()-1)
            return true;
        for(int d=0;d<4;d++)
        {
            int x_ = x+d1[d], y_ = y+d2[d];
            if(x_ < 0 || x_ >= board.size() || y_ < 0 || y_>= board[0].size())  continue;
            if(board[x_][y_] == '#')    continue;
            if(dfs(board, x_, y_, id+1, word))  return true;
        }
        board[x][y] = word[id];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int id = 0;
                if(dfs(board, i, j, id, word))
                    return true;
            }
        }
        return false;
    }
};