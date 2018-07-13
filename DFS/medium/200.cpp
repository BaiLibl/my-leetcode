#include<iostream>
#include<vector>
using namespace std;

int dfs(vector< vector<char> >& grid,int i,int j){
	int n=grid.size();
	int m=grid[0].size();
	if(i<0||j<0||i>=n||j>=m)return 0;
	if(grid[i][j]=='1'){
		grid[i][j]='0';//如果没有visited，则可以设置成grid[i][j]=0 
		return 1+dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i-1,j)+dfs(grid,i,j-1);
	}else{
        return 0;
    }
}
int numIslands(vector< vector<char> >& grid) {
    if(grid.size()==0||grid[0].size()==0)return 0;
    int n=grid.size();
	int m=grid[0].size();
	int res=0;
    int i,j;
    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		int c= dfs(grid,i,j);
    		res += c>0?1:0;
    	}
    }
    return res;   
}
int maxAreaOfIsland(vector< vector<int> >& grid) {
    
}

int main(){
	return 0;
}
