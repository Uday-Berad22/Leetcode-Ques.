class Solution {
    public int dfs(int i,int j,int parent,int [][] grid){
        if(i<0||i>=grid.length||j<0||j>=grid.length||grid[i][j]>1||grid[i][j]==0) return 0;
        grid[i][j]=parent;
        int count=0;
        count=dfs(i+0,j+1,parent,grid)+dfs(i+0,j-1,parent,grid)+dfs(i+1,j+0,parent,grid)+dfs(i-1,j,parent,grid);
        return count+1;
    }
    public int largestIsland(int[][] grid) {
        int parent=2;
        ArrayList<Integer> Count= new ArrayList<>();
        Count.add(0);
        Count.add(0);
        int ans=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid.length;j++){
                if(grid[i][j]==1){
                    Count.add(dfs(i,j,parent,grid));
                    ans=Math.max(ans,Count.get(parent));
                    parent++;
                }
            }
        }
        int n=grid.length;
       
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid.length;j++){
                if(grid[i][j]==0){
                    Set<Integer> set = new HashSet<Integer> (); 
                    if(i+1<n){
                        set.add(grid[i+1][j]);
                    }
                    if(i-1>=0){
                        set.add(grid[i-1][j]); 
                    }
                    if(j+1<n){
                        set.add(grid[i][j+1]);
                    }
                    if(j-1>=0){
                        set.add(grid[i][j-1]);
                    }
                    int sum=1;
                    for(Integer Parent: set){
                        sum+=Count.get(Parent);
                    }
                    ans=Math.max(ans,sum); 
                }
            }
        }
        return ans;
    }
}