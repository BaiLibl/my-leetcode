#include<iostream>
#include<vector>
using namespace std;

int maxn =0 ;
int dfs(vector< vector<int> >& grid,vector< vector<int> >& visited,int i,int j){
	int n=grid.size();
	int m=grid[0].size();
	if(i<0||j<0||i>=n||j>=m)return 0;
	if(grid[i][j]==1&&visited[i][j]==0){
		visited[i][j]=1;//如果没有visited，则可以设置成grid[i][j]=0 
		//maxn = maxn<count?count:maxn;
		//dfs(grid,visited,i+1,j,count);
		//dfs(grid,visited,i,j+1,count);
		return 1+dfs(grid,visited,i+1,j)+dfs(grid,visited,i,j+1)+dfs(grid,visited,i-1,j)+dfs(grid,visited,i,j-1);
	}else{
        return 0;
    }
}
int maxAreaOfIsland(vector< vector<int> >& grid) {
    if(grid.size()==0||grid[0].size()==0)return 0;
    int n=grid.size();
	int m=grid[0].size();
    vector< vector<int> > visited=vector< vector<int> >(n,vector<int>(m,0));
    //dfs(grid,visited,0,0,0);
    int i,j;
    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		int c= dfs(grid,visited,i,j);
    		maxn=c>maxn?c:maxn;
    	}
    }
    return maxn;  
}

/*
int dfs(vector< vector<int> >& grid,int x0,int y0){
	int n=grid.size();
    int m=grid[0].size();
    int sum=1;//进来就是1
    grid[x0][y0]=0;//读过一次了,在以这次遍历为中心的地方不会再遍历到自己
    int id[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int i;
    for(i=0;i<4;i++){
        int x=x0+id[i][0];
        int y=y0+id[i][1];
        if(x>=0&&x<n&&y>=0&&y<m){
            if(grid[x][y])sum+=dfs(grid,x,y);
        }
    }
    return sum;
}

int maxAreaOfIsland(vector< vector<int> >& grid) {
	if(grid.size()==0||grid[0].size()==0)return 0;
    int res=0;
    int i,j;
    for(i=0;i<grid.size();i++){
        for(j=0;j<grid[0].size();j++){
            if(grid[i][j]){
                res=max(dfs(grid,i,j),res);
            }
        }
    }
	return res;  
}

*/ 

int main(){
	return 0;
}
