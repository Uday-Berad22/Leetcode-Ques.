class Myclass{
    public:
    int x;
    int y;
    int time;
    Myclass(int x,int y,int time){
        this->x=x;
        this->y=y;
        this->time=time;
    }
};
class Solution {
    // vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return -1;
        }
        int cols = grid[0].size();
        
        int fresh_cnt = 0;
        queue<pair<int, int>> rotten;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    rotten.push(make_pair(r, c));
                }
                else if (grid[r][c] == 1) {
                    fresh_cnt++;
                }
            }
        }
        
        int minutes_passed = 0;
        
        while (!rotten.empty() && fresh_cnt > 0) {
            minutes_passed++;
            int level_size = rotten.size();
            
            for (int i = 0; i < level_size; i++) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                
                for (const auto& dir : directions) {
                    int xx = x + dir.first;
                    int yy = y + dir.second;
                    
                    if (xx < 0 || xx == rows || yy < 0 || yy == cols) {
                        continue;
                    }
                    
                    if (grid[xx][yy] == 0 || grid[xx][yy] == 2) {
                        continue;
                    }
                    
                    fresh_cnt--;
                    grid[xx][yy] = 2;
                    rotten.push(make_pair(xx, yy));
                }
            }
        }
        
        return (fresh_cnt == 0) ? minutes_passed : -1;
    }

};