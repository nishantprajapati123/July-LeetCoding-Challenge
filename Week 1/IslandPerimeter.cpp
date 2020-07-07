// Time Complexity :- O(n^2)
// Space complexity :- O(1)
class Solution {
    int d1[4] = {-1, 1, 0, 0};
    int d2[4] = {0, 0, -1, 1};
public:
    void dfs(int x, int y, vector<vector<int> >&grid, int &perimeter)
    {
        grid[x][y] = -1;
        for(int d=0;d<4;d++)
        {
            int X = x+d1[d], Y = y+d2[d];
            if(X<0 || X>=grid.size() || Y<0 || Y>=grid[0].size())   perimeter++;
            else if(grid[X][Y] == 0)    perimeter++;
            else if(grid[X][Y] == -1)   continue;
            else if(grid[X][Y] == 1)   dfs(X, Y, grid, perimeter);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        if(!grid.size())    return 0;
        
        int perimeter = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j])
                {
                    dfs(i, j, grid, perimeter);
                    break;
                }
            }
            if(perimeter)   break;
        }
        
        return perimeter;
    }
};