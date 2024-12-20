package practice_java;

public class Demo {
	public static void main(String[] args) {
		Solution S = new Solution();
		S.numIslands(new char[][] {
			{'1','1','1','1','0'},
				{'1','1','0','1','0'},
				{'1','1','0','0','0'},
				{'0','0','0','0','0'}
		});
	}
}

class Solution {
	public int numIslands(char[][] grid) {
		boolean[][] check = new boolean[grid.length][grid[0].length];
		int ans=0;
		for(int i=0;i<grid.length;i++){
			for(int j=0;j<grid[0].length;j++){
				if(grid[i][j]==1 && check[i][j]==false){
					ans++;
					dfs(grid,check,i,j);
				}
			}
		}
		return ans;
	}
	private void dfs(char[][] grid,boolean[][] check,int i,int j){
		if(i<0 || i>=grid.length || j<0 || j>=grid[0].length){
			return;
		}
		if(grid[i][j]==1 && check[i][j]==false){
			check[i][j]=true;
			dfs(grid,check,i,j+1);
			dfs(grid,check,i,j-1);
			dfs(grid,check,i+1,j);
			dfs(grid,check,i-1,j); 
		}
	}
}
