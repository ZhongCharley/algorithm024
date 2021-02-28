class Solution {
//leetcode200
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for (int length = 0 ; length < grid.size() ; length++)
            for (int width = 0; width < grid[0].size() ; width++) {
                if(grid[length][width] == '1') {
                    dfs(grid,length,width);
                    ans++;
                }
            }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid,int length,int width){
        //判断边界
        if (!inmap(grid,length,width) ) return;

        //执行逻辑
        if(grid[length][width] == '1') {
            //变成0就无法判断是否遍历过
            grid[length][width] = '2';
            dfs(grid,length+1,width);
            dfs(grid,length-1,width);
            dfs(grid,length,width+1);
            dfs(grid,length,width-1);
            }

        return;
        }

    bool inmap(vector<vector<char>>& grid,int length,int width){
        return length >= 0 && length < grid.size() && width >= 0 && width < grid[0].size();
        }
};

//回溯