//并查集实现
class Solution {
    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int count0=0;
        UFDS ufds=new UFDS(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') count0++;
                else{
                    if(i>0&&grid[i-1][j]=='1')ufds.union(i*n+j,(i-1)*n+j);
                    if(i<m-1&&grid[i+1][j]=='1') ufds.union(i*n+j,(i+1)*n+j);
                    if(j>0&&grid[i][j-1]=='1') ufds.union(i*n+j,i*n+j-1);
                    if(j<n-1&&grid[i][j+1]=='1') ufds.union(i*n+j,i*n+j+1);
                }
            }
        }
        return ufds.unioncount-count0;
    }
}
class UFDS{
    int father[];
    int unioncount;
    public UFDS(int n){
        father=new int[n];
        unioncount=n;
        for(int i=0;i<n;i++) father[i]=i;
    }
    public int  find(int x){  //路径压缩
        int a=x;
        while(x!=father[x]) x=father[x];
        while(a!=father[a]){
            int temp=a;
            a=father[a];
            father[temp]=x;
        }
        return x;
    }
    public void union(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx==fy) return;
        father[fy]=fx;
        unioncount--;
        
    }
}
/*
//回溯
class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for (int i  = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        for (int num = 0; num < 4; num++) {
            dfs(grid, i + dx[num], j + dy[num]);
        }
        return;
    }
};

*/